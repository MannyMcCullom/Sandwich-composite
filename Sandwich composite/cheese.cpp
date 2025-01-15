#include "cheese.h"
#include <iostream>

using namespace std;

void cheese::cheeseChoice(int num, int Type)
{
	//would there be a loop somewhere for multiple cheese types?
	//if num of cheese is above 0, include in final cout statement.
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

cheese::cheese()
{
	cheddar = 0;
	american = 0;
	mozarella = 0;
	ricotta = 0;
	provolone = 0;
	colbyJack = 0;
}
