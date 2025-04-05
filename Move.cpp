/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 848fee0125dbb5eb53ed294f20dbef81
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include <cmath>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move()
{
    // stringstream ss(commandString);
    // char junk;
    // ss >> junk;
    // ss >> elevatorId;
    // ss >> junk;
    // ss >> junk;
    // ss >> targetFloor;
    // ss >> junk;
    // ss >> angerLevel;
}

bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const
{
    if (isPassMove() || isSaveMove() || isQuitMove())
    {
        return true;
    }
    return false;
}

void Move::setPeopleToPickup(const string &pickupList, const int currentFloor,
                             const Floor &pickupFloor)
{
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    int pickupListSize = pickupList.size();
    for (int i = 0; i < pickupListSize; i++)
    {
        int index = 0;
        index = static_cast<int>(pickupList[i]);
        peopleToPickup[i] = index;
        numPeopleToPickup++;
        totalSatisfaction += (MAX_ANGER - pickupFloor.getPersonByIndex(peopleToPickup[i]).getAngerLevel());
        int max = 0;
        for (int i = 0; i < numPeopleToPickup; i++)
        {
            if (peopleToPickup[i] > max)
            {
                max = peopleToPickup[i];
            }
        }
        targetFloor = max;
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move()
{
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const
{
    return isPickup;
}

bool Move::isPassMove() const
{
    return isPass;
}

bool Move::isSaveMove() const
{
    return isSave;
}

bool Move::isQuitMove() const
{
    return isQuit;
}

int Move::getElevatorId() const
{
    return elevatorId;
}

int Move::getTargetFloor() const
{
    return targetFloor;
}

int Move::getNumPeopleToPickup() const
{
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const
{
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor)
{
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const
{
    for (int i = 0; i < numPeopleToPickup; ++i)
    {
        newList[i] = peopleToPickup[i];
    }
}
