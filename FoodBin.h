#ifndef FOODBIN_H
#define FOODBIN_H

#include "Food.h"

class FoodBin
{

    private:

        Food *foodList;

    public:

        FoodBin(GameMechs* thisGMRef);
        ~FoodBin();

        void checkFoodCollision(objPos &head);

};




#endif