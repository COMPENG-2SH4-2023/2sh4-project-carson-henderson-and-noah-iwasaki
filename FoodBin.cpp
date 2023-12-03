#include "FoodBin.h"

FoodBin::FoodBin(gameMechs* thisGMRef){ 

    foodList = new food[5];

    for (int i = 0; i < 5; i++){
        foodList[i]{thisGMRef};
    }

}

FoodBin::~FoodBin(){
    delete[] foodList;
}