#include <iostream>

#include "tictactoeboard.h"
#include "game.h"

int main(int argc, char **argv)
{
	TicTacToeBoard b{};
	Player p1("one", 'x');
	Player p2("two", 'o');
	Player *winner = nullptr;
	Game g(&p1, &p2, &b);

	winner = g.start();
	if (!winner)
		std::cout << "Game tied" << std::endl;
	else
		std::cout << "Winner is " << winner->getPlayerName() << std::endl;
}
