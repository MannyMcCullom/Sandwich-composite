#include "fillingType.h"
#include <iostream>

using namespace std;

fillingType::fillingType() {
	peanutbutter = false;
	jelly = false;
	roasted = false;
}
fillingType::fillingType(bool peanutb, bool jel)
{
	peanutbutter = peanutb;
	jelly = jel;
	roasted = false;
}
fillingType::fillingType(int cheeseNum, int cheeseType, bool roast) {
	peanutbutter = false;
	jelly = false;
	roasted = roast;
	cheese.cheeseChoice(cheeseNum, cheeseType);
}


void fillingType::Cheese(int cheeseNum, int cheeseType)
{
	cheese.cheeseChoice(cheeseNum, cheeseType);
}


void fillingType::veggies(bool choice[6])
{
	Veggies.veggiesChoice(choice);
}

void fillingType::Meat(bool choice[6])
{
	meat.meatChoice(choice);
}
