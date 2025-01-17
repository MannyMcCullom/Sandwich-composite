#include "Veggies.h"

void Veggies::veggiesChoice(bool choice[6]) {
	tomatoes = choice[0];
	cucumbers = choice[1];
	onions = choice[2];
	peppers = choice[3];
	celery = choice[4];
	olives = choice[5];
}

void Veggies::showChoices(bool choice[6]) const {
	choice[0] = tomatoes;
	choice[1] = cucumbers;
	choice[2] = onions;
	choice[3] = peppers;
	choice[4] = celery;
	choice[5] = olives;
}

Veggies::Veggies() {
	tomatoes = false;
	cucumbers = false;
	onions = false;
	peppers = false;
	celery = false;
	olives = false;
}