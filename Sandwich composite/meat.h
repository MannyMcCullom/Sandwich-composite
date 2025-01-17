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
	//determines which Meat will be used.
	//Postcondition: Sets all the bool variables based on array

	void showChoices(bool choice[6]) const;
	//changes an array according to all the meat
	//post: modifies array to match all private variables

	meat();
	//Default constructor.
	//Postcondition: prosciutto = 0, bologna = 0, salami = 0, bacon = 0, turkey = 0, chicken = 0.
};

