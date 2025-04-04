/*
 * Copyright 2023 University of Michigan EECS183
 *
 * Floor.cpp
 * Project UID 848fee0125dbb5eb53ed294f20dbef81
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "Floor.h"

using namespace std;

int Floor::tick(int currentTime)
{
	// TODO: implement
	return 0;
}

void Floor::addPerson(Person newPerson, int request)
{
	// TODO: Implement addPerson
	if (numPeople < MAX_PEOPLE_PER_FLOOR)
	{
		people[numPeople] = newPerson;
		if (request > newPerson.getCurrentFloor())
		{
			hasUpRequest = true;
		}
		else if (request < newPerson.getCurrentFloor())
		{
			hasDownRequest = true;
		}
	}
}

void Floor::removePeople(const int indicesToRemove[MAX_PEOPLE_PER_FLOOR],
						 int numPeopleToRemove)
{
	for (int i = 0; i < numPeopleToRemove; i++)
	{
		for (int j = indicesToRemove[i]; j < numPeople; j++)
		{
			people[j] = people[j + 1];
		}
		numPeople--;
	}
	// TODO: Implement removePeople
}

void Floor::resetRequests()
{
	for (int i = 0; i < numPeople; i++)
	{
		if (people[i].getCurrentFloor() < people[i].getTargetFloor())
		{
			hasUpRequest = true;
		}
		else if (people[i].getCurrentFloor() > people[i].getTargetFloor())
		{
			hasDownRequest = true;
		}
	}
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor()
{
	hasDownRequest = false;
	hasUpRequest = false;
	numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream &outs) const
{
	string up = "U";
	outs << (hasUpRequest ? up : " ") << " ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << people[i].getAngerLevel();
		outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
	}
	outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream &outs) const
{
	string down = "D";
	outs << (hasDownRequest ? down : " ") << " ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << "o   ";
	}
	outs << endl;
}

void Floor::printFloorPickupMenu(ostream &outs) const
{
	cout << endl;
	outs << "Select People to Load by Index" << endl;
	outs << "All people must be going in same direction!";
	/*  O   O
	// -|- -|-
	//  |   |
	// / \ / \  */
	outs << endl
		 << "              ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << " O   ";
	}
	outs << endl
		 << "              ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << "-|-  ";
	}
	outs << endl
		 << "              ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << " |   ";
	}
	outs << endl
		 << "              ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << "/ \\  ";
	}
	outs << endl
		 << "INDEX:        ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << " " << i << "   ";
	}
	outs << endl
		 << "ANGER:        ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << " " << people[i].getAngerLevel() << "   ";
	}
	outs << endl
		 << "TARGET FLOOR: ";
	for (int i = 0; i < numPeople; ++i)
	{
		outs << " " << people[i].getTargetFloor() << "   ";
	}
}

void Floor::setHasUpRequest(bool hasRequest)
{
	hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const
{
	return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest)
{
	hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const
{
	return hasDownRequest;
}

int Floor::getNumPeople() const
{
	return numPeople;
}

Person Floor::getPersonByIndex(int index) const
{
	return people[index];
}
