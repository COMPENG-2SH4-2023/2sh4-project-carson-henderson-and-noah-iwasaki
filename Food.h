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
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPosArrayList blockOff);
        void getFoodPos(objPos &returnPos);
        bool checkForFood(objPos &head);
};

#endif