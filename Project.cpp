#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#define DELAY_CONST 100000 // 0.1s delay
#define BOARDY 40
#define BOARDX 20

using namespace std;

GameMechs gameMechs{BOARDX, BOARDY};
Player snake {&gameMechs};
objPosArrayList snakeList;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
// ADDITONAL FUNCTIONS




int main(void)
{
    Initialize();

    while(gameMechs.getExitFlagStatus() == false) {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();


}

void GetInput(void)
{
    gameMechs.setInput('\0');
    if (MacUILib_hasChar())
        gameMechs.setInput(MacUILib_getChar()); // this line tosses the input into the input field of gameMechs
}

void RunLogic(void)
{

    if (gameMechs.getInput() != '\0') {
        snake.updatePlayerDir();
        gameMechs.setInput('\0'); //reset input
    }

    snake.movePlayer();

}

void DrawScreen(void)
{
    objPos playerPos{};
    MacUILib_clearScreen();





    // Print the board
    objPos tempPos;
    char border = gameMechs.getBorderSymbol();
    snake.getPlayerPos(snakeList);

    for (int i = 0; i < gameMechs.getBoardSizeX(); i++){
        for (int j = 0; j < gameMechs.getBoardSizeY(); j++){
            if (i == 0 || i == gameMechs.getBoardSizeX()-1 || j == 0 || j == gameMechs.getBoardSizeY()-1){
                cout << border;
            }
            else {
                objPos currPos{i, j, ' '};

                for (int n = 0; n < snakeList.getSize(); n++){
                    snakeList.getElement(tempPos, n);
                    if (currPos.isPosEqual(&tempPos)){
                        currPos.setObjPos(currPos.x, currPos.y, tempPos.getSymbol());
                    }
                }
                cout << currPos.getSymbol();
            }
        }
        cout << endl;
    }



}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST);
}


void CleanUp(void)
{
    MacUILib_clearScreen();
    MacUILib_uninit();
}

// ADDITIONAL FUNCTIONS
