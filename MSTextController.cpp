#include <iostream>
#include "MSTextController.h"
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
using namespace std;

MSTextController::MSTextController(MinesweeperBoard &board, MSBoardTextView &view):board(board), view(view){}
void MSTextController::play(){
    while(board.gameState()==RUNNING){
        char wybor;
        int row, col;
        view.display();
//        board.debug_display();
        cout<<"Odkryc pole(O) czy postawic flage(F)? ";
        cin>>wybor;
        wybor=toupper(wybor);
        cout<<"Na jakim polu(Rzad, Kolumna)? "<<endl;
        cout<<"Rzad: ";
        cin>>row;
        cout<<"Kolumna: ";
        cin>>col;
        switch(wybor){
            case 'O':
                if(board.hasFlag(row, col)){
                    cout<<"Nie mozna odkryc pola z flaga!"<<endl;
                }
                else{
                    board.revealField(row, col);
                }
                break;
            case 'F':
                board.toggleFlag(row, col);
                break;
            default:
                cout<<"Nieznane polecenie!";
                break;
        }
    }
    while(board.gameState()==FINISHED_WIN){
        view.display();
        cout<<"Wygrales!"<<endl;
        break;
    }
    while(board.gameState()==FINISHED_LOSS){
        view.display();
        cout<<"No i **** bombki strzelil!"<<endl;
        break;
    }
}
