#include "Veggies.h"

void Veggies::veggiesChoice(bool choice[6]) {
	tomatoes = choice[0];
	cucumbers = choice[1];
	onions = choice[2];
	peppers = choice[3];
	celery = choice[4];
	olives = choice[5];
}

Veggies::Veggies() {
	tomatoes = false;
	cucumbers = false;
	onions = false;
	peppers = false;
	celery = false;
	olives = false;
}