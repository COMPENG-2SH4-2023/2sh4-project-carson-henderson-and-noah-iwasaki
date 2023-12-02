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

    // no heap members?
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos array list
    playerPosList.getHeadElement(returnPos);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic        
    int input = mainGameMechsRef->getInput();

    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;

            // direction processing
            case 'w':
                if(myDir != DOWN){
                    myDir = UP;
                }
                break;

            case 's':
                if(myDir != UP){
                    myDir = DOWN;
                }
                break;

            case 'a':
                if(myDir != RIGHT){
                    myDir = LEFT;
                }
                break;

            case 'd':
                if(myDir != LEFT){
                    myDir = RIGHT;
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
    
    objPos headPos;
    playerPosList.getHeadElement(headPos);

    switch(myDir)
    {

        // movement cases
        case UP:
            headPos.setObjPos(headPos.x, headPos.y - 1, headPos.symbol);

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        case DOWN:
            headPos.setObjPos(headPos.x, headPos.y + 1, headPos.symbol);

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        case LEFT:
            headPos.setObjPos(headPos.x - 1, headPos.y, headPos.symbol);

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        case RIGHT:
            headPos.setObjPos(headPos.x + 1, headPos.y, headPos.symbol);

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        // default state is not moving
        case STOP:
        default:
            break;

    }

    const int WIDTH = mainGameMechsRef->getBoardSizeX();
    const int HEIGHT = mainGameMechsRef->getBoardSizeY();
    // wrap around logic from ppa3
    // horizontal wrap around
    if(headPos.x < 1){
        headPos.setObjPos(WIDTH - 2, headPos.y, headPos.symbol);
    }
    else if(headPos.x > WIDTH - 2) {
        headPos.setObjPos(1, headPos.y, headPos.symbol);
    }

    // vertical wrap around
    else if(headPos.y < 1){
        headPos.setObjPos(headPos.x, HEIGHT - 2, headPos.symbol);
    }
    else if(headPos.y > HEIGHT - 2){
        headPos.setObjPos(headPos.x, 1, headPos.symbol);
    }



}

