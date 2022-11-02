#include <iostream>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
using namespace std;

int main(){
    MinesweeperBoard board(16, 16, EASY);
//    MSBoardTextView view(board);
//    MSTextController ctrl(board, view);
    MSSFMLView view(board);
    MSSFMLController ctrl(board, view);
    ctrl.play();
    if(board.playAgain()){
        main();
    }
};
