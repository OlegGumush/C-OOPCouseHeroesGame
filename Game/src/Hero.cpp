#include "Hero.h"
#include "HandArmor.h"
#include "BodyArmor.h"
#include "Potion.h"
#include "OneHandWeapon.h"
#include "TwoHandWeapon.h"
#include "SearchConclusion.h"
#include <iostream>
using namespace std;
/*
Constructor
*/
Hero::Hero(const double power, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2, const  ECharacter characterType, const  EGender gender, const double radius) :
	Character(power, characterType, x1, y1 , x2,y2), radius(radius), handArmor(nullptr), bodyArmor(nullptr)  , weapon(nullptr) , gender(gender)
{}



/*
Distructor
*/
Hero::~Hero() {}


/*
Attack enemy
*/
void Hero::attack(Character* const character) {

	//Loop runs until one dead
	while (character->getLifeAmount() > 0 && this->lifeAmount> 0) {
		//Hero attacking enemy 
		character->damage(this->totalPower);
		//Enemy attacking hero
		character->attack(this);
		//Attack together!!!
	}
}

/*
get destination point and move in the best way to the destination
*/
void Hero::move(const size_t& x,const size_t& y ,const size_t& worldSizeX,const size_t& worldSizeY) {
	//reference to original point 
	size_t i = getLocationStart()->getX();
	size_t j = getLocationStart()->getY();

	if (x>i && y>j) {
		i++; j++;
	}
	else if (x<i && y<j) {
		i--; j--;
	}
	else if (x<i && y>j) {
		i--; j++;
	}
	else if (x>i && y<j) {
		i++; j--;
	}
	else if (x==i && y>j) {
		j++;
	}
	else if (x==i && y<j) {
		j--;
	}
	else if (x<i && y==j) {
		i--;
	}
	else {
		i++;
	}
	
	bool finish = false;
	
	if(i <0) {i=0;finish=true;}
	if(j <0) {j=0;finish=true;}
	if(i >= worldSizeX) {i=worldSizeX-1;finish=true;}
	if(j >= worldSizeY) {j=worldSizeY-1;finish=true;}

	getLocationStart()->setX(i);
	getLocationStart()->setY(j);
	
	//I arrived to the destination
	if (finish || (i == getLocationEnd()->getX() && j == getLocationEnd()->getY())) {
		setGameState(FINISH);
	}
}

/*
update total power my power * weapon power
*/
void Hero::updateTotalPower(double newPower) {
	this->totalPower = newPower;
}

/*
update total defence
*/
void Hero::updateTotalDefence(double newTotalDefence) {
	this->totalDefence = newTotalDefence;
}


/*
Find life or mana ,add myself to the quantity of life .
*/
bool Hero::use(Potion* const potion) {
	
	if (potion == nullptr) {
		return false;
	}

	//if my life full
	if (this->lifeAmount == GLOB_MAX_LIFE) {
		return false;
	}
	
	this->lifeAmount += potion->getAmount();
	if (this->lifeAmount > GLOB_MAX_LIFE) {
		this->lifeAmount = GLOB_MAX_LIFE;
	}	

	return true;
}

/*
find armor and decide whether to take it myself or not.
*/
bool Hero::use(Armor* const armor) {
	if (armor == nullptr) {
		return false;
	}
	
	if(armor->getArmorKind() == BODY_ARMOR ) {
		return decideIfLiftBodyArmor(armor);
	}
	else if(armor->getArmorKind() == SHIELD_ARMOR) {
		return decideIfLiftShieldArmor(armor);
	}

	//ERROR 
	return false;
}


/*
Finds weapon checks if it fits my type then decide whether take or not.
*/
bool Hero::use(Weapon* const weapon) {
	if (weapon == nullptr) {
		return false;
	}

	if (weapon->getNumberHands() == ONE_HAND) {
		return decideIfLiftOneHandWeapon(weapon);
	}
	else if (weapon->getNumberHands() == TWO_HAND) {
		return decideIfLiftTwoHandWeapon(weapon);
	}

	
	return false;
}

/*
find two hand weapon decide if get it.
*/
bool Hero::decideIfLiftTwoHandWeapon(Weapon * const weapon) {
	
	//two hands are free
	if (this->weapon == nullptr && this->handArmor == nullptr) {
		this->weapon = weapon;
		updateTotalPower(getPowerAmount() * weapon->getPower());
		return true;
	}
	//If i dont have weapon but I have one hand shield ,I'll throw the shield
	else if (this->weapon == nullptr && this->handArmor != nullptr) {
		this->weapon = weapon;
		updateTotalDefence(this->totalDefence / this->handArmor->getDefenceAmount());
		this->handArmor = nullptr;
		updateTotalPower(getPowerAmount()*weapon->getPower());
		return true;
	}
	//if i dont have a shield but have weapon i am replace (At worst case i threw weapon with two hands and I took it again)
	else if (this->weapon != nullptr && this->handArmor == nullptr) {
		//not matter if i have one hand weapon or two
		this->weapon = weapon;
		updateTotalPower(getPowerAmount() * weapon->getPower());
		return true;
	}
	//I have one hand weapon and shield , must decide whether to throw my items and take two hand weapon
	else {
		//If my shield is weak >= 0.85 
		if (this->handArmor->getDefenceAmount() >= GLOB_SWITCH_WEAPON_SHIELD) {
			updateTotalDefence(this->totalDefence / this->handArmor->getDefenceAmount());
			this->handArmor = nullptr;
			this->weapon = weapon;
			updateTotalPower(this->getPowerAmount()*weapon->getPower());
			return true;
		}
	}

	return false;
}

/*
find one hand weapon decide if get it
*/
bool Hero::decideIfLiftOneHandWeapon(Weapon * const weapon) {
	//dont have a weapon
	if (this->weapon == nullptr) {
		this->weapon = weapon;
		updateTotalPower(getPowerAmount()*weapon->getPower());
		return true;
	}
	//If I have a one hand weapon but my weapon weaker
	else if (this->weapon->getNumberHands() == ONE_HAND) {
		if (this->weapon->getPower() < weapon->getPower()) {
			this->weapon = weapon;
			updateTotalPower(getPowerAmount()*weapon->getPower());
			return true;
		}
	}
	else {
		//i have two hande weapon do anything
	}

	return false;
}

/*
Find shield armor decide if get it
*/
bool Hero::decideIfLiftShieldArmor(Armor * const armor) {
	//If I dont have a shield
	if (this->handArmor == nullptr) {
		//if i dont have weapon or i have one hand weapon
		if (this->weapon == nullptr || this->weapon->getNumberHands() == ONE_HAND) {
			this->handArmor = armor;
			updateTotalDefence(this->totalDefence*armor->getDefenceAmount());
			return true;
		}else{
			//have two hand weapon
		}
	}
	//If i have a hand armor
	else {
		//If my hand armor is weaker
		if (this->handArmor->getDefenceAmount() > armor->getDefenceAmount()) {
			updateTotalDefence((this->totalDefence/this->handArmor->getDefenceAmount())*armor->getDefenceAmount());
			this->handArmor = armor;
			return true;
		}
	}

	return false;
}

/*
Find body armor decide if get it
*/
bool Hero::decideIfLiftBodyArmor(Armor * const armor) {
	//if i dont have body armor  or my body armor weaker
	if (this->bodyArmor == nullptr ) {
		this->bodyArmor = armor;
		updateTotalDefence(this->totalDefence*armor->getDefenceAmount());
		return true;
	}
	if (this->bodyArmor->getDefenceAmount() > armor->getDefenceAmount()) {
		updateTotalDefence((this->totalDefence/this->bodyArmor->getDefenceAmount())*armor->getDefenceAmount());
		this->bodyArmor = armor;
		return true;
	}

	return false;
}


/*
The function receives the world where hero is supposed to walk.

And returns what he saw in his radius ,return vector of SearchConclusion objects each object marks 
point of what he saw and type of object : enemy or item to know where to look for this object in game class.
*/
vector<SearchConclusion*> Hero::ScanEnviroment(char** const world , const size_t& n , const size_t& m) {

	vector<SearchConclusion*> result;
	int startX = getLocationStart()->getX() - (size_t)radius;
	int endX = getLocationStart()->getX() + (size_t)radius;
	int startY = getLocationStart()->getY() - (size_t)radius;
	int endY = getLocationStart()->getY() + (size_t)radius;

	for (int i = startX; i <= endX; i++)
	{
		for (int j = startY ; j <= endY ; j++)
		{
			//if(this->getLocationStart()){continue;}
			if(this->getLocationStart()->distance(i,j) > radius) {continue;}
				
			//If the point not in the range
			if (i < 0 || i >= (int)n || j < 0 || j >= (int)m)   {continue;}

			if (world[i][j] == GLOB_ENEMY || world[i][j] == GLOB_ELITE) {
				result.push_back(new SearchConclusion(i, j, GLOB_ENEMY));
			}
			else if (world[i][j] == GLOB_POTION || world[i][j] == GLOB_ARMOR || world[i][j] == GLOB_WEAPON) {
				result.push_back(new SearchConclusion(i, j, GLOB_ITEM));
			}
		}
	}
	return result;
}

/*
getters
*/
const EGender& Hero::getGenger() const{
	return gender;
}
Armor* const Hero::getHandArmor() const{
	return handArmor;
}
Armor* const Hero::getBodyArmor()const {
	return bodyArmor;
}
Weapon* const Hero::getWeapon()const {
	return weapon;
}

/*
toString
*/
string Hero::toString() const {
	return "(Hero:)" + Character::toString();
}

