#include "Food.h"
#include <time.h>
#include <stdlib.h>

#include <iostream>

Food::Food()
{
    // empty constructor. This is here so an array of food objects can be declared.
    // Don't use this constructor otherwise.

    objPos foodPos;
    foodPos.setObjPos(4,4,'&');

    srand(time(NULL));
}

// horrible syntax, but C++ doesnt give me another way to do this.
void Food::updateGameMechs(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
}

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

    // generate the foods symbol
    // a - normal food, 1 point
    // @ - super food, 5 points
    char symbol = 'a';
    int randomNum = rand() % 10;
    if (randomNum == 0){
        symbol = '@';
    }



    // run this loop while the generated element is not in blockList
    bool unique;
    do{
        // fun fact: if you dont set unique to true here, it doesnt work!
        // its 3 am and i have spent the last 2 hours debugging thi
        unique = true;

        // generate a random position
        foodPos.setObjPos(rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1, rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1, symbol);

        // check if this position is in blockList
        for (int i = 0; i < blockOff.getSize(); i++){

            objPos temp;
            blockOff.getElement(temp, i);

            if (temp.isPosEqual(&foodPos)){
                unique = false;
                break;
            }
        }
    }
    while (unique == false);
    
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