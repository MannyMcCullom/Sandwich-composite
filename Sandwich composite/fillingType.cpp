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

string fillingType::VeggieV2(int veggieNum, int veggieType)
{
	return Veggies.veggiesChoiceV2(veggieNum, veggieType);
}

string fillingType::MeatV2(int veggieNum, int veggieType)
{
	return meat.meatChoiceV2(veggieNum, veggieType);
}

string fillingType::spreadV2(int spreadType)
{
	return spread.spreadChoice(spreadType);
}

string fillingType::breadV2(int breadType)
{
	return bread.breadChoice(breadType);
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

bool fillingType::checkFilling(bool reqVeg[6], bool reqMeat[6]) const {
	bool choices[6];
	bool result[2];
	Veggies.showChoices(choices);
	for (int i = 0; i < 6; i++) {
		if (choices[i] != reqVeg[i]) {
			result[0] = false;
		}
	}
	meat.showChoices(choices);
	for (int i = 0; i < 6; i++) {
		if (choices[i] != reqMeat[i]) {
			result[1] = false;
		}
	}
	return result[0] && result[1];
}

//bool compareArray(bool choice1[6], bool choice2[6]) {
//	for (int i = 0; i < 6; i++) {
//		if (choice1[i] != choice2[i]) {
//			return false;
//		}
//	}
//	return true;
//}