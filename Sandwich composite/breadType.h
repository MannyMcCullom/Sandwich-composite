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
	//pre: 
	//post:
	string getBread() const;
	void print() const;
	breadType(string b = "Wheat");
private:
	string bread;
};

#endif
