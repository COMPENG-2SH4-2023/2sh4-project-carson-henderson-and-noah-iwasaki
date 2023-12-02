#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    objPos startPos{mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*'};
    objPosArrayList playerPos;

    objPos temp1{mainGameMechsRef->getBoardSizeX() / 2 + 1, mainGameMechsRef->getBoardSizeY() / 2, '*'};
    playerPosList.insertTail(temp1);

    temp1.setObjPos(mainGameMechsRef->getBoardSizeX() / 2 + 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList.insertTail(temp1);

    playerPosList.insertHead(startPos);
}


Player::~Player()
{
    // delete any heap members here

    // no heap members?
}

void Player::getPlayerPos(objPosArrayList &returnPos)
{
    // return the reference to the playerPos array list
    for (int i = 0; i < playerPos.getSize(); i++){
        returnPos.insertTail(playerPosList.getElement(i));
    }
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
            break;

        case DOWN:
            headPos.setObjPos(headPos.x, headPos.y + 1, headPos.symbol);
            break;

        case LEFT:
            headPos.setObjPos(headPos.x - 1, headPos.y, headPos.symbol);
            break;

        case RIGHT:
            headPos.setObjPos(headPos.x + 1, headPos.y, headPos.symbol);
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

    playerPosList.insertHead(headPos);
    playerPosList.removeTail();


}

