#pragma once

#include "OneHandWeapon.h"

class Wand : public OneHandWeapon {
public:
	/*
	Constractor
	*/
	Wand(const size_t x, const size_t y, const EWeapon weaponName, const double power);
	/*
	Distractor
	*/
	virtual ~Wand();
	/*
	to String
	*/
	virtual string toString() const;

};