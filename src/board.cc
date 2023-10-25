#include <algorithm>
#include <functional>

#include "board.h"

#define EMPTY_FIELD '\0'

Board::Board()
{
	std::for_each(this->board.begin(), this->board.end(), [](std::array<char, 3> &row) {
		std::fill(row.begin(), row.end(), EMPTY_FIELD);
	});
	this->m_winner = EMPTY_FIELD;
}

void Board::printBoard(std::function<void(char)> printFunc, std::function<void()> endLine)
{
	std::for_each(this->board.begin(), this->board.end(), [printFunc, endLine](std::array<char, 3> &row) {
		std::for_each(row.begin(), row.end(), [printFunc](char &c) {
			if ( c == EMPTY_FIELD)
				printFunc(' ');
			else
				printFunc(c);
		});
		endLine();
	});
}

void Board::setWinner()
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

bool Board::makeMove(int x, int y, char c)
{
	if (this->board[x][y] != EMPTY_FIELD) return false;
	this->board[x][y] = c;
	this->setWinner();
	return true;
}

bool Board::gameOver()
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

char Board::gameWinner()
{
	return this->m_winner;
}
	
