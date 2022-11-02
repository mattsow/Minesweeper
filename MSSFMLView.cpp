#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include "MinesweeperBoard.h"
using namespace std;
using namespace sf;

MSSFMLView::MSSFMLView(MinesweeperBoard &board) : board(board){
    string filePath="/Users/matt/Documents/ProgramowanieObiektowe/Minesweeper/Minesweeper/tiles.png";
    tileBackground.loadFromFile( filePath, IntRect(0, 0, 32, 32));
    spriteBackground.setTexture(tileBackground);
    spriteBackground.setScale(board.fieldSize()/32.f, board.fieldSize()/32.f);
    tile1.loadFromFile(filePath, IntRect(32, 0, 32, 32));
    sprite1.setTexture(tile1);
    sprite1.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tile2.loadFromFile(filePath, IntRect(64, 0, 32, 32));
    sprite2.setTexture(tile2);
    sprite2.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tile3.loadFromFile(filePath, IntRect(96, 0, 32, 32));
    sprite3.setTexture(tile3);
    sprite3.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tile4.loadFromFile(filePath, IntRect(128, 0, 32, 32));
    sprite4.setTexture(tile4);
    sprite4.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tile5.loadFromFile(filePath, IntRect(160, 0, 32, 32));
    sprite5.setTexture(tile5);
    sprite5.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tile6.loadFromFile(filePath, IntRect(192, 0, 32, 32));
    sprite6.setTexture(tile6);
    sprite6.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tile7.loadFromFile(filePath, IntRect(224, 0, 32, 32));
    sprite7.setTexture(tile7);
    sprite7.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tile8.loadFromFile(filePath, IntRect(256, 0, 32, 32));
    sprite8.setTexture(tile8);
    sprite8.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tileMine.loadFromFile(filePath, IntRect(288, 0, 32, 32));
    spriteMine.setTexture(tileMine);
    spriteMine.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tileEmpty.loadFromFile(filePath, IntRect(320, 0, 32, 32));
    spriteEmpty.setTexture(tileEmpty);
    spriteEmpty.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    tileFlag.loadFromFile(filePath, IntRect(352, 0, 32, 32));
    spriteFlag.setTexture(tileFlag);
    spriteFlag.setScale(Vector2f(board.fieldSize()/32.f, board.fieldSize()/32.f));
    font.loadFromFile("/Users/matt/Documents/ProgramowanieObiektowe/Minesweeper/Minesweeper/Arial.ttf");
    gameLose.setFont(font);
    gameWin.setFont(font);
    tryAgain.setFont(font);
}

void MSSFMLView::draw(RenderWindow &win){
    gameBackground=RectangleShape(Vector2f(board.sizeWidth(), board.sizeHeight()));
    gameBackground.setFillColor(Color(0, 0, 0, 64));
    gameBackground.setPosition(0, 0);
    gameLose.setString("GAME OVER");
    gameLose.setCharacterSize(board.fieldSize()*(board.getBoardWidth())*0.1);
    gameLose.setFillColor(Color::Black);
    gameLose.setOutlineThickness(board.getBoardWidth()*0.45);
    gameLose.setOutlineColor(Color::White);
    gameLose.setOrigin(gameLose.getGlobalBounds().width*0.5, gameLose.getGlobalBounds().height*0.5);
    gameLose.setPosition(board.sizeWidth()*0.5,(board.sizeHeight()*0.45));
    gameWin.setString("YOU WIN!");
    gameWin.setCharacterSize(board.fieldSize()*(board.getBoardWidth())*0.1);
    gameWin.setFillColor(Color::Black);
    gameWin.setOutlineThickness(board.getBoardWidth()*0.45);
    gameWin.setOutlineColor(Color::White);
    gameWin.setOrigin(gameWin.getGlobalBounds().width*0.5, gameWin.getGlobalBounds().height*0.5);
    gameWin.setPosition((board.sizeWidth()*0.5),(board.sizeHeight()*0.45));
    tryAgain.setString("TRY AGAIN? PRESS RIGHT MOUSE BUTTON");
    tryAgain.setCharacterSize(board.fieldSize()*(board.getBoardWidth())*0.04);
    tryAgain.setFillColor(Color::Black);
    tryAgain.setOutlineThickness(board.getBoardWidth()*0.2);
    tryAgain.setOutlineColor(Color::White);
    tryAgain.setOrigin(tryAgain.getGlobalBounds().width*0.5, tryAgain.getGlobalBounds().height*0.5);
    tryAgain.setPosition(board.sizeWidth()*0.5,(board.sizeHeight()*0.55));

    for(int col=0; col<board.getBoardHeight(); col++){
        for(int row=0; row<board.getBoardWidth(); row++){
            int x=board.fieldSize()*row;
            int y=board.fieldSize()*col;
            spriteBackground.setPosition(x, y);
            sprite1.setPosition(x, y);
            sprite2.setPosition(x, y);
            sprite3.setPosition(x, y);
            sprite4.setPosition(x, y);
            sprite5.setPosition(x, y);
            sprite6.setPosition(x, y);
            sprite7.setPosition(x, y);
            sprite8.setPosition(x, y);
            spriteMine.setPosition(x, y);
            spriteEmpty.setPosition(x, y);
            spriteFlag.setPosition(x, y);
            if(board.getFieldInfo(row, col) == '_')win.draw(spriteEmpty);
            if(board.getFieldInfo(row, col) == ' ')win.draw(spriteBackground);
            if(board.getFieldInfo(row, col) == 'X')win.draw(spriteMine);
            if(board.getFieldInfo(row, col) == 'F')win.draw(spriteFlag);
            if(board.getFieldInfo(row, col) == '1')win.draw(sprite1);
            if(board.getFieldInfo(row, col) == '2')win.draw(sprite2);
            if(board.getFieldInfo(row, col) == '3')win.draw(sprite3);
            if(board.getFieldInfo(row, col) == '4')win.draw(sprite4);
            if(board.getFieldInfo(row, col) == '5')win.draw(sprite5);
            if(board.getFieldInfo(row, col) == '6')win.draw(sprite6);
            if(board.getFieldInfo(row, col) == '7')win.draw(sprite7);
            if(board.getFieldInfo(row, col) == '8')win.draw(sprite8);
        }
    }
    if(board.gameState()!=RUNNING){
        if(board.gameState()==FINISHED_WIN){
            gameBackground.setFillColor(Color(0, 255, 0, 100));
            win.draw(gameBackground);
            win.draw(gameWin);
            win.draw(tryAgain);
        }
        if(board.gameState()==FINISHED_LOSS){
            gameBackground.setFillColor(Color(255, 0, 0, 100));
            win.draw(gameBackground);
            win.draw(gameLose);
            win.draw(tryAgain);
        }
    }
}
