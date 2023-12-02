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
    
    objPos headPos = objPos();
    playerPosList.getHeadElement(&headPos);

    switch(myDir)
    {

        // movement cases
        case UP:
            headPos.setObjPos(headPos.x, headPos.y - 1, headPos.symbol);

            playerPos.y--;
            steps++;

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        case DOWN:
            headPos.setObjPos(headPos.x, headPos.y + 1, headPos.symbol);

            playerPos.y++;
            steps++;

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        case LEFT:
            headPos.setObjPos(headPos.x - 1, headPos.y, headPos.symbol);

            playerPos.x--;
            steps++;

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        case RIGHT:
            headPos.setObjPos(headPos.x + 1, headPos.y, headPos.symbol);

            playerPos.x++;
            steps++;

            playerPosList.insertHead(headPos);
            playerPosList.removeTail();

            break;

        // default state is not moving
        case NONE:
        default:
            break;

    }


}

