#pragma once
#include "Item.h"
#include "Enums.h"

class Weapon : public Item {
public :
	/*
	Constractor
	*/
	Weapon(const size_t x, const size_t y, const EWeapon weaponName, const EWeapon weaponKind, const double power);
	/*
	Disstractor
	*/
	virtual ~Weapon();
	/*
	to String
	*/
	virtual string toString() const;

	/*
	getters
	*/
	const double& getPower() const;
	const EWeapon& getWeaponName() const;
	const EWeapon& getNumberHands() const;

private:
	double power;
	EWeapon weaponName;
	EWeapon numberHands;

};