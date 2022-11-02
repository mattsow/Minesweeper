#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>
#include "MinesweeperBoard.h"
#include "MSBoardTextView.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
using namespace std;
using namespace sf;

MSSFMLController::MSSFMLController(MinesweeperBoard &board, MSSFMLView &view):board(board), view(view){}
void MSSFMLController::play(){
    RenderWindow window(VideoMode(board.getBoardWidth()*board.fieldSize(), board.getBoardHeight()*board.fieldSize()), "Saper");
    window.setVerticalSyncEnabled(false);
    while(window.isOpen()){
        Event event;
        if(board.gameState()==RUNNING){
            window.setKeyRepeatEnabled(false);
            if(event.type == event.MouseButtonPressed){
                if(board.gameMode()==DEBUG_MODE){
                    board.debug_display();
                }
                if(event.mouseButton.button == Mouse::Left){
                    board.revealField(floor(event.mouseButton.x/board.fieldSize()), floor(event.mouseButton.y/board.fieldSize()));
                    this_thread::sleep_for(chrono::milliseconds(60));
                }
                if(event.mouseButton.button == Mouse::Right){
                    board.toggleFlag(floor(event.mouseButton.x/board.fieldSize()), floor(event.mouseButton.y/board.fieldSize()));
                    this_thread::sleep_for(chrono::milliseconds(120));
                }
            }
        }
        if(board.gameState()!=RUNNING){
            if(event.type == Event::MouseButtonPressed){
                if(event.mouseButton.button == Mouse::Right){
                    board.playAgain();
                    window.close();
                }
            }
        }
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }
        window.clear();
        view.draw(window);
        window.display();
    }
}
