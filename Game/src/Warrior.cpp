#include "Warrior.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
#include <cmath>

/*
Constractor
*/
Warrior::Warrior(const double power, const size_t x1, const size_t y1, const size_t x2, const size_t y2, const ECharacter name, const EGender gender)
	:Hero(power, x1, y1, x2, y2, name, gender, GLOB_WARRIOR_RADIUS)
{}

/*
Distractor
*/
Warrior::~Warrior() {
	//~Hero virtual 
}

/*
toString
*/
string Warrior::toString() const {
	return "(Warrior:)" + Hero::toString();
}

/*
Get a general item and by type send to parent function use .
*/
bool Warrior::use(Item* const item) {

	if (item->getType() == ARMOR) {
		return Hero::use(dynamic_cast<Armor*>(item));
	}
	else if (item->getType() == WEAPON ){
		Weapon * w = dynamic_cast<Weapon*>(item);
		
		if(w->getWeaponName() == SWORD || w->getWeaponName() == HAMMER){
			return Hero::use(w);
		}
	}
	else if (item->getType() == POTION) {
		
		Potion * p = dynamic_cast<Potion*>(item);
		if(p->getType() == LIFE){
			return Hero::use(p);
		}
	}
	return false;
}