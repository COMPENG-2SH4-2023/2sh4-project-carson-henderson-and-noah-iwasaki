#ifndef FOODBIN_H
#define FOODBIN_H

#include "Food.h"
#include "Player.h"

class FoodBin
{

    private:

        Food *foodList;
        int size; // this is probably bad syntax but id rather have size be a consts

    public:

        FoodBin(Player &snake);
        ~FoodBin();

        int getSize();

        bool checkFoodCollision(Player &snake);
        bool isFoodAt(objPos &foodPos);

        // debugger functions
        int getFoodX(int i);
        int getFoodY(int i);

};

#endif