#include "Hammer.h"

/*
Constractor
*/
Hammer::Hammer(const  size_t x, const  size_t y, const  EWeapon weaponName, const   double power)
	: TwoHandWeapon(x,y,weaponName,power)
{}

/*
Distractor
*/
Hammer::~Hammer() {}

/*
ToString
*/
string Hammer::toString() const {
	return "(Hammer:)" + TwoHandWeapon::toString();
}