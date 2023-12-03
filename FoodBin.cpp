#include "FoodBin.h"

FoodBin::FoodBin(Player snake){ 

    //const int size = 5;

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


bool FoodBin::checkFoodCollision(Player snake){

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