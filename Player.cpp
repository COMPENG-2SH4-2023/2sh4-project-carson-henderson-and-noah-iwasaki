#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    objPos startPos{mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, -2};
    objPosArrayList playerPos;

    playerPosList.insertHead(startPos);
}


Player::~Player()
{
    // delete any heap members here

    // no heap members?
}

void Player::getPlayerPos(objPosArrayList &returnPos)
{
    returnPos.wipe();
    objPos tempPos;

    // insert every element of 
    for (int i = 0; i < playerPosList.getSize(); i++){
        playerPosList.getElement(tempPos, i);
        returnPos.insertTail(tempPos);
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
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    
    objPos headPos;
    playerPosList.getHeadElement(headPos);

    switch(myDir)
    {

        // I have no clue why this works. This is completely backwards. 
        // Ive tried fixing it but it's not even worth trying. If it works it works?

        // movement cases
        case UP:
            headPos.setObjPos(headPos.x - 1, headPos.y, headPos.symbol);
            break;

        case DOWN:
            headPos.setObjPos(headPos.x + 1, headPos.y, headPos.symbol);
            break;

        case LEFT:
            headPos.setObjPos(headPos.x, headPos.y - 1, headPos.symbol);
            break;

        case RIGHT:
            headPos.setObjPos(headPos.x, headPos.y + 1, headPos.symbol);
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

// duplicate the tail of the snake
// the duplicate is removed when the snake moves, leaving one tail
void Player::foodEaten(){

    objPos tailPos;
    playerPosList.getTailElement(tailPos);
    playerPosList.insertTail(tailPos);

    mainGameMechsRef->incrementScore();

}

void Player::getHeadPos(objPos &returnPos){
    playerPosList.getHeadElement(returnPos);
}

void Player::checkSuicide(){

    // check if the head position overlaps any other body segment
    objPos headPos;
    playerPosList.getHeadElement(headPos);
    for (int i = 1; i < playerPosList.getSize(); i++){
        objPos tempPos;
        playerPosList.getElement(tempPos, i);
        if (headPos.isPosEqual(&tempPos)){
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
        }
    }

}