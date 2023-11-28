#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000 // 0.1s delay
#define ROWS 10
#define COLUMNS 20
#define border BORSYM

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{
    Initialize();

    while(exitFlag == false) {
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

    exitFlag = false;
}

void GetInput(void)
{

}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    for (int i = 0; i < COLUMNS; i++)
        cout << BORSYM;
    cout << endl;
    for (int i = 1; i < ROWS - 1; i++) {
        cout << BORSYM
        for (int j = 1; j < COLUMNS - 1; j++) {
            cout << ' ';
        }
        cout << BORSYM << endl;
    }
    for (int i = 0; i < COLUMNS; i++)
        cout << '#'
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
