#pragma once

#include "TwoHandWeapon.h"

class Hammer : public TwoHandWeapon {
public:
	/*
	Constractor
	*/
	Hammer(const size_t x , const   size_t y, const   EWeapon weaponName, const   double power);
	/*
	Distractor
	*/
	virtual ~Hammer();
	/*
	Tostring
	*/
	virtual string toString() const;

};