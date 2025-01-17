#include "cheese.h"
#ifndef H_fillingType
#define H_fillingType

using namespace std;

class fillingType
{
public:

	//constructor
	fillingType();
	fillingType(bool peanutbutter, bool jelly);
	fillingType(int cheeseNum, int cheeseType, bool roast);
	
	void Cheese(int cheeseNum, int cheeseType);
	//determines which cheese will be used, and how much.
	//Postcondition: Calls functions from cheese

	string CheeseV2(int cheeseNum, int cheeseType);
	
	string VeggieV2(int cheeseNum, int cheeseType);

	void Meat(bool choice[6]);
	//determines which meat types will be used.
	//Postcondition: Calls functions from meat

	string returnMeat() const;
	//lists all the meat in the sandwich
	//post: returns string containing all variable names in meat object set to true

	void veggies(bool choice[6]);
	//determines which veggies types will be used.
	//Postcondition: Calls functions from veggies

	string returnVeggies() const;
	//lists all the veggies in the sandwich
	//post: returns string containing all variable names in veggies object set to true

	void roast(bool roast);
	//determines if to use roasted ingredients
	//Postcondition: sets roasted to true or false

	bool returnRoastBool() const;
	//sends back boolian if roasted or not
	//post: returns bool roasted
	
	string returnRoastString() const;
	//sends a string confirming if roasted is true or false
	//post: returns string "roasted" or "not roasted" on condition of bool roasted

private:
	
	//misc
	bool peanutbutter;
	bool jelly;
	//cheese
	cheese cheese;
	//meat
	meat meat;
	////veggies
	Veggies Veggies;
	//roasted or not
	bool roasted;

};

#endif
