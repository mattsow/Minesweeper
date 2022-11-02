#include <iostream>
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
using namespace std;

MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):board(board){}

void MSBoardTextView::display(){
    for (int row=0; row<board.getBoardWidth(); row++){
        for (int col=0; col<board.getBoardHeight(); col++){
            cout<<"["<<board.getFieldInfo(row, col)<<"]";
        }
        cout<<endl;
    }
    cout<<endl;
}
