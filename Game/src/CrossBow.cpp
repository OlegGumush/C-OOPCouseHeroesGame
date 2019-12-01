#include "CrossBow.h"

/*
Constractor
*/
CrossBow::CrossBow(const size_t x, const  size_t y, const  EWeapon weaponName, const  double powerAmount)
	: OneHandWeapon(x, y, weaponName, powerAmount)
{}

/*
Distractor
*/
CrossBow::~CrossBow() {}

/*
toString
*/
string CrossBow::toString() const {
	return "(CrossBow:)" + OneHandWeapon::toString();
}