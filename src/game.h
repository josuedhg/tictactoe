#ifndef __GAME_H__
#define __GAME_H__

#include <functional>

#include "player.h"
#include "board.h"
	
class Game {
	Player *p1;
	Player *p2;
	Board<char> *b;
public:
	Game(Player *p1, Player *p2, Board<char> *b);
	Player *start();
private:
	std::pair<int, int> getMove();
	void tryMove(Player *p, std::function<void(std::pair<int, int>, bool)> fail);
	bool isPlayerWinner(Player *p);
};

#endif
