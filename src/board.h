#ifndef __BOARD_H__
#define __BOARD_H__

#include <array>
#include <functional>

class Board {
	std::array<std::array<char, 3>, 3> board;
	char m_winner;
public:
	Board();
	bool makeMove(int x, int y, char c);
	bool gameOver();
	char gameWinner();
	void printBoard(std::function<void(char)> printFunc,
			std::function<void()> endLine = []() {});
private:
	void setWinner();
};

#endif
