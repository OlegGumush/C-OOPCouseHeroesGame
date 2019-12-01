#include "Armor.h"
#include <string>
/*
Constractor
*/
Armor::Armor(const size_t x, const  size_t y, const  double defenceAmount, const  EArmor armorKind)
	:Item(x,y,ARMOR), defenceAmount(defenceAmount) , armorKind(armorKind)
{}

/*
Distractor
*/
Armor::~Armor() {}

/*
getters
*/
const EArmor& Armor::getArmorKind() const {
	return armorKind;
}
const double& Armor::getDefenceAmount() const {
	return defenceAmount;
}


/*
toString
*/
string Armor::toString() const {
	return "(Armor:)(DefenceAmount:" + to_string(this->defenceAmount) + ")" + Item::toString();
}