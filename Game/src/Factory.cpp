#include "Factory.h"
#include "Hammer.h"
#include "Bow.h"
#include "CrossBow.h"
#include "Staff.h"
#include "Wand.h"
#include "Sword.h"
#include "BodyArmor.h"
#include "HandArmor.h"
#include "Archer.h"
#include "Wizard.h"
#include "Warrior.h"
#include "OneHandWeapon.h"
#include "TwoHandWeapon.h"
#include "Potion.h"
#include "Elite.h"
#include <stdlib.h>

/*
Get a line and pointer to any place and returns the first int he sees
*/
size_t Factory::getIntAttribute(const string& line, size_t& i)  const{
	string attribute = "";
	//if not number continue promote pointer
	while (i < line.size() && (line[i] < GLOB_ZERO || line[i] > GLOB_NINE)) {
		i++;
	}
	//copy number
	while (i < line.size() && (line[i] >= GLOB_ZERO && line[i] <= GLOB_NINE)) {
		attribute += line[i++];
	}
	//convert from string to int
	return stoi(attribute);
}

/*
Get a line and pointer to any place and returns the first double he sees
*/
double Factory::getDoubleAttribute(const string& line, size_t& i) const {
	string attribute;
	//if not number continue promote pointer
	while (i < line.size() && (line[i] < GLOB_ZERO || line[i] > GLOB_NINE)) {
		i++;
	}
	//copy number
	while (i < line.size() && (line[i] == GLOB_EMPTY || (line[i] >= GLOB_ZERO && line[i] <= GLOB_NINE))) {
		attribute += line[i++];
	}
	//convert from string to double
	return atof(attribute.c_str());
}

/*
Get a line containing the size of our world get out them and builds a matrix that represents our world
*/
char** Factory::buildWorld(const string& line ,size_t& x ,size_t& y)  const{
	char ** world;

	size_t i = 0;
	//get size
	x = getIntAttribute(line, i);
	y = getIntAttribute(line, i);

	world = new char*[x];
	for (size_t i = 0; i < x; i++)
	{
		world[i] = new char[y];
	}

	//return matrix x*y size
	return world;
}

/*
Get a line containing the parameters of Potion get out them and builds a potion object.
*/
Item* Factory::buildPotion(const string& line, const string& name) const {
	
	EPotion type = (name == "mana") ? MANA : LIFE;

	size_t i = 0;
	double amount = getDoubleAttribute(line, i);
	int x = getIntAttribute(line, i);
	int y = getIntAttribute(line, i);

	return new Potion(x, y, type, amount);
}


/*
Get a line containing the parameters of armor get out them and builds a armor object.
*/
Item* Factory::buildArmor(const string& line, const string& name) const {
	
	size_t i = 0;	
	
	double power = getDoubleAttribute(line, i);
	int x = getIntAttribute(line, i);
	int y = getIntAttribute(line, i);

	if (name == "bodyArmor") {
		return new BodyArmor(x,y,power,BODY_ARMOR);
	}
	else if(name == "shieldArmor"){
		return new HandArmor(x, y,power ,SHIELD_ARMOR);
	}

	return nullptr;
}

/*
Get a line containing the parameters of actor get out them and builds a actor object.
*/
Character* Factory::buildActor(const string& line, const string& name) const {
	size_t i = 0;

	double power = getDoubleAttribute(line, i);
	size_t x1 = getIntAttribute(line, i);
	size_t y1 = getIntAttribute(line, i);
	size_t x2 = getIntAttribute(line, i);
	size_t y2 = getIntAttribute(line, i);
	size_t gender = getIntAttribute(line, i);

	EGender Egender = (gender == 0) ? FEMALE : MALE;

	if (name == "archer") {
		return new Archer(power, x1, y1, x2, y2, ARCHER, Egender);
	}
	else if (name == "wizard") {
		return new Wizard(power, x1, y1, x2, y2, WIZARD, Egender);
	}
	else if (name == "warrior") {
		return new Warrior(power, x1, y1, x2, y2, WARRIOR, Egender);
	}

	return nullptr;
}

/*
Get a line containing the parameters of enemy get out them and builds a enemy object.
*/
Character* Factory::buildEnemy(const string& line, const string& name) const {

	size_t i = 0;
	double power = getDoubleAttribute(line, i);
	size_t x1 = getIntAttribute(line, i);
	size_t y1 = getIntAttribute(line, i);
	size_t x2 = getIntAttribute(line, i);
	size_t y2 = getIntAttribute(line, i);

	if (name == "enemy") {
		return new Enemy(power,ENEMY, x1, y1, x2, y2);
	}
	else if(name == "elite"){
		return new Elite(power,ELITE, x1, y1, x2, y2);
	}

	return nullptr;
}

/*
Get a line containing the parameters of weapon get out them and builds a weapon object.
*/
Item* Factory::buildWeapon(const string& line, const string& name) const {
	size_t i = 0;	
	
	double power = getDoubleAttribute(line, i);
	size_t x = getIntAttribute(line, i);
	size_t y = getIntAttribute(line, i);

	if (name == "hammer") {
		return new Hammer(x, y, HAMMER , power);
	}
	else if (name == "bow") {
		return new Bow(x, y, BOW, power);
	}
	else if (name == "staff") {
		return new Staff(x, y, STAFF, power);
	}
	else if (name == "sword") {
		return new Sword(x, y, SWORD, power);
	}
	else if (name == "crossbow") {
		return new CrossBow(x, y, CROSSBOW, power);
	}
	else if (name == "wand") {
		return new Wand(x, y, WAND, power);
	}

	return nullptr;
}