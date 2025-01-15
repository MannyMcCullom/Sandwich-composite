#include "cheese.h"
#ifndef H_fillingType
#define H_fillingType

using namespace std;

class fillingType
{
public:
	fillingType();
	
	void Cheese();
	//determines which cheese will be used, and how much.
	//Postcondition: Calls functions from cheese
	

	void Meat(int numMeat, int meatType);

	void Veggies(int choice);

private:
	
	//misc
	bool peanutbutter;
	bool jelly;
	//cheese
	cheese cheese;
	//meat
	int numMeat;
	int meatType;
	int prosciutto;
	int bologna;
	int salami;
	int bacon;
	int turkey;
	int chicken;
	//veggies
	int tomatoes;
	int cucumbers;
	int onions;
	int peppers;
	int celery;
	int olives;
	//roasted or not
	bool roasted;
	




};

#endif
