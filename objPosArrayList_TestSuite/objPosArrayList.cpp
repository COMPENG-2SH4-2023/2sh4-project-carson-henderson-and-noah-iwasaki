#include "objPosArrayList.h"


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
    delete aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{

    // check if array is full
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
    // check if array is full
    if (sizeList == sizeArray){
        return;
    }

    // add the input to the end of the list
    aList[sizeList] = thisPos;
    sizeList++;
}

void objPosArrayList::removeHead()
{
    
}

void objPosArrayList::removeTail()
{

}

void objPosArrayList::getHeadElement(objPos &returnPos)
{

}

void objPosArrayList::getTailElement(objPos &returnPos)
{

}

void objPosArrayList::getElement(objPos &returnPos, int index)
{

}