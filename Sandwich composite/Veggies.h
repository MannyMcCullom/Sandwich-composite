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
	//determines which cheese will be used, and how much.
	//Postcondition: cheeseType determines the selected cheese, and numCheese determines how much cheese.

	Veggies();
	//Default constructor.
	//Postcondition: cheddar = 0, american = 0, mozarella = 0, ricotta = 0, provolone = 0, colbyJack = 0.
};

