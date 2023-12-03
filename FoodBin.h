#ifndef FOODBIN_H
#define FOODBIN_H

#include "Food.h"
#include "Player.h"

class FoodBin
{

    private:

        Food *foodList;
        const int size = 5;

    public:

        FoodBin(Player snake);
        ~FoodBin();

        bool checkFoodCollision(Player snake);

};




#endif