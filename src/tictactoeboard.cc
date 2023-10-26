#include <algorithm>

#include "tictactoeboard.h"

#define EMPTY_FIELD '\0'

TicTacToeBoard::TicTacToeBoard() : TicTacToeBoard({std::array<char, 3>({EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD}),
						   std::array<char, 3>({EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD}),
						   std::array<char, 3>({EMPTY_FIELD, EMPTY_FIELD, EMPTY_FIELD})}) {}

TicTacToeBoard::TicTacToeBoard(std::array<std::array<char, 3>, 3> initializer)
{
	this->board = std::move(initializer);
	this->m_winner = EMPTY_FIELD;
}

bool TicTacToeBoard::makeMove(int x, int y, char c)
{
	if (this->board[x][y] != EMPTY_FIELD) return false;
	this->board[x][y] = c;
	this->setWinner();
	return true;
}

bool TicTacToeBoard::gameOver()
{
	bool over = true;
	std::for_each(this->board.begin(), this->board.end(), [&over](std::array<char, 3> &row) {
		std::for_each(row.begin(), row.end(), [&over](char &c) {
			if (c == EMPTY_FIELD)
				over = false;
		});
	});
	return over || this->gameWinner() != EMPTY_FIELD;
}

char TicTacToeBoard::gameWinner()
{
	return this->m_winner;
}

void TicTacToeBoard::setWinner()
{
	char winner = EMPTY_FIELD;
	for (int i = 0; i < 3; i++) {
		if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2]) {
			winner = this->board[i][0];
			break;
		}
		if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i]) {
			winner = this->board[0][i];
			break;
		}
	}
	if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2]) {
		winner = this->board[0][0];
	}
	if (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0]) {
		winner = this->board[0][2];
	}
	this->m_winner = winner;
}

void TicTacToeBoard::refresh(BoardRefresher<char> *refresher)
{
	for (size_t i = 0; i < this->board.size(); i++) {
		auto row = this->board[i];
		for (size_t j = 0; j < row.size(); j++) {
			if ( row[j] == EMPTY_FIELD)
				refresher->refresh(std::make_pair(j, i), ' ');
			else
				refresher->refresh(std::make_pair(j, i), row[j]);
		}
		refresher->rowEnd(i);
	}
}

