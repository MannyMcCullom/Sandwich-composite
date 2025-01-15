#include "sandwichType.h"

void sandwichType::printTempMessage()
{
	longLine();
	cout << tempMessage << endl;

	tempMessage = "";
}

void sandwichType::longLine()
{
	cout << "----------------------------------------" << endl;
}

void sandwichType::skipLines(int num)
{
	for (int index = 0; index < num; index++)
	{
		cout << endl;
	}
}

void sandwichType::checkSelection(int& selection, int numOfSelections)
{
	if (selection < 0)
	{
		selection = numOfSelections - 1;
	}

	else if (selection >= numOfSelections)
	{
		selection = 0;
	}
}

void sandwichType::displayOptions(string selections[], int selection, int numOfSelections)
{
	longLine();

	for (int index = 0; index < numOfSelections; index++)
	{
		if (index == selection)
		{
			cout
				<< '['
				<< selections[index]
				<< ']'
				<< endl;
		}

		else
		{
			cout
				<< ' '
				<< selections[index]
				<< ' '
				<< endl;
		}
	}
}

// File Management
void sandwichType::fileEmployeeLoad()
{

}

// Menus
void sandwichType::menuStart()
{
	string response;
	bool exit = false;

	while (!exit)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "C++ Deli" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to make sandwiches"
			<< endl
			<< "q to leave deli"
			<< endl;

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (toupper(response[0]) == 'E')
		{
			menuMain();
		}
	}
}

void sandwichType::menuMain()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 3;
	string selections[numOfSelections] = { "Make Sandwiches", "Employee Management", "Recipe Management" };

	while (!exit)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "Main Menu" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to make selection"
			<< endl
			<< "w or s to navigate"
			<< endl
			<< "q to exit"
			<< endl;

		// Display Options
		displayOptions(selections, selection, numOfSelections);

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (toupper(response[0]) == 'W')
		{
			// action
			selection--;
			checkSelection(selection, numOfSelections);
		}

		else if (toupper(response[0]) == 'S')
		{
			// action
			selection++;
			checkSelection(selection, numOfSelections);
		}

		else if (toupper(response[0]) == 'E')
		{
			// action
			switch (selection)
			{
			case 0:
				//gameMakeSandwiches();
				break;
			case 1:
				menuEmployeeManagement();
				break;
			case 2:
				//menuRecipeManagement();
				break;
			}
		}
	}
}

void sandwichType::menuEmployeeManagement()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 3;
	string selections[numOfSelections] = { "Select Employee", "Hire Employee", "Fire Employee"};

	while (!exit)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "Employee Management" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to make selection"
			<< endl
			<< "w or s to navigate"
			<< endl
			<< "q to exit"
			<< endl;

		// Display Options
		displayOptions(selections, selection, numOfSelections);

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (toupper(response[0]) == 'W')
		{
			selection--;
			checkSelection(selection, numOfSelections);
		}

		else if (toupper(response[0]) == 'S')
		{
			selection++;
			checkSelection(selection, numOfSelections);
		}

		else if (toupper(response[0]) == 'E')
		{
			switch (selection)
			{
			case 0:
				menuEmployeeManagement();
				break;
			case 1:
				//menuEmployeeCreate();
				break;
			case 2:
				//actionEmployeeFire();
				break;
			}
		}
	}
}

/*
void sandwichType::menuEmployeeSelect()
{
	string response;
	bool exit = false;

	fileEmployeeLoad();

	int selection = 0;
	int numOfSelections = numOfEmployees;
	string* selections;
	selections = new string[numOfSelections];

	while (!exit)
	{
		if (numOfEmployees < 1)
		{
			tempMessage += "No Accounts";
			break;
		}

		skipLines(50);

		// User Display
		longLine();
		pEmployee[selection].print();

		// Title Message
		longLine();
		cout
			<< "Select Employee"
			<< endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to select employee"
			<< endl
			<< "w or s to navigate"
			<< endl
			<< "q to exit"
			<< endl;

		// Options
		longLine();

		for (int index = 0; index < numOfSelections; index++)
		{
			if (index == selection)
			{
				cout << '[';

				cout
					<< setw(15)
					<< setfill('0')
					<< pEmployee[index].getEmployeeNumber()
					<< setfill(' ')
					<< setw(20)
					<< pEmployee[index].getNameFull()
					;

				cout << ']' << endl;
			}

			else
			{
				cout << ' ';

				cout
					<< setw(15)
					<< setfill('0')
					<< pEmployee[index].getEmployeeNumber()
					<< setfill(' ')
					<< setw(20)
					<< pEmployee[index].getNameFull()
					;

				cout << ' ' << endl;
			}
		}


		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (toupper(response[0]) == 'W')
		{
			// action
			selection--;
			checkSelection(selection, numOfSelections);
		}

		else if (toupper(response[0]) == 'S')
		{
			// action
			selection++;
			checkSelection(selection, numOfSelections);
		}

		else if (toupper(response[0]) == 'E')
		{
			//actionEmployeeSelect(selection);
			employeeSelected = true;
			exit = true;
		}
	}
}
*/

sandwichType::sandwichType()
{
	menuStart();
}

sandwichType::~sandwichType()
{
	//delete[] pFilling;
}