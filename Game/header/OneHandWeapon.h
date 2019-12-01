#pragma once
#include "Weapon.h"
#include "Enums.h"

class OneHandWeapon : public Weapon {
public:
	/*
	Constructor
	*/
	OneHandWeapon(const size_t x, const size_t y, const EWeapon weaponName , const double power);
	/*
	Distructor
	*/
	virtual ~OneHandWeapon() =0;
	/*
	to String
	*/
	virtual string toString() const;

};