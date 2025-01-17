#include "meat.h"

void meat::meatChoice(bool choice[6]) {
	prosciutto = choice[0];
	bologna = choice[1];
	salami = choice[2];
	bacon = choice[3];
	turkey = choice[4];
	chicken = choice[5];
}

string meat::meatChoiceV2(int num, int Type)
{
	string meat;

	switch (Type)
	{
	case 0:
		meat = "prosciutto";
		break;
	case 1:
		meat = "bologna";
		break;
	case 2:
		meat = "salami";
		break;
	case 3:
		meat = "bacon";
		break;
	case 4:
		meat = "turkey";
		break;
	case 5:
		meat = "chicken";
		break;
	}

	return meat;
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