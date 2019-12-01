#include "TwoHandWeapon.h"

/*
Constractor
*/
TwoHandWeapon::TwoHandWeapon(const size_t x, const size_t y, const EWeapon weaponName, const double power)
	:Weapon(x, y, weaponName ,TWO_HAND ,  power*GLOB_TWO_HAND_WEAPON_POWER)
{}

/*
Distractor
*/
TwoHandWeapon::~TwoHandWeapon() {}

/*
toString
*/
string TwoHandWeapon::toString() const {
	return "(TwoHand:)(WeaponPower:" + to_string(GLOB_TWO_HAND_WEAPON_POWER) + ")" + Weapon::toString();
}