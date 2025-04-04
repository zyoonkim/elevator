/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Person.cpp
 * Project UID 848fee0125dbb5eb53ed294f20dbef81
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "Person.h"
#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

Person::Person(string inputString) : Person()
{

    stringstream ss(inputString);
    char junk;
    ss >> turn;
    ss >> junk;
    ss >> currentFloor;
    ss >> junk;
    ss >> targetFloor;
    ss >> junk;
    ss >> angerLevel;
}

bool Person::tick(int currentTime)
{
    // TODO: Implement tick

    angerLevel++;
    if (angerLevel == MAX_ANGER)
    {
        return true;
    }

    // Returning false to prevent compilation error
    return false;
}

void Person::print(ostream &outs)
{
    // TODO: Implement print
    outs << 'f' << currentFloor << 't' << targetFloor << 'a' << angerLevel;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Person::Person()
{
    turn = 0;
    currentFloor = 0;
    targetFloor = 0;
    angerLevel = 0;
}

int Person::getTurn() const
{
    return turn;
}

int Person::getCurrentFloor() const
{
    return currentFloor;
}

int Person::getTargetFloor() const
{
    return targetFloor;
}

int Person::getAngerLevel() const
{
    return angerLevel;
}

ostream &operator<<(ostream &outs, Person p)
{
    p.print(outs);
    return outs;
}
