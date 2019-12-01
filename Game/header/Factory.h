#pragma once
#include "Enums.h"
#include <string>
class Item;
class Character;
using namespace std;

class Factory {

public:
	/*
	Get a line containing the size of our world get out them and builds a matrix that represents our world
	*/
	char** buildWorld(const string& line,size_t& x,size_t& y) const;
	/*
	Get a line containing the parameters of Potion get out them and builds a potion object.
	*/
	Item* buildPotion(const string& line, const string& name) const;
	/*
	Get a line containing the parameters of weapon get out them and builds a weapon object.
	*/
	Item* buildWeapon(const string& line, const string& name) const;
	/*
	Get a line containing the parameters of armor get out them and builds a armor object.
	*/
	Item* buildArmor(const string& line, const string& name) const;
	/*
	Get a line containing the parameters of enemy get out them and builds a enemy object.
	*/
	Character* buildEnemy(const string& line, const string& name)const ;	
	/*
	Get a line containing the parameters of actor get out them and builds a actor object.
	*/
	Character* buildActor(const string& line, const string& name) const;

private:
	/*
	Get a line and pointer to any place and returns the first int he sees
	*/
	size_t getIntAttribute(const string& line, size_t& i) const;
	/*
	Get a line and pointer to any place and returns the first double he sees
	*/
	double getDoubleAttribute(const string& line, size_t& i) const;
};