#include "Wand.h"

/*
Constractor
*/
Wand::Wand(const size_t x, const size_t y, const EWeapon weaponName, const double power)
	: OneHandWeapon(x, y, weaponName, power)
{}

/*
Distractor
*/
Wand::~Wand() {}

/*
toString
*/
string Wand::toString() const {
	return "(Wand:)" + OneHandWeapon::toString();
}