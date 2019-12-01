#include "HandArmor.h"

/*
Constractor
*/
HandArmor::HandArmor(const size_t x, const  size_t y, const  double amountDefence, const  EArmor armorKind)
	:Armor(x,y,amountDefence,armorKind)
{}

/*
Distractor
*/
HandArmor::~HandArmor() {}

/*
toString
*/
string HandArmor::toString() const {
	return "(HandArmor:)" + Armor::toString();
}
