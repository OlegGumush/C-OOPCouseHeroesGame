#include "Sword.h"

/*
Constractor
*/
Sword::Sword(const size_t x, const size_t y, const EWeapon weaponName, const double power)
	: OneHandWeapon(x, y, weaponName, power)
{}

/*
Distractor
*/
Sword::~Sword() {}

/*
toString
*/
string Sword::toString() const {
	return "(Sword:)" + OneHandWeapon::toString();
}