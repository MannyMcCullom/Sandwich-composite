#include "meat.h"

void meat::meatChoice(bool choice[6]) {
	prosciutto = choice[0];
	bologna = choice[1];
	salami = choice[2];
	bacon = choice[3];
	turkey = choice[4];
	chicken = choice[5];
}

meat::meat() {
	prosciutto = false;
	bologna = false;
	salami = false;
	bacon = false;
	turkey = false;
	chicken = false;
}