#include "fillingType.h"
#include <iostream>

using namespace std;

fillingType::fillingType(bool peanutb, bool jel)
{
	peanutbutter = peanutb;
	jelly = jel;
}
fillingType::fillingType(int cheeseNum, int cheeseType) {
	peanutbutter = false;
	jelly = false;
	cheese.cheeseChoice(cheeseNum, cheeseType);
}


void fillingType::Cheese() 
{
  
}


void fillingType::Veggies(int choice) 
{

}

void fillingType::Meat(int numMeat, int meatType) 
{

}
