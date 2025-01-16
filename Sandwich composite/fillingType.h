#include "cheese.h"
#ifndef H_fillingType
#define H_fillingType

using namespace std;

class fillingType
{
public:
	fillingType();
	fillingType(bool peanutbutter, bool jelly);
	fillingType(int cheeseNum, int cheeseType, bool roast);
	
	void Cheese(int cheeseNum, int cheeseType);
	//determines which cheese will be used, and how much.
	//Postcondition: Calls functions from cheese
	

	void Meat(bool choice[6]);
	//determines which meat types will be used.
	//Postcondition: Calls functions from meat

	void veggies(bool choice[6]);

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
