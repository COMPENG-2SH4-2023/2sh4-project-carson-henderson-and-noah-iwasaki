#ifndef FOOD_H
#define FOOD_H

#include "objPosArrayList.h"
#include "GameMechs.h"

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;
    public:

        Food();
        Food(GameMechs* thisGMRef);
        ~Food();

        // make sure to use this after using the default constructor
        void updateGameMechs(GameMechs *thisGMRef);

        void generateFood(objPosArrayList blockOff);
        void getFoodPos(objPos &returnPos);
        bool checkForFood(objPos &head);
};

#endif