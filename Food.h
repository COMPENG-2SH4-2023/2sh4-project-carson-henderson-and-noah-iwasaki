#ifndef FOOD_H
#define FOOD_H

class Food
{
    private:
        objPos foodPos;
        GameMechs* mainGameMechsRef;
    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPos blockOff);
        void getFoodPos(objPos &returnPos);
};

#endif