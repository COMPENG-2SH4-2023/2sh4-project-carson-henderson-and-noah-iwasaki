#include "Food.h"
#include <time.h>
#include <stdlib.h>

srand(time(NULL));


Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodPos.setObjPos(4,4,'&');
}

Food::~Food() {}


void Food::generateFood(objPos blockOff)
{
    posNotFound = 1;
    do {
        foodPos.setObjPos(rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1, rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1, '&');
        if (!foodPos.isPosEqual(&blockOff))
            posNotFound = 0;
    } while (posNotFound)
}


void Food::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos);
}