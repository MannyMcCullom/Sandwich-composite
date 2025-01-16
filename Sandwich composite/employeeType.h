#ifndef H_employeeType
#define H_employeeType

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class employeeType
{
public:
	void setNameFirst(string firstName);

	void setNameLast(string lastName);

	void setNameFull(string firstName, string lastName);

	void setEmployeeNumber();

	void setEmployeeNumber(int);

	void setEmployeeNumberHigh(int);

	void setEmployeeSandwichesMade(int);

	void setEmployeeBalance(double accountBalance);

	string getNameFirst() const;

	string getNameLast() const;

	string getNameFull() const;

	int getEmployeeNumber() const;

	int getEmployeeNumberHigh() const;

	int getEmployeeSandwichesMade() const;

	double getEmployeeBalance() const;

	void print() const;

	employeeType(string firstName = "first", string lastName = "last", double accountBalance = 0.00);

private:
	string nameFirst;
	string nameLast;
	int employeeNumber;
	double employeeBalance;
	int employeeNumOfSandwichesMade;
	
	static int employeeNumberHigh;
};

#endif