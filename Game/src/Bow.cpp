#include "Bow.h"

/*
Constructor
*/
Bow::Bow(const size_t x, const  size_t y, const  EWeapon weaponName, const double attackAmount)
	: TwoHandWeapon(x, y, weaponName, attackAmount)
{}

/*
Distructor
*/
Bow::~Bow() {}

/*
toString
*/
string Bow::toString() const {
	return "(Bow:)" + TwoHandWeapon::toString();
}