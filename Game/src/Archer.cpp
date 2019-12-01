#include "Archer.h"
#include "Armor.h"
#include "Weapon.h"
#include "Potion.h"
/*
Constructor
*/
Archer::Archer(const double power, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2, const  ECharacter name, const  EGender gender) :
	Hero(power, x1, y1, x2, y2 ,name ,gender, GLOB_ARCHER_RADIUS)
{}

/*
Distructor
*/
Archer::~Archer() {}

/*
to String
*/
string Archer::toString() const {
	return "(Archer:)" + Hero::toString();
}


/*
Get a general item and by type send to parent function use .
*/
bool Archer::use(Item* const item) {

	if (item->getType() == ARMOR) {
		return Hero::use((Armor *)(item));
	}
	else if (item->getType() == WEAPON ){
		Weapon * w = (Weapon*)(item);
		
		if(w->getWeaponName() == BOW || w->getWeaponName() == CROSSBOW){
			return Hero::use(w);
		}
	}
	else if (item->getType() == POTION) {
		Potion * p = (Potion *)(item);
		if(p->getType() == LIFE){
			return Hero::use(p);
		}
	}
	return false;
}