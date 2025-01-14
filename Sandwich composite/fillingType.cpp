#include "fillingType.h"
#include "cheese.h"
#include <iostream>

using namespace std;


fillingType::fillingType()
{

}

void fillingType::Cheese(int num, int Type) 
{
	Numcheese = num;
	cheeseType = Type;
	cheeses.cheeseChoice(Numcheese, cheeseType);
  
}

void fillingType::Veggies(int choice) 
{

}

void fillingType::Meat(int numMeat, int meatType) 
{

}
