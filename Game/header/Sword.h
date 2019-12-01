#pragma once
#include "OneHandWeapon.h"

class Sword : public OneHandWeapon {
public:
	/*
	Constractor
	*/
	Sword(const size_t x, const size_t y, const EWeapon weaponName, const double power);
	/*
	Distractor
	*/
	virtual ~Sword();
	/*
	to String
	*/
	virtual string toString() const;

};