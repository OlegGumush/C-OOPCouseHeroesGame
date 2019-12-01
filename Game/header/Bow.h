#pragma once
#include "TwoHandWeapon.h"

class Bow : public TwoHandWeapon {
public:
	/*
	Constructor
	*/
	Bow(const size_t x, const  size_t y, const  EWeapon weaponName, const double attackAmount);
	/*
	Distructor
	*/
	virtual ~Bow();
	/*
	to string
	*/
	virtual string toString() const;
};