#ifndef __TICTACTOEBOARD_H__
#define __TICTACTOEBOARD_H__

#include <array>

#include "board.h"

class TicTacToeBoard : public Board<char> {
	std::array<std::array<char, 3>, 3> board;
	char m_winner;
public:
	TicTacToeBoard();
	TicTacToeBoard(std::array<std::array<char, 3>, 3> initializer);

	bool makeMove(int x, int y, char c) override;
	bool gameOver() override;
	char gameWinner() override;
	void refresh(BoardRefresher<char> *refresher) override;
private:
	void setWinner();
};

#endif
