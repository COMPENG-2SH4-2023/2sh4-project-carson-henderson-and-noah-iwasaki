#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include "FoodBin.h"
#define DELAY_CONST 100000 // 0.1s delay
#define BOARDY 40
#define BOARDX 20

using namespace std;

GameMechs gameMechs{BOARDX, BOARDY};
Player snake {&gameMechs};
objPosArrayList snakeList;

FoodBin apples{snake};
Food apple;

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

    snake.getPlayerPos(snakeList);

}

void GetInput(void)
{
    gameMechs.setInput('\0');
    if (MacUILib_hasChar())
        gameMechs.setInput(MacUILib_getChar()); // this line tosses the input into the input field of gameMechs
}

void RunLogic(void)
{

    // control the snake direction
    if (gameMechs.getInput() != '\0') {
        snake.updatePlayerDir();
        gameMechs.setInput('\0'); //reset input
    }

    // move the snake
    snake.movePlayer();

    //check if you died
    snake.checkSuicide();  

    // check for a food collision
    // this method also handles the generation of new food
    apples.checkFoodCollision(snake);

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
                        break;
                    }
                    else if (apples.isFoodAt(currPos)){
                        break;
                    }
                }
                cout << currPos.getSymbol();
            }
        }
        cout << endl;
    }

    cout << "Your score is: " << gameMechs.getScore() << endl;

    //gameMechs.setExitTrue();

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST);
}


void CleanUp(void)
{
    if (gameMechs.getLoseFlagStatus())
        cout << "YOU DIED WITH A SCORE OF " << gameMechs.getScore();
    else
        cout << "YOU QUIT WITH A SCORE OF " << gameMechs.getScore();
    MacUILib_uninit();
}

// ADDITIONAL FUNCTIONS
