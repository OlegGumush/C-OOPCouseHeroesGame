#pragma once
#include "Item.h"
#include "Enums.h"

class Armor : public Item {
public:
	/*
	Constractor
	*/
	Armor(const size_t x, const  size_t y, const  double defenceAmount , const  EArmor armorKind);

	/*
	Distractor
	*/
	virtual ~Armor() = 0;
	
	/*
	getters
	*/
	const EArmor& getArmorKind() const;
	const double& getDefenceAmount() const;

	/*
	to String
	*/
	virtual string toString() const ;
private:
	
	//defence amount of armor
	double defenceAmount;
	//armor kind body or shield
	EArmor armorKind;
};