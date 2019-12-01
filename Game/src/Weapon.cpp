#include "Weapon.h"

/*
Constractor
*/
Weapon::Weapon(const size_t x, const size_t y, const EWeapon weaponName , const EWeapon numberHands, const double power)
	:Item(x,y,WEAPON) , power(power), weaponName(weaponName) , numberHands(numberHands) 
{}

/*
Disstractor
*/
Weapon::~Weapon() {}

/*
getters
*/
const double& Weapon::getPower() const{
	return power;
}

/*
getters
*/
const EWeapon& Weapon::getWeaponName() const{
	return weaponName;
}
const EWeapon& Weapon::getNumberHands() const{
	return numberHands;
}

/*
toString
*/
string Weapon::toString() const {
	return "(Weapon:)(PowerAmount:" + to_string(this->power) + ")" + Item::toString();
}