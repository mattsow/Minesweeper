#include <iostream>
#include <cmath>
#include "MinesweeperBoard.h"
using namespace std;

MinesweeperBoard::MinesweeperBoard(int width, int height, GameMode mode){
    this->width=width;
    this->height=height;
    this->mode=mode;
    this->actionCount=0;
    this->play=true;
    for (int row=0; row<width; row++){
        for (int col=0; col<height; col++){
            board[row][col].hasMine=false;
            board[row][col].isRevealed=false;
            board[row][col].hasFlag=false;
        }
    }
    srand((unsigned)time(0));
    if(mode==DEBUG_MODE){
        for (int row=0; row<width; row++){
            for (int col=0; col<height; col++){
                if(row==col || row==0 || (col==0 && row%2==0)){
                    board[row][col].hasMine=true;
                }
            }
        }
    }
    else{
        for (int mines=0; getMineCount()<(round((height*width)*setDifficultyLevel())); mines++){
            generateMine();
        }
    }
}

int MinesweeperBoard::getBoardWidth() const{
    return width;
}

int MinesweeperBoard::getBoardHeight() const{
    return height;
}

int MinesweeperBoard::sizeWidth() const{
    return width*fieldSize();
}

int MinesweeperBoard::sizeHeight() const{
    return height*fieldSize();
}

int MinesweeperBoard::getMineCount() const{
    int mines_count=0;
    for (int row=0; row<width; row++){
        for (int col=0; col<height; col++){
            if(board[row][col].hasMine){
                mines_count++;
            }
        }
    }
    return mines_count;
}

int MinesweeperBoard::getMinesLeft() const{
    int mines_left=getMineCount();
    for (int row=0; row<width; row++){
        for (int col=0; col<height; col++){
            if(board[row][col].hasFlag && board[row][col].hasMine){
                mines_left--;
            }
        }
    }
    return  mines_left;
}

int MinesweeperBoard::getFieldsLeft() const{
    int fieldsLeft=width*height-getMineCount();
    for (int row=0; row<width; row++){
        for (int col=0; col<height; col++){
            if(!board[row][col].hasMine && board[row][col].isRevealed){
                fieldsLeft--;
            }
            if(board[row][col].hasMine && board[row][col].isRevealed){
                fieldsLeft++;
            }
        }
    }
    return fieldsLeft;
}

int MinesweeperBoard::countMines(int row, int col) const{
    int mines=0;
    if(row<width && col<height){
        for (int x=(row-1); x<=(row+1); x++){
            for (int y=(col-1); y<=(col+1); y++){
                if((x>=0 && y>=0) && (x<width && y<height) && board[x][y].hasMine){
                    mines++;
                }
            }
        }
        if(board[row][col].hasMine){
            mines--;
        }
    }
    else{
        mines=-1;
    }
    return mines;
}

float MinesweeperBoard::setDifficultyLevel() const{
    if(mode==EASY){
        return (0.1);
    }
    if(mode==NORMAL){
        return (0.2);
    }
    if(mode==HARD){
        return (0.3);
    }
    return 0;
}

bool MinesweeperBoard::isRevealed(int row, int col) const{
    if(board[row][col].isRevealed){
        return true;
    }
    else{
        return false;
    }
}

void MinesweeperBoard::revealField(int row, int col){
    if(!board[row][col].hasFlag){
        actionCount++;
        if(board[row][col].hasMine){
            if(actionCount==1 && mode!=DEBUG_MODE){
                moveMine(row, col);
            }
            else{
                for(int x=0; x<=width; x++){
                    for(int y=0; y<=height; y++){
                        board[x][y].isRevealed=true;
                    }
                }
            }
        }
        if(countMines(row, col)==0){
            for (int x=(row-1); x<=(row+1); x++){
                for (int y=(col-1); y<=(col+1); y++){
                    if((x>=0 && y>=0) && (!board[x][y].hasMine && !board[x][y].isRevealed)){
                        board[x][y].isRevealed=true;
                        revealField(x, y);
                    }
                }
            }
        }
        else if(countMines(row, col)>0){
            board[row][col].isRevealed=true;
        }
    }
    else{
        return;
    }
}

int MinesweeperBoard::fieldSize() const{
    int size=64;
    return size;
}

bool MinesweeperBoard::hasFlag(int row, int col) const{
    if(board[row][col].hasFlag){
        return true;
    }
    else{
        return false;
    }
}

void MinesweeperBoard::toggleFlag(int row, int col){
    if(!board[row][col].isRevealed){
        if(!board[row][col].hasFlag){
            board[row][col].hasFlag=true;
        }
        else{
            board[row][col].isRevealed=false;
            board[row][col].hasFlag=false;
        }
    }
    else{
        return;
    }
}

bool MinesweeperBoard::hasMine(int row, int col) const{
    if(board[row][col].hasMine){
        return true;
    }
    else{
        return false;
    }
}

void MinesweeperBoard::generateMine(){
    bool emptyField=false;
    do {
        int row=rand() % width;
        int col=rand() % height;
        if(board[row][col].hasMine==false){
            board[row][col].hasMine=true;
            emptyField=true;
        }
    }
    while(!emptyField);
}

void MinesweeperBoard::moveMine(int row, int col){
    generateMine();
    board[row][col].hasMine=false;
}

GameState MinesweeperBoard::gameState() const{
    for (int row=0; row<width; row++){
        for (int col=0; col<height; col++){
            if(board[row][col].isRevealed && board[row][col].hasMine){
                return FINISHED_LOSS;
            }
            if(getMinesLeft()>=0 && getFieldsLeft()==0){
                return FINISHED_WIN;
            }
        }
    }

    return RUNNING;
}

GameMode MinesweeperBoard::gameMode() const{
    if(mode==EASY){
        return EASY;
    }
    if(mode==NORMAL){
        return NORMAL;
    }
    if(mode==HARD){
        return HARD;
    }
    return DEBUG_MODE;
}

bool MinesweeperBoard::playAgain(){
    if(play){
        play=false;
    }
    else{
        play=true;
    }
    return play;
}

char MinesweeperBoard::getFieldInfo(int row, int col) const{
    if(row<=width && col<=height){
        if(board[row][col].isRevealed){
            if(board[row][col].hasMine){
                return 'X';
            }
            else if(!board[row][col].hasMine){
                if(countMines(row, col)==0){
                    return ' ';
                }
                if(countMines(row, col)!=0){
                    return countMines(row, col)+48;
                }
            }
        }
        else if(!board[row][col].isRevealed){
            if(board[row][col].hasFlag){
                return 'F';
            }
            else if(!board[row][col].hasFlag){
                return '_';
            }
        }
    }
    return '#';
}

void MinesweeperBoard::debug_display() const{
    for (int row=0; row<width; row++){
        cout<<"    "<<row;
    }
    cout<<endl;
    for (int col=0; col<height; col++){
        cout<<col<<" ";
        for (int row=0; row<width; row++){
            string M,R,F;
            if(board[row][col].hasMine){
                M="M";
            }
            else{
                M=".";
            }
            if(board[row][col].isRevealed){
                R="O";
            }
            else{
                R=".";
            }
            if(board[row][col].hasFlag){
                F="F";
            }
            else{
                F=".";
            }
            cout<<"["<<M<<R<<F<<"]";
        }
        cout<<endl;
    }
}
