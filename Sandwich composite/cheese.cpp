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

string cheese::cheeseChoiceV2(int num, int Type)
{
	//would there be a loop somewhere for multiple cheese types?
	//if num of cheese is above 0, include in final cout statement.
	string cheese = "";
	switch (Type)
	{
	case 0:
		cheese = "cheddar";
		break;
	case 1:
		cheese = "american";
		break;
	case 2:
		cheese = "mozarella";
		break;
	case 3:
		cheese = "ricotta";
		break;
	case 4:
		cheese = "provolone";
		break;
	case 5:
		cheese = "colbyJack";
		break;
	}

	return cheese + " cheese";
}

void cheese::drawCheese() {
	cout << "          ___" << endl;
	cout << "        .'o O'-._" << endl;
	cout << "       / O o_.-`|" << endl;
	cout << "      /O_.-'  O |" << endl;
	cout << "      | o   o .-`" << endl;
	cout << "      |o O_.-'" << endl;
	cout << "      '--`" << endl;
}

void cheese::drawCheeseSlice() {
	cout << "       ,--------," << endl;
	cout << "      /        /" << endl;
	cout << "     /        /" << endl;
	cout << "     '-------'";
	if (cheddar >= 1) {
		cout << "\tx" << cheddar << endl;
	} else if (american >= 1)  {
		cout << "\tx" << american << endl;
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
