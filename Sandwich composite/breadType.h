//************************
// Author: Zachary Connor
// Date Created: 1/14/2025
// Class: ITCS 2550
//************************
#pragma once
#ifndef H_breadType
#define H_breadType

#include <string>
using namespace std;

class breadType
{
public:
	void setBread(string b);
	//pre: Function that takes one string as an argument. Sets bread to the value of b
	//post: bread = b

	string getBread() const;
	//pre: Function that returns the value of bread
	//post: return bread;

	void print() const;
	//pre: Function that outputs the value of bread to the screen
	//post: bread = " "

	breadType(string b = "Wheat");
	//pre: Default Constructor with a string parameter.
	//post: bread = b. if b is not specified bread = "Wheat";

private:
	string bread; //variable that stores the value for bread.
};

#endif
