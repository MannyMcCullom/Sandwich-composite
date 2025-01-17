#include "meat.h"

void meat::meatChoice(bool choice[6]) {
	prosciutto = choice[0];
	bologna = choice[1];
	salami = choice[2];
	bacon = choice[3];
	turkey = choice[4];
	chicken = choice[5];
}

void meat::showChoices(bool choice[6]) const {
	choice[0] = prosciutto;
	choice[1] = bologna;
	choice[2] = salami;
	choice[3] = bacon;
	choice[4] = turkey;
	choice[5] = chicken;
}

meat::meat() {
	prosciutto = false;
	bologna = false;
	salami = false;
	bacon = false;
	turkey = false;
	chicken = false;
}