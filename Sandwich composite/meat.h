#pragma once
class meat
{
private:
	bool prosciutto;		// prosciutto to be added or not
	bool bologna;			// bologna to be added or not
	bool salami;			// salami to be added or not
	bool bacon;				// bacon to be added or not
	bool turkey;			// turkey to be added or not
	bool chicken;			// chicken to be added or not
	
public:
	void meatChoice(bool choice[6]);
	//determines which cheese will be used, and how much.
	//Postcondition: cheeseType determines the selected cheese, and numCheese determines how much cheese.

	meat();
	//Default constructor.
	//Postcondition: cheddar = 0, american = 0, mozarella = 0, ricotta = 0, provolone = 0, colbyJack = 0.
};

