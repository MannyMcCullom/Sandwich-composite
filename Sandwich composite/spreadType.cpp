#include "spreadType.h"

string spreadType::spreadChoice(int spreadType)
{
	string spread = "";

	switch (spreadType)
	{
	case 0:
		spread = "peanut butter";
		break;
	case 1:
		spread = "jelly";
		break;
	case 2:
		spread = "mayo";
		break;
	case 3:
		spread = "relish";
		break;
	case 4:
		spread = "ketchup";
		break;
	case 5:
		spread = "mustard";
		break;
	}

	return spread;
}

spreadType::spreadType()
{

}