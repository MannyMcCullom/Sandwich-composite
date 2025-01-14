#include "fillingType.h"
#include <iostream>

using namespace std;


fillingType::fillingType()
{

}

void fillingType::Cheese(int num, int Type) 
{
	//would there be a loop somewhere for multiple cheese types?
	//if cheese type is above 0, include in final cout statement.
	switch (Type)
	{
	case 0:
		cheddar = num;
		break;
	case 1:
		american = num;
		break;
	case 2:
		mozarella = num;
		break;
	case 3:
		ricotta = num;
		break;
	case 4:
		provolone = num;
		break;
	case 5:
		colbyJack = num;
		break;
	default:
		cout << "Please select an appropriate number." << endl;
		break;
	}
  
}

void fillingType::Veggies(int choice) 
{

}

void fillingType::Meat(int numMeat, int meatType) 
{

}
