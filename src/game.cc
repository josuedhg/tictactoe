#include <iostream>

#include "game.h"

class CommandLineBoardRefresher : public BoardRefresher<char> {
	void refresh(std::pair<int, int> field, char change) override {
		std::cout << change << " ";
	}
	void rowEnd(int rowEnd) override {
		std::cout << std::endl << "- - -" << std::endl;
	}
};

CommandLineBoardRefresher refresher;

Game::Game(Player *p1, Player *p2, Board<char> *b): p1{p1}, p2{p2}, b{b} {}

void Game::tryMove(Player *p, std::function<void(std::pair<int, int>, bool)> tried)
{
	bool done = false;
	do {
		std::pair<int, int> move = this->getMove();
		done = this->b->makeMove(move.first, move.second, p->getMarker());
		tried(move, done);
	} while (!done);
	
}

std::pair<int, int> Game::getMove()
{
	int x, y;
	std::cout << "x:";
	std::cin >> x;
	std::cout << "y:";
	std::cin >> y;
	return std::make_pair(x, y);
}
bool Game::isPlayerWinner(Player *p)
{
	return p->getMarker() == b->gameWinner();
}

Player *Game::start()
{
	std::cout << "Starting Game" << std::endl;
	while (!b->gameWinner() && !b->gameOver()) {
		auto func = [this](std::pair<int, int> move, bool done) {
			if (!done)
				std::cout << "x = " << move.first << " and y = " << move.second << 
				" is not emtpy" << std::endl << "try again." << std::endl;
			this->b->refresh(&refresher);
			std::cout << "-----" << std::endl;
		};
		
		std::cout << p1->getPlayerName() << " turn" << std::endl;
		this->tryMove(p1, func);
		if (b->gameWinner() || b->gameOver()) break;

		std::cout << p2->getPlayerName() << " turn" << std::endl;
		this->tryMove(p2, func);
	}
	if (this->isPlayerWinner(p1)) return p1;
	if (this->isPlayerWinner(p2)) return p2;
	else return nullptr;
}

