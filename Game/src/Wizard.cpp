#include "Wizard.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
/*
Constractor
*/
Wizard::Wizard(const double power, const size_t x1 ,const size_t y1, const size_t x2, const size_t y2, const ECharacter name, const EGender gender)
	:Hero(power, x1, y1, x2, y2, name, gender,GLOB_WIZARD_RADIUS)
{}

/*
Distractor
*/
Wizard::~Wizard() {}

/*
toString
*/
string Wizard::toString() const {
	return "(Wizard:)" + Hero::toString();
}

/*
Get a general item and by type send to parent function use .
*/
bool Wizard::use(Item* const item) {

	if (item->getType() == ARMOR) {
		return Hero::use((Armor*)item);
	}
	else if (item->getType() == WEAPON ){
		Weapon * w = (Weapon*)item;
	
		if(w->getWeaponName() == STAFF || w->getWeaponName() == WAND){
			return Hero::use(w);
		}
	}
	else if (item->getType() == POTION) {
		//must be mana or life no need to ask
		return Hero::use((Potion*)item);
	}
	return false;
}