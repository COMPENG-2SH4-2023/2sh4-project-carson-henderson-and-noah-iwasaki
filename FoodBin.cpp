#include "FoodBin.h"
#include <iostream>

FoodBin::FoodBin(Player &snake){ 

    size = 5;
    foodList = new Food[size];

    // just copy the snakes game mechanics reference
    mainGameMechsRef = snake.getGameMechs();

    // store which entries the snake is using so food doesnt generate on top of them
    objPosArrayList blockedList;
    snake.getPlayerPos(blockedList);

    // finish building every food item
    for (int i = 0; i < size; i++){

        foodList[i].updateGameMechs(mainGameMechsRef);

        foodList[i].generateFood(blockedList);

        // add the new position to the blocked list
        objPos temp;
        foodList[i].getFoodPos(temp);
        blockedList.insertTail(temp); 
        // For whatever stupid reason, adding to head causes a segmentation fault
        // I have no idea why, screw this code.
    }
}


FoodBin::~FoodBin(){
    delete[] foodList;
}


int FoodBin::getSize(){
    return size;
}


bool FoodBin::checkFoodCollision(Player &snake){

    objPos headPos;
    snake.getHeadPos(headPos);

    for (int i = 0; i < size; i++){

        if (foodList[i].checkForFood(headPos)){

            // store every element from the snakes body
            objPosArrayList blockedList;
            snake.getPlayerPos(blockedList);

            objPos temp;

            // add every food item to the blocked list
            for (int j = 0; j < 5; j++){
                foodList[j].getFoodPos(temp);
                blockedList.insertHead(temp);
            }

            // generate another food
            foodList[i].generateFood(blockedList);

            snake.foodEaten();

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