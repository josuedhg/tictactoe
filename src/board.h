#ifndef __BOARD_H__
#define __BOARD_H__

#include <functional>

template<class T>
class BoardRefresher {
public:
	virtual void refresh(std::pair<int, int> field, T change) = 0;
	virtual void rowEnd(int rowEnd) = 0;
};

template<class T>
class Board {
public:
	virtual bool makeMove(int x, int y, T c) = 0;
	virtual bool gameOver() = 0;
	virtual T gameWinner() = 0;
	virtual void refresh(BoardRefresher<T> *refresher) = 0;
};

#endif
