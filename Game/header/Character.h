#pragma once
#include "Enums.h"
#include <string>
class Point2d;
using namespace std;

class Character {
public:
	/*
	Constractor
	*/
	Character(const double powerAmount,const  ECharacter characterType, const  size_t x1, const  size_t y1 , const  size_t x2 , const size_t y2);
	/*
	Distractor
	*/
	virtual ~Character();
	/*
	to string
	*/
	virtual string toString() const ;

	/*
	Get amount of damage and lowers my life.
	Use shields for minimize the damage.
	*/
	virtual void damage(const double damage);
	
	/*
	get a character(enemy) and start attack each other until someone die
	*/
	virtual void attack(Character* character) = 0;

	/*
	getters
	*/
	const ECharacter& getCharacterType() const ;
	const EModeOfLife& getGameState() const ;
	Point2d* const getLocationStart() const ;
	Point2d* const getLocationEnd() const ;
	const double& getLifeAmount() const ;
	const double& getPowerAmount() const ;


protected:
	double lifeAmount;
	double totalPower;
	double totalDefence ;
	void setGameState(const EModeOfLife newGameState);

private:
	ECharacter characterType;
	EModeOfLife gameState;
	Point2d* locationStart;
	Point2d* locationEnd;
	const double powerAmount ;
};