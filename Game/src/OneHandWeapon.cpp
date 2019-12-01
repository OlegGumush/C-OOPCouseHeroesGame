#include "OneHandWeapon.h"

/*
Constructor
*/
OneHandWeapon::OneHandWeapon(const size_t x, const size_t y, const EWeapon weaponName, const double power)
	:Weapon(x,y,weaponName ,ONE_HAND, power* GLOB_ONE_HAND_WEAPON_POWER)
{}

/*
Distructor
*/
OneHandWeapon::~OneHandWeapon() {}

/*
toString
*/
string OneHandWeapon::toString() const {
	return "(OneHandWeapon:)(WeaponPower:" + to_string(GLOB_ONE_HAND_WEAPON_POWER) + ")" + Weapon::toString();
}