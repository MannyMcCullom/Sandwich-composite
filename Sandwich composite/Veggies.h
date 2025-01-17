#include <string>
using namespace std;
#pragma once
class Veggies
{
private:
	bool tomatoes;			// tomatoes to be added or not
	bool cucumbers;			// cucumbers to be added or not
	bool onions;			// onions to be added or not
	bool peppers;			// peppers to be added or not
	bool celery;			// celery to be added or not
	bool olives;			// olives to be added or not

public:
	void veggiesChoice(bool choice[6]);
	//determines which veggies will be used
	//Postcondition: Sets all the bool variables based on array

	string veggiesChoiceV2(int num, int Type);

	void showChoices(bool choice[6]) const;
	//changes an array according to veggies
	//post: modifies array to match all private variables

	Veggies();
	//Default constructor.
	//Postcondition: tomatoes = 0, cucumbers = 0, onions = 0, peppers = 0, celery = 0, olives = 0.
};

