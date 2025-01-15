#ifndef H_sandwichType
#define H_sandwichType

#include "breadType.h"
#include "fillingType.h"

#include <iostream>
#include <string>

using namespace std;

enum bread { TOP_SLICE, BOTTOM_SLICE };

class sandwichType
{
public:
	void skipLines(int num);

	void longLine();

	void printTempMessage();

	void checkSelection(int& selection, int numOfSelections);

	void displayOptions(string selections[], int selection, int numOfSelections);

	// File Management
	void fileEmployeeLoad();

	// Menus
	void menuStart();

	void menuMain();

	void menuEmployeeManagement();

	//void menuEmployeeSelect();

	// Constructors
	sandwichType();

	~sandwichType();

private:
	breadType breadSlice[2];
	fillingType* pFilling;
	string tempMessage;

};

#endif