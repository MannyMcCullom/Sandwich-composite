#ifndef H_sandwichType
#define H_sandwichType

#include "breadType.h"
#include "fillingType.h"
#include "employeeType.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

enum bread { TOP_SLICE, BOTTOM_SLICE };

const int MAX_NO_EMPLOYEES = 10;

class sandwichType
{
public:
	void skipLines(int num);

	void longLine();

	void printTempMessage();

	void checkSelection(int& selection, int numOfSelections);

	void displayOptions(string selections[], int selection, int numOfSelections);

	void setNumberOfEmployees(int);

	// File Management
	void fileEmployeeLoad();

	void fileRecipeLoad();

	void fileEmployeeSave();

	void fileRecipeSave();

	// Actions
	void actionEmployeeHire(employeeType& newEmployee);

	void actionEmployeeFire(int currentEmployee);

	void actionChangeNameFirst(employeeType& newAccount);

	void actionChangeNameLast(employeeType& newAccount);

	// Menus
	void menuStart();

	void menuMain();

	void menuManagementRecipe();

	void menuManagementEmployee();

	void menuSelectRecipe();

	void menuSelectEmployeeOptions();

	void menuCreateRecipe();

	void menuEmployeeHire();

	void menuEmployeeOptions(int selection);

	// Constructors
	sandwichType();

	~sandwichType();

private:
	string tempMessage;
	breadType breadSlice[2];
	fillingType* pFilling;
	employeeType* pEmployee;
	string** pRecipe;
	bool employeeSelected;
	int numOfEmployees;
	int numOfRecipes;
};

#endif