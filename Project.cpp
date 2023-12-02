#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#define DELAY_CONST 100000 // 0.1s delay
#define BOARDY 20
#define BOARDX 40
#define ESC 27

using namespace std;

GameMechs gameMechs = GameMechs(BOARDX, BOARDY);
Player snake = Player(gameMechs);

objPos currPos = objPos();
objPos debug = objPos(3, 5, '@');


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);
// ADDITONAL FUNCTIONS
char symAtPos(int, int);



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
        switch (gameMechs.getInput()) {
        case ESC:
            gameMechs.setExitTrue();
            break;
        }
        gameMechs.setInput('\0');
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    // Print top line
    for (int i = 0; i < gameMechs.getBoardSizeX(); i++)
        cout << gameMechs.getBorderSymbol();
    cout << endl;




    // Print everything in between
    
    for (int i = 1; i < gameMechs.getBoardSizeY() - 1; i++) {
        cout << gameMechs.getBorderSymbol();
        for (int j = 1; j < gameMechs.getBoardSizeX() - 1; j++) {
            currPos.setObjPos(j, i, 0);
        }
        cout << gameMechs.getBorderSymbol() << endl;
    }
    



    // Print bottom line
    for (int i = 0; i < gameMechs.getBoardSizeX(); i++)
        cout << gameMechs.getBorderSymbol();
    cout << endl;


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

char symAtPos(int x, int y)
{}