#pragma once
#include "Weapon.h"
#include "Enums.h"

class TwoHandWeapon : public Weapon {
public:
	/*
	Constractor
	*/
	TwoHandWeapon(const size_t x, const size_t y,const EWeapon weaponName ,const double power);
	/*
	Distractor
	*/
	virtual ~TwoHandWeapon() =0;
	/*
	to String
	*/	
	virtual string toString() const;

};