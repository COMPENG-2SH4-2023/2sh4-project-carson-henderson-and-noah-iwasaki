#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPosList = objPosArrayList();
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    returnPos = &playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic        
    input = mainGameMechsRef.getInput();

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
               mainGameMechsRef.exitFlag = 1;
                break;

            // direction processing
            case 'w':
                if(Dir != DOWN){
                    Dir = UP;
                }
                break;

            case 's':
                if(Dir != UP){
                    Dir = DOWN;
                }
                break;

            case 'a':
                if(Dir != RIGHT){
                    Dir = LEFT;
                }
                break;

            case 'd':
                if(Dir != LEFT){
                    Dir = RIGHT;
                }
                break;

            default:
                break;
        }
        input = 0;
    }




}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

