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

string fillingType::CheeseV2(int cheeseNum, int cheeseType)
{
	return cheese.cheeseChoiceV2(cheeseNum, cheeseType);
}


void fillingType::veggies(bool choice[6])
{
	Veggies.veggiesChoice(choice);
}

string fillingType::returnVeggies() const {
	bool choice[6];
	Veggies.showChoices(choice);
	int count = 0;
	string allNames = " ";
	if (choice[0] == true) {
		allNames += "tomatoes, ";
		count++;
	}
	if (choice[1] == true) {
		allNames += "cucumbers, ";
		count++;
	}
	if (choice[2] == true) {
		allNames += "onions, ";
		count++;
	}
	if (choice[3] == true) {
		allNames += "peppers, ";
		count++;
	}
	if (choice[4] == true) {
		allNames += "celery, ";
		count++;
	}
	if (choice[5] == true) {
		allNames += "olives, ";
		count++;
	}
	if (allNames.length() >= 1) {
		allNames.resize(allNames.length() - 2); //remove last ", " 2 character (used resize instead of erase, cause faster)
	}
	if (count <= 0) {
		return "No Veggies Selected";
	}
	else {
		return allNames;
	}
}

void fillingType::roast(bool r) {
	roasted = r;
}

bool fillingType::returnRoastBool() const {
	return roasted;
}

string fillingType::returnRoastString() const {
	if (roasted == true) {
		return "roasted";
	}
	else {
		return "not roasted";
	}
}

void fillingType::Meat(bool choice[6])
{
	meat.meatChoice(choice);
}

string fillingType::returnMeat() const {
	bool choice[6];
	meat.showChoices(choice);
	int count = 0;
	string allNames = " ";
	if (choice[0] == true) {
		allNames += "prosciutto, ";
		count++;
	}
	if (choice[1] == true) {
		allNames += "bologna, ";
		count++;
	}
	if (choice[2] == true) {
		allNames += "salami, ";
		count++;
	}
	if (choice[3] == true) {
		allNames += "bacon, ";
		count++;
	}
	if (choice[4] == true) {
		allNames += "turkey, ";
		count++;
	}
	if (choice[5] == true) {
		allNames += "chicken, ";
		count++;
	}
	if (allNames.length() >= 1) {
		allNames.resize(allNames.length() - 2); //remove last ", " 2 character (used resize instead of erase, cause faster)
	}
	if (count <= 0) {
		return "No Veggies Selected";
	}
	else {
		return allNames;
	}
}