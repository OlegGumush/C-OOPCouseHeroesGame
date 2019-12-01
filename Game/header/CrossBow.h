#pragma once

#include "OneHandWeapon.h"

class CrossBow : public OneHandWeapon
{
public:
	/*
	Constractor
	*/
	CrossBow(const size_t x, const  size_t y, const  EWeapon weaponName, const  double powerAmount);
	/*
	Constractor
	*/
	virtual ~CrossBow();
	/*
	to string
	*/
	virtual string toString() const;

};