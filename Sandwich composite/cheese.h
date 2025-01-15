#pragma once
using namespace std;

class cheese
{
private: 
	int cheddar; // number of cheddar slices
	int american; // number of american slices
	int mozarella; // number of mozarella slices
	int ricotta; // number of ricotta slices
	int provolone; // number of provolone slices
	int colbyJack; // number of colbyJack slices

public:
	void cheeseChoice(int numCheese, int cheeseType);
	//determines which cheese will be used, and how much.
	//Postcondition: cheeseType determines the selected cheese, and numCheese determines how much cheese.

	cheese();
	//Default constructor.
	//Postcondition: cheddar = 0, american = 0, mozarella = 0, ricotta = 0, provolone = 0, colbyJack = 0.
};
