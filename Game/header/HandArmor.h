#pragma once
#include "Armor.h"

class HandArmor : public Armor {
public:

	/*
	Constractor
	*/
	HandArmor(const size_t x, const  size_t y, const  double amountDefence, const  EArmor armorKind);
	/*
	Distractor
	*/
	virtual ~HandArmor();
	/*
	To string
	*/
	virtual string toString() const;

};