#pragma once

#include "TwoHandWeapon.h"

class Staff : public TwoHandWeapon {
public:
	/*
	Constractor
	*/
	Staff(const size_t x, const size_t y, const EWeapon weaponName, const double power);
	/*
	Distractor
	*/
	virtual ~Staff();
	/*
	to String
	*/
	virtual string toString() const;

};