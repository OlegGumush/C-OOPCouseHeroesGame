#include "BodyArmor.h"

/*
Constructor
*/
BodyArmor::BodyArmor(const size_t x, const  size_t y, const  double defenceAmount, const EArmor armorKind)
	:Armor(x, y, defenceAmount , armorKind)
{}

/*
Distructor
*/
BodyArmor::~BodyArmor() {}

/*
toString
*/
string BodyArmor::toString() const {
	return "(BodyArmor:)" + Armor::toString();
}