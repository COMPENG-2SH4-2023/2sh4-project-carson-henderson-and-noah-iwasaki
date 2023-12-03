#include "FoodBin.h"
#include <iostream>

FoodBin::FoodBin(Player &snake){ 

    int size = 5;

    Food *foodList = new Food[size];

    for (int i = 0; i < size; i++){
        foodList[i].updateGameMechs(snake.getGameMechs());

        // store the snakes body so random elements are not generated over it
        objPosArrayList blockOff;
        snake.getPlayerPos(blockOff);
        foodList[i].generateFood(blockOff);
    }
}


FoodBin::~FoodBin(){
    delete[] foodList;
}


int FoodBin::getSize(){
    return size;
}


bool FoodBin::checkFoodCollision(Player &snake){

    objPos temp;
    snake.getHeadPos(temp);

    for (int i = 0; i < size; i++){

        if (foodList[i].checkForFood(temp)){

            // store every element from the snakes body
            objPosArrayList snakeBody;
            snake.getPlayerPos(snakeBody);

            // generate another food
            foodList[i].generateFood(snakeBody);


            return true;
        }
    }
    return false;
}


// this function is used by the draw logic to check if there is food at a given position.
bool FoodBin::isFoodAt(objPos &foodPos){

    for (int i = 0; i < size; i++){

        // check if ith item is at the position checked
        if (foodList[i].checkForFood(foodPos)){
            return true;
        }
    }
    return false;
}


int FoodBin::getFoodX(int i){
    objPos temp;
    foodList[i].getFoodPos(temp);
    return temp.x;
}


int FoodBin::getFoodY(int i){
    objPos temp;
    foodList[i].getFoodPos(temp);
    return temp.y;
}