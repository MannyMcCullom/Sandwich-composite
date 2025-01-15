#include "employeeType.h"

int employeeType::employeeNumberHigh = 0;

void employeeType::setNameFirst(string firstName)
{
	nameFirst = firstName;
}

void employeeType::setNameLast(string lastName)
{
	nameLast = lastName;
}

void employeeType::setNameFull(string firstName, string lastName)
{
	setNameFirst(firstName);
	setNameLast(lastName);
}

void employeeType::setEmployeeNumber()
{
	employeeNumber = employeeNumberHigh;
	employeeNumberHigh++;
}

void employeeType::setEmployeeNumber(int currentAccountNumber)
{
	employeeNumber = currentAccountNumber;
}

void employeeType::setEmployeeNumberHigh(int newHigh)
{
	employeeNumberHigh = newHigh;
}

void employeeType::setEmployeeSandwichesMade(int numOfSandwiches)
{
	employeeNumOfSandwichesMade = numOfSandwiches;
}

void employeeType::setEmployeeBalance(double balance)
{
	employeeBalance = balance;

	if (employeeBalance < 0)
	{
		employeeBalance = 0;
	}
}

string employeeType::getNameFirst() const
{
	return nameFirst;
}

string employeeType::getNameLast() const
{
	return nameLast;
}

string employeeType::getNameFull() const
{
	return nameFirst + " " + nameLast;
}

int employeeType::getEmployeeNumber() const
{
	return employeeNumber;
}

int employeeType::getEmployeeNumberHigh() const
{
	return employeeNumberHigh;
}

int employeeType::getEmployeeSandwichesMade() const
{
	return employeeNumOfSandwichesMade;
}

double employeeType::getEmployeeBalance() const
{
	cout << fixed << showpoint << setprecision(2);
	return employeeBalance;
}

void employeeType::print() const
{
	cout
		<< "Employee Number: "
		<< setfill('0')
		<< setw(15)
		<< getEmployeeNumber()
		<< setfill(' ')
		<< endl
		<< "Name: " << getNameFull()
		<< endl
		<< "Saandwiches Made: $" << getEmployeeSandwichesMade()
		<< endl
		<< "Balance: $" << getEmployeeBalance()
		<< endl
		;
}

employeeType::employeeType(string firstName, string lastName, double accountBalance)
{
	setNameFull(firstName, lastName);
	setEmployeeBalance(accountBalance);
}
