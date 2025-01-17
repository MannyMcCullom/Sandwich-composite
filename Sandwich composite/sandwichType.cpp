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
	system("cls");
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

void sandwichType::setNumberOfRecipes(int num)
{
	numOfRecipes = num;

	if (numOfRecipes < 0)
	{
		numOfRecipes = 0;
	}

	else if (numOfRecipes > MAX_NO_RECIPES)
	{
		numOfRecipes = MAX_NO_RECIPES;
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

		numOfEmployees = numOfEmployeesLoc;

		pEmployee = new employeeType[numOfEmployees];

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
					for (int index = 0; index < 5; index++)
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

void sandwichType::fileRecipeLoad()
{
	ifstream inFile;
	inFile.open("recipes.txt");

	if (inFile)
	{
		string line1;
		string line2;
		string tempLine;
		string tempStr;
		int q1;
		int q2;
		int numOfQuotes;
		int numOfRecipesLoc = 0;
		int currentRecipe = 0;

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

				if (numOfQuotes >= 4 && numOfQuotes % 2 == 0)
				{
					numOfRecipesLoc++;
				}
			}

			line2 = line1;
		}

		inFile.close();

		setNumberOfRecipes(numOfRecipesLoc);

		pNumOfRecipeComp = new int[numOfRecipes];

		//numOfRecipesLoc = numOfRecipes;

		pRecipe = new string * [numOfRecipes];

		inFile.open("recipes.txt");

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

				pNumOfRecipeComp[currentRecipe] = numOfQuotes / 2;

				pRecipe[currentRecipe] = new string[pNumOfRecipeComp[currentRecipe]];

				if (numOfQuotes >= 4 && numOfQuotes % 2 == 0)
				{
					tempLine = line1;

					for (int index = 0; index < pNumOfRecipeComp[currentRecipe]; index++)
					{
						q1 = tempLine.find('"');
						q2 = tempLine.find('"', q1 + 1);

						tempStr = tempLine.substr(1, q2 - 1);

						pRecipe[currentRecipe][index] = tempStr;

						cout << "M: " << index << endl;
						cout << "L: " << pRecipe[currentRecipe][index] << endl;

						if (index == (pNumOfRecipeComp[currentRecipe]) - 1)
						{
							break;
						}

						else
						{
							tempLine = tempLine.substr(q2 + 2);
						}
					}

					currentRecipe++;
				}
			}

			line2 = line1;
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

void sandwichType::fileRecipeSave()
{
	ofstream outFile;
	outFile.open("recipes.txt");

	for (int index = 0; index < numOfRecipes; index++)
	{
		for (int index2 = 0; index2 < pNumOfRecipeComp[index]; index2++)
		{
			outFile
				<< '"'
				<< pRecipe[index][index2]
				<< '"' << " "
				;
		}

		outFile << endl;
	}

	outFile.close();
}

// Actions
void sandwichType::actionRecipeCreate()
{
	numOfRecipes++;
	fileRecipeSave();
	fileRecipeLoad();
}

void sandwichType::actionLayerAdd()
{
	bool layerSelected = false;
	string layerName = "";

	if (pNumOfRecipeComp[numOfRecipes] < 10)
	{
		menuSelectLayer(layerName, layerSelected);

		if (layerSelected)
		{
			pNumOfRecipeComp[numOfRecipes]++;

			string* newRecipe;
			newRecipe = new string[pNumOfRecipeComp[numOfRecipes]];

			for (int index = 0; index < pNumOfRecipeComp[numOfRecipes] - 1; index++)
			{
				newRecipe[index] = pRecipe[numOfRecipes][index];
			}

			newRecipe[pNumOfRecipeComp[numOfRecipes] - 1] = layerName;
			//newRecipe[pNumOfRecipeComp[numOfRecipes] - 1] = "new layer";

			pRecipe[numOfRecipes] = newRecipe;
		}
	}
	
	else
	{
		// At Max Layer
	}
}

void sandwichType::actionLayerRemove()
{

	if (pNumOfRecipeComp[numOfRecipes] > 1)
	{
		pNumOfRecipeComp[numOfRecipes]--;

		string* newRecipe;
		newRecipe = new string[pNumOfRecipeComp[numOfRecipes]];

		for (int index = 0; index < pNumOfRecipeComp[numOfRecipes]; index++)
		{
			newRecipe[index] = pRecipe[numOfRecipes][index];
		}

		pRecipe[numOfRecipes] = newRecipe;
	}
	
	else
	{
		// no layers to remove
	}
}

void sandwichType::actionLayerRemoveAll()
{

	if (pNumOfRecipeComp[numOfRecipes] > 1)
	{
		pNumOfRecipeComp[numOfRecipes] = 1;

		string* newRecipe;
		newRecipe = new string[1];

		newRecipe[0] = pRecipe[numOfRecipes][0];

		pRecipe[numOfRecipes] = newRecipe;
	}

	else
	{
		// no layers to remove
	}
}

void sandwichType::actionEmployeeHire(employeeType& newEmployee)
{
	bool valid = false;
	string newCode;

	newEmployee.setEmployeeNumber();
	newEmployee.setEmployeeBalance(0.00);
	newEmployee.setEmployeeSandwichesMade(0);

	employeeType* pNewEmployee;
	pNewEmployee = new employeeType[numOfEmployees + 1];

	for (int index = 0; index < numOfEmployees; index++)
	{
		pNewEmployee[index] = pEmployee[index];
	}

	pNewEmployee[numOfEmployees] = newEmployee;

	numOfEmployees++;

	pEmployee = pNewEmployee;

	fileEmployeeSave();
}

void sandwichType::actionRecipeErase(int currentRecipe)
{
	string response;
	bool exit = false;

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[currentRecipe][0] << endl;

		if (pNumOfRecipeComp[currentRecipe] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[currentRecipe][index]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Erase " << pRecipe[currentRecipe][0] << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "y to erase " << pRecipe[currentRecipe][0]
			<< endl
			<< "q to exit"
			<< endl;

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (toupper(response[0]) == 'Y')
		{
			if (numOfRecipes <= 1)
			{
				pRecipe = nullptr;

				numOfRecipes = 0;
			}

			else
			{
				string** pNewRecipe;
				pNewRecipe = new string * [numOfRecipes - 1];

				int newRecipes = 0;
				int oldRecipies = 0;

				while (oldRecipies < numOfRecipes)
				{
					if (currentRecipe != oldRecipies)
					{
						pNewRecipe[currentRecipe] = pRecipe[oldRecipies];

						newRecipes++;
					}

					oldRecipies++;
				}

				pRecipe = pNewRecipe;

				numOfRecipes--;
			}

			fileRecipeSave();
			fileEmployeeLoad();

			exit = true;
			tempMessage += "Recipe Erased\n";
		}
	}
}

void sandwichType::actionEmployeeFire(int currentEmployee)
{
	string response;
	bool exit = false;

	while (!exit)
	{
		skipLines(50);

		longLine();
		pEmployee[currentEmployee].print();

		// Title Message
		longLine();
		cout << "Fire " << pEmployee[currentEmployee].getNameFull() << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "y to fire " << pEmployee[currentEmployee].getNameFirst()
			<< endl
			<< "q to exit"
			<< endl;

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (toupper(response[0]) == 'Y')
		{
			employeeType* pNewEmployee;
			pNewEmployee = new employeeType[numOfEmployees - 1];

			int newEmployees = 0;
			int oldEmployees = 0;

			while (oldEmployees < numOfEmployees)
			{
				if (currentEmployee != oldEmployees)
				{
					pNewEmployee[newEmployees] = pEmployee[oldEmployees];

					newEmployees++;
				}

				oldEmployees++;
			}

			pEmployee = pNewEmployee;

			numOfEmployees--;

			fileEmployeeSave();

			exit = true;
			tempMessage += "Employee Fired\n";
		}
	}
}

void sandwichType::actionChangeNameRecipe()
{
	string response;
	bool exit = false;

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[numOfRecipes][0] << endl;

		if (pNumOfRecipeComp[numOfRecipes] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int layer = pNumOfRecipeComp[numOfRecipes] - 1; layer > 0; layer--)
			{
				cout
					<< '\t'
					<< pRecipe[numOfRecipes][layer]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Change Recipe Name" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "enter new recipe name"
			<< endl
			<< "q to exit"
			<< endl;

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (response.length() > 1)
		{
			pRecipe[numOfRecipes][0] = response;
			tempMessage += "Recipe Name Changed\n";
		}

		else
		{
			tempMessage += "Invalid Input\n";
		}
	}
}

void sandwichType::actionChangeNameFirst(employeeType& newEmployee)
{
	string response;
	bool exit = false;

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
		cout << "Change First Name" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "enter new first name"
			<< endl
			<< "q to exit"
			<< endl;

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (response.length() > 1)
		{
			newEmployee.setNameFirst(response);
			tempMessage += "First Name Changed\n";
		}

		else
		{
			tempMessage += "Invalid Input\n";
		}
	}
}

void sandwichType::actionChangeNameLast(employeeType& newEmployee)
{
	string response;
	bool exit = false;

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
		cout << "Change Last Name" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "enter new last name"
			<< endl
			<< "q to exit"
			<< endl;

		// Response
		longLine();
		getline(cin, response);

		// Options
		if (toupper(response[0]) == 'Q')
		{
			exit = true;
		}

		else if (response.length() > 1)
		{
			newEmployee.setNameLast(response);
			tempMessage += "Last Name Changed\n";
		}

		else
		{
			tempMessage += "Invalid Input\n";
		}
	}
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
	string selections[numOfSelections] = { "Make Sandwiches", "Recipe Book",  "Employee Management" };

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
				menuManagementRecipe();
				break;
			case 2:
				menuManagementEmployee();
				break;
			}
		}
	}
}

void sandwichType::menuManagementRecipe()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 2;
	string selections[numOfSelections] = { "View Recipes", "Create Recipe" };

	while (!exit)
	{
		skipLines(50);

		// Title Message
		longLine();
		cout << "Recipe Book" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "w or s to navigate"
			<< endl
			<< "e to make selection"
			<< endl
			<< "q to log out"
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
				menuSelectRecipe();
				break;
			case 1:
				menuCreateRecipe();
				break;
			}
		}
	}
}

void sandwichType::menuManagementEmployee()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 2;
	string selections[numOfSelections] = { "Select Employee", "Hire Employee"};

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
				menuSelectEmployeeOptions();
				break;
			case 1:
				menuEmployeeHire();
				break;
			}
		}
	}
}

void sandwichType::menuSelectRecipe()
{
	string response;
	bool exit = false;

	fileRecipeLoad();

	int selection = 0;
	int numOfSelections = numOfRecipes;
	string* selections;
	selections = new string[numOfSelections];

	while (!exit)
	{
		if (numOfRecipes < 1)
		{
			tempMessage += "No Recipes";
			break;
		}

		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[selection][0] << endl;

		if (pNumOfRecipeComp[selection] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[selection]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[selection][index]
					<< endl
					;
			}
		}
		

		// Title Message
		longLine();
		cout << "Select Recipe" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to select recipe"
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

				cout << pRecipe[index][0];

				cout << ']' << endl;
			}

			else
			{
				cout << ' ';

				cout << pRecipe[index][0];

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
			menuRecipeOptions(selection);
			tempMessage += "Recipe Selected";
			exit = true;
		}
	}
}

void sandwichType::menuSelectLayer(string& layerName, bool& layerSelected)
{
	breadType bread;

	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 4;
	string selections[numOfSelections] = { "Bread", "Meat", "Cheese", "Veggies" };

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[currentRecipe][0] << endl;

		if (pNumOfRecipeComp[currentRecipe] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[currentRecipe][index]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Ingredients" << endl;

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
				// menuSelectLayerBread(layerName, layerSelected);
				layerName = bread.getBread();
				layerSelected = true;
				break;
			case 1:
				//menuSelectLayerMeat(layerName, layerSelected);
				break;
			case 2:
				menuSelectLayerCheese(layerName, layerSelected);
				break;
			case 3:
				menuSelectLayerVeggies(layerName, layerSelected);
				break;
			}
		}

		if (layerSelected)
		{
			exit = true;
		}
	}
}

/*
void sandwichType::menuSelectLayerBread(string& layerName, bool& layerSelected)
{
	breadType bread;

	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 4;
	string selections[numOfSelections] = { "Bread", "Meat", "Cheese", "Veggies" };

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[currentRecipe][0] << endl;

		if (pNumOfRecipeComp[currentRecipe] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[currentRecipe][index]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Ingredients" << endl;

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
				menuSelectLayerBread(layerName, layerSelected);
				break;
			case 1:
				menuSelectLayerMeat(layerName, layerSelected);
				break;
			case 2:
				menuSelectLayerCheese(layerName, layerSelected);
				break;
			case 3:
				menuSelectLayerVeggies(layerName, layerSelected);
				break;
			}
		}
		//  { "Bread", "Meat", "Cheese", "Veggies" };
		if (layerSelected)
		{
			exit = true;
		}
	}
}
*/

/*
void sandwichType::menuSelectLayerMeat(string& layerName, bool& layerSelected)
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 4;
	string selections[numOfSelections] = { "Bread", "Meat", "Cheese", "Veggies" };

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		if (pNumOfRecipeComp[currentRecipe] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[currentRecipe][index]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Ingredients" << endl;

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
				//menuSelectLayerBread(layerName, layerSelected);
				break;
			case 1:
				menuSelectLayerMeat(layerName, layerSelected);
				break;
			case 2:
				menuSelectLayerCheese(layerName, layerSelected);
				break;
			case 3:
				//menuSelectLayerVeggies(layerName, layerSelected);
				break;
			}
		}
		//  { "Bread", "Meat", "Cheese", "Veggies" };
		if (layerSelected)
		{
			exit = true;
		}
	}
}
//*/

//*
void sandwichType::menuSelectLayerCheese(string& layerName, bool& layerSelected)
{
	fillingType cheese;
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 6;
	string selections[numOfSelections] = { "Cheddar", "american", "mozarella", "ricotta", "provolone", "colbyJack"};

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[currentRecipe][0] << endl;

		if (pNumOfRecipeComp[currentRecipe] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[currentRecipe][index]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Ingredients" << endl;

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
			layerName = cheese.CheeseV2(1, selection);
			layerSelected = true;
		}

		if (layerSelected)
		{
			exit = true;
		}
	}
}
//*/

//*
void sandwichType::menuSelectLayerVeggies(string& layerName, bool& layerSelected)
{
	fillingType veggie;
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 6;
	string selections[numOfSelections] = { "tomatoes", "cucumbers", "onions", "peppers", "celery", "olives"};

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[currentRecipe][0] << endl;

		if (pNumOfRecipeComp[currentRecipe] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[currentRecipe][index]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Ingredients" << endl;

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
			layerName = veggie.VeggieV2(1, selection);
			layerSelected = true;
		}

		if (layerSelected)
		{
			exit = true;
		}
	}
}
//*/

void sandwichType::menuSelectEmployeeOptions()
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

				cout << pEmployee[index].getNameFull();

				cout << ']' << endl;
			}

			else
			{
				cout << ' ';

				cout << pEmployee[index].getNameFull();

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
			menuEmployeeOptions(selection);
			tempMessage += "Employee Selected";
			exit = true;
		}
	}
}

void sandwichType::menuRecipeOptions(int currentRecipe)
{
	string response;
	bool exit = false;

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[currentRecipe][0] << endl;

		if (pNumOfRecipeComp[currentRecipe] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
			{
				cout
					<< '\t'
					<< pRecipe[currentRecipe][index]
					<< endl
					;
			}
		}

		// Title Message
		longLine();
		cout << "Recipe Options" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to delete recipe"
			<< endl
			<< "q to exit"
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
			actionRecipeErase(currentRecipe);
			exit = true;
		}
	}
}

void sandwichType::menuEmployeeOptions(int currentEmployee)
{
	string response;
	bool exit = false;

	while (!exit)
	{
		skipLines(50);

		longLine();
		pEmployee[currentEmployee].print();

		// Title Message
		longLine();
		cout << "Employee Options" << endl;

		// Temp Message
		printTempMessage();

		// Controls
		longLine();
		cout
			<< "e to fire Employee"
			<< endl
			<< "q to exit"
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
			actionEmployeeFire(currentEmployee);
			exit = true;
		}
	}
}

void sandwichType::menuCreateRecipe()
{
	currentRecipe = numOfRecipes;

	string response;
	bool exit = false;
	bool newRecipe = false;

	string** pNewRecipe;
	pNewRecipe = new string*[numOfRecipes + 1];

	int* pNewNumOfRecipeComp;
	pNewNumOfRecipeComp = new int[numOfRecipes + 1];

	for (int index = 0; index < numOfRecipes; index++)
	{
		pNewRecipe[index] = pRecipe[index];
		pNewNumOfRecipeComp[index] = pNumOfRecipeComp[index];
	}

	pNewNumOfRecipeComp[numOfRecipes] = 1;
	pNewRecipe[numOfRecipes] = new string[pNewNumOfRecipeComp[numOfRecipes]];

	pNewRecipe[numOfRecipes][0] = "";

	pRecipe = pNewRecipe;
	pNumOfRecipeComp = pNewNumOfRecipeComp;

	int selection = 0;
	const int numOfSelections = 3;
	string selections[numOfSelections] = { "Name", "Layers", "Create Recipe" };

	while (!exit)
	{
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[numOfRecipes][0] << endl;

		if (pNumOfRecipeComp[numOfRecipes] > 1)
		{
			cout << "Ingredients: " << endl;

			for (int layer = pNumOfRecipeComp[numOfRecipes] - 1; layer > 0; layer--)
			{
				cout
					<< '\t'
					<< pRecipe[numOfRecipes][layer]
					<< endl
					;
			}
		}
		

		// Title Message
		longLine();
		cout << "Creating Recipe" << endl;

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
				actionChangeNameRecipe();
				break;
			case 1:
				menuLayers();
				break;
			case 2:
				if (pRecipe[numOfRecipes][0].length() > 4 && pNewNumOfRecipeComp[numOfRecipes] > 1)
				{
					actionRecipeCreate();
					newRecipe = true;
					exit = true;

					tempMessage += "Recipe Created\n";
				}

				else if (pRecipe[numOfRecipes][0].length() < 5)
				{
					tempMessage += "Recipe Name Not Long Enough\n";
				}

				else if (pNewNumOfRecipeComp[numOfRecipes] < 2)
				{
					tempMessage += "Recipe Has No Ingredients\n";
				}
				
				break;
			}
		}
	}

	if (!newRecipe)
	{
		pNewRecipe = new string * [numOfRecipes];

		pNewNumOfRecipeComp = new int[numOfRecipes];

		for (int index = 0; index < numOfRecipes; index++)
		{
			pNewRecipe[index] = pRecipe[index];
			pNewNumOfRecipeComp[index] = pNumOfRecipeComp[index];
		}

		pRecipe = pNewRecipe;
		pNumOfRecipeComp = pNewNumOfRecipeComp;
	}

}

void sandwichType::menuLayers()
{
	string response;
	bool exit = false;

	int selection = 0;
	const int numOfSelections = 3;
	string selections[numOfSelections] = { "Add Layer", "Remove Layer", "Remove All Layers" };

	while (!exit)
	{
		//cout << numOfLayers << endl;
		skipLines(50);

		// User Display
		longLine();
		cout << "Recipe: " << pRecipe[numOfRecipes][0] << endl;

		if (pNumOfRecipeComp[numOfRecipes] > 1)
		{
			if (pNumOfRecipeComp[currentRecipe] > 1)
			{
				cout << "Ingredients: " << endl;

				for (int index = 1; index < pNumOfRecipeComp[currentRecipe]; index++)
				{
					cout
						<< '\t'
						<< pRecipe[currentRecipe][index]
						<< endl
						;
				}
			}
		}

		// Title Message
		longLine();
		cout << "Recipe Layers" << endl;

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
			string tempStr;

			switch (selection)
			{
			case 0:
				actionLayerAdd();
				break;
			case 1:
				actionLayerRemove();
				break;
			case 2:
				actionLayerRemoveAll();
				break;
			}
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
	string selections[numOfSelections] = { "First Name", "Last Name", "Hire New Employee" };

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

sandwichType::sandwichType()
{
	menuStart();
}

sandwichType::~sandwichType()
{
	delete[] pEmployee;
	delete[] pRecipe;
	delete[] pNumOfRecipeComp;
}