#ifndef MSSFMLController_h
#define MSSFMLController_h
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"

class MSSFMLController{
    MinesweeperBoard &board;
    MSSFMLView &view;

public:
    MSSFMLController(MinesweeperBoard &board, MSSFMLView &view);
    void play();
};

#endif
