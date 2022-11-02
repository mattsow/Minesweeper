#ifndef MSBoardTextView_h
#define MSBoardTextView_h
#include "MinesweeperBoard.h"

class MSBoardTextView{
    MinesweeperBoard &board;

public:
    MSBoardTextView(MinesweeperBoard &board);
    void display();
};

#endif
