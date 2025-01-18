//************************
// Author: Zachary Connor
// Date Created: 1/14/2025
// Class: ITCS 2550
//************************
#include "breadType.h"
#include <iostream>
using namespace std;

void breadType::setBread(string b)
{
    bread = b;
}

string breadType::getBread() const
{
    return bread;
}

string breadType::breadChoice(int breadType)
{
	string bread = "";

	switch (breadType)
	{
	case 0:
		bread = "white";
		break;
	case 1:
		bread = "wheat";
		break;
	case 2:
		bread = "honey wheat";
		break;
	case 3:
		bread = "potato";
		break;
	case 4:
		bread = "french";
		break;
	case 5:
		bread = "spinach";
		break;
	}

	return bread;
}

void breadType::print() const
{
    cout << "Bread Type = " << bread << " ";
}

breadType::breadType(string b)
{
    bread = b;
}