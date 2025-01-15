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

void sandwichType::setNumberOfEmployees(int num)
{
	numOfEmployees = num;

	if (numOfEmployees < 0)
	{
		numOfEmployees = 0;
	}

	else if (numOfEmployees > MAX_NO_EMPLOYEES)
	{
		numOfEmployees = MAX_NO_EMPLOYEES;
	}
}

// File Management
void sandwichType::fileEmployeeLoad()
{
	ifstream inFile;
	inFile.open("employees.txt");

	if (inFile)
	{
		string line1;
		string line2;
		string tempLine;
		string tempStr;
		int q1;
		int q2;
		int numOfQuotes;
		int numOfEmployeesLoc = 0;
		int currentEmployee = 0;

		while (inFile)
		{
			numOfQuotes = 0;
			getline(inFile, line1);

			if (line2 != line1)
			{
				for (int index = 0; index < line1.length(); index++)
				{
					if (line1[index] == '"')
					{
						numOfQuotes++;
					}
				}

				if (numOfQuotes == 10)
				{
					numOfEmployeesLoc++;
				}
			}

			line2 = line1;
		}

		inFile.close();

		setNumberOfEmployees(numOfEmployeesLoc);

		numOfEmployeesLoc = numOfEmployees;

		pEmployee = new employeeType[numOfEmployeesLoc];

		inFile.open("employees.txt");

		line1 = "";
		line2 = "";

		while (inFile)
		{
			numOfQuotes = 0;
			getline(inFile, line1);

			if (line2 != line1)
			{
				for (int index = 0; index < line1.length(); index++)
				{
					if (line1[index] == '"')
					{
						numOfQuotes++;
					}
				}
				cout << numOfEmployeesLoc << endl;
				if (numOfQuotes == 10)
				{
					tempLine = line1;
					for (int index = 0; index < 7; index++)
					{
						q1 = tempLine.find('"');
						q2 = tempLine.find('"', q1 + 1);

						tempStr = tempLine.substr(1, q2 - 1);

						switch (index)
						{
						case 0:
							pEmployee[currentEmployee].setNameFirst(tempStr);
							break;
						case 1:
							pEmployee[currentEmployee].setNameLast(tempStr);
							break;
						case 2:
							pEmployee[currentEmployee].setEmployeeNumber(stoi(tempStr));
							break;
						case 3:
							pEmployee[currentEmployee].setEmployeeBalance(stod(tempStr));
							break;
						case 4:
							pEmployee[currentEmployee].setEmployeeSandwichesMade(stoi(tempStr));
							break;
						}

						if (index == 4)
						{
							break;
						}
						else
						{
							tempLine = tempLine.substr(q2 + 2);
						}
					}

					currentEmployee++;
				}
			}

			line2 = line1;

			if (currentEmployee == numOfEmployees)
			{
				int tempEmployeeNum = pEmployee[0].getEmployeeNumberHigh();

				for (int index = 0; index < numOfEmployees; index++)
				{
					if (tempEmployeeNum <= pEmployee[index].getEmployeeNumber())
					{
						tempEmployeeNum = pEmployee[index].getEmployeeNumber() + 1;
					}
				}

				pEmployee[0].setEmployeeNumberHigh(tempEmployeeNum);

				break;
			}
		}
	}

	else
	{
		cout << "couldn't open file" << endl;
	}
}

void sandwichType::fileEmployeeSave()
{
	ofstream outFile;
	outFile.open("employees.txt");

	for (int index = 0; index < numOfEmployees; index++)
	{
		outFile
			<< '"'
			<< pEmployee[index].getNameFirst()
			<< '"' << " "
			<< '"'
			<< pEmployee[index].getNameLast()
			<< '"' << " "
			<< '"'
			<< pEmployee[index].getEmployeeNumber()
			<< '"' << " "
			<< '"'
			<< pEmployee[index].getEmployeeBalance()
			<< '"' << " "
			<< '"'
			<< pEmployee[index].getEmployeeSandwichesMade()
			<< '"'
			<< endl;
		;
	}

	outFile.close();
}

// Actions
void sandwichType::actionEmployeeHire(employeeType& newEmployee)
{
	bool valid = false;
	string newCode;

	newEmployee.setEmployeeNumber();

	employeeType* pNewEmployee;
	pNewEmployee = new employeeType[numOfEmployees + 1];

	for (int index = 0; index < numOfEmployees; index++)
	{
		pNewEmployee[index] = pEmployee[index];
	}

	pNewEmployee[numOfEmployees] = newEmployee;

	numOfEmployees++;

	pEmployee = new employeeType[numOfEmployees];

	for (int index = 0; index < numOfEmployees; index++)
	{
		pEmployee[index] = pNewEmployee[index];
	}

	fileEmployeeSave();
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
				menuEmployeeSelect();
				break;
			case 1:
				//menuEmployeeHire();
				break;
			case 2:
				//actionEmployeeFire();
				break;
			}
		}
	}
}

///*
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
			tempMessage += "No Employees";
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
			//exit = true;
			tempMessage += "Employee Selected";
			employeeSelected = true;
		}
	}
}

void sandwichType::menuEmployeeHire()
{
	string response;
	bool exit = false;

	employeeType newEmployee;

	int selection = 0;
	const int numOfSelections = 3;
	string selections[numOfSelections] = { "First Name", "Last Name", "Hire Employee" };

	while (!exit)
	{
		skipLines(50);

		longLine();
		cout
			<< "First Name: " << newEmployee.getNameFirst()
			<< endl
			<< "Last Name: " << newEmployee.getNameLast()
			<< endl
			;

		// Title Message
		longLine();
		cout << "Hire Employee" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to modify or make selection"
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
			switch (selection)
			{
			case 0:
				actionChangeNameFirst(newEmployee);
				break;
			case 1:
				actionChangeNameLast(newEmployee);
				break;
			case 2:
				actionEmployeeHire(newEmployee);
				exit = true;
				break;
			}
		}
	}
}

// "First Name", "Last Name", "Hire Employee" };

//*/

sandwichType::sandwichType()
{
	menuStart();
}

sandwichType::~sandwichType()
{
	//delete[] pFilling;
}