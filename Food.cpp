#include "Food.h"
#include <time.h>
#include <stdlib.h>


Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    objPos foodPos;
    foodPos.setObjPos(4,4,'&');

    srand(time(NULL));
}

Food::~Food(){
    // nothing
}


void Food::generateFood(objPosArrayList blockOff){

    bool posNotFound = true;
    do {
        foodPos.setObjPos(rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1, rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1, '&');
        for (int i = 0; i < blockOff.getSize(); i++){
            objPos tempPos;
            blockOff.getElement(tempPos, i);
            if (!foodPos.isPosEqual(&tempPos))
                posNotFound = false;
        }
    } while (posNotFound);
}


void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}

// check if there is food at the head position
bool Food::checkForFood(objPos &head){

    if (foodPos.isPosEqual(&head)){
        return true;
    }
    return false;

}