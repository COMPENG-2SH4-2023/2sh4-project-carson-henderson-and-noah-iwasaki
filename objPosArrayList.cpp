#include "objPosArrayList.h"
#include "objPos.h"


// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{

    sizeArray = ARRAY_MAX_CAP;
    sizeList = 0;

    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    // check if arraylist is full
    if (sizeList == sizeArray){
        return;
    }

    // move everything back one, starting at the end
    for (int i = sizeList; i > 0; i--){
        aList[i].setObjPos(aList[i - 1]);
    }

    // insert a new element at the head
    aList[0].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    // check if arraylist is full
    if (sizeList == sizeArray){
        return;
    }

    // add the input to the end of the list
    aList[sizeList].setObjPos(thisPos);
    sizeList++;
}

void objPosArrayList::removeHead()
{
    // check if arraylist is full
    if (sizeList == sizeArray){
        return;
    }

    // move every element forward by 1
    for (int i = --sizeList; i > 0; i++){
        aList[i].setObjPos(aList[i+1]);
    }
}

void objPosArrayList::removeTail()
{
    // if list is not empty remove the tail
    if (sizeList > 0){
        sizeList--;
    }
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{
    // check if list is full
    returnPos.setObjPos(aList[0]);
}

void objPosArrayList::getTailElement(objPos &returnPos)
{
    returnPos.setObjPos(aList[sizeList - 1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{
    if (index >= sizeList){
        index = sizeList - 1;
    }
    returnPos.setObjPos(aList[index]);
}
