#pragma once
#include <vector>
#include "Armor.h"
#include "Weapon.h"
#include "Character.h"

class Potion;
class SearchConclusion;

class Hero : public Character {
public :
	/*
	Constructor
	*/
	Hero(const double power, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2, const  ECharacter characterType, const  EGender gender ,  const double radius);
	/*
	Distructor
	*/
	virtual ~Hero();
	
	double const radius;
	/*
	get character(enemy) and attack enemy
	*/
	virtual void attack(Character* const character);
	/*
	get destination point and move in the best way to the destination , and world size
	*/
	virtual void move(const size_t& x,const size_t& y ,const size_t& worldSizeX,const size_t& worldSizeY);
	/*
	abstruct 
	*/
	virtual bool use(Item* const item)=0;
	/*
	toString
	*/
	virtual string toString() const;
	/*
	The function receives the world where hero is supposed to walk.
	
	And returns what he saw in his radius ,return vector of SearchConclusion objects each object marks 
	point of what he saw and type of object : enemy or item to know where to look for this object in game class.
	*/
	virtual vector<SearchConclusion*> ScanEnviroment(char** const world, const size_t& n, const size_t& m);
	/*
	getters
	*/
	const EGender& getGenger() const;
	Armor* const getHandArmor() const;
	Armor* const getBodyArmor() const;
	Weapon* const getWeapon() const;

protected:
	/*
	update total power my power * weapon power
	*/
	void updateTotalPower(const double newPower);
	/*
	update total defence
	*/	
	void updateTotalDefence(const double newTotalDefence);
	/*
	Finds weapon checks if it fits my type then decide whether take or not.
	*/
	bool use(Weapon* const weapon);
	/*
	find armor and decide whether to take it myself or not.
	*/
	bool use(Armor* const armor);
	/*
	Find life or mana ,add myself to the quantity of life .
	Only a wizard could drink the mana
	*/
	bool use(Potion* const potion);
	Armor* handArmor;
	Armor* bodyArmor;
	Weapon* weapon;

private:	
	EGender gender;
	/*
	find one hand weapon decide if get it.
	*/
	bool decideIfLiftOneHandWeapon(Weapon * const weapon);
	/*
	find two hand weapon decide if get it.
	*/
	bool decideIfLiftTwoHandWeapon( Weapon * const weapon);
	/*
	Find shield armor decide if get it
	*/
	bool decideIfLiftShieldArmor(Armor * const armor);
	/*
	Find body armor decide if get it
	*/
	bool decideIfLiftBodyArmor(Armor * const armor);
};