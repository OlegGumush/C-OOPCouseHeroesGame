#include "Staff.h"

/*
Constractor
*/
Staff::Staff(const size_t x, const size_t y, const EWeapon weaponName, const double power)
	: TwoHandWeapon(x, y, weaponName, power)
{}

/*
Distractor
*/
Staff::~Staff() {}

/*
toString
*/
string Staff::toString() const {
	return "(Staff:)" + TwoHandWeapon::toString();
}