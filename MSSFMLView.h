#ifndef MSSFMLView_h
#define MSSFMLView_h
#include "MinesweeperBoard.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class MSSFMLView{
    MinesweeperBoard &board;
    RectangleShape gameBackground ;
    Texture tileBackground, tile1, tile2, tile3, tile4, tile5, tile6, tile7, tile8, tileMine, tileEmpty, tileFlag;
    Sprite spriteBackground, sprite1, sprite2, sprite3, sprite4, sprite5, sprite6, sprite7, sprite8, spriteMine, spriteEmpty, spriteFlag;
    Texture face, face2, face3, face4;
    Sprite spriteFace, spriteFace2, spriteFace3, spriteFace4;
    Text gameLose, gameWin, tryAgain;
    Font font;

public:
    MSSFMLView(MinesweeperBoard &board);
    void draw (RenderWindow &window);
    
};

#endif
