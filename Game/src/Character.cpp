#include "Character.h"
#include "Point2d.h"

/*
Constractor
*/
Character::Character(const double powerAmount, const ECharacter characterType, const size_t x1, const size_t y1 , const size_t x2, const size_t y2)
	:lifeAmount(GLOB_AMOUNT_OF_LIFE) , totalPower(powerAmount) , totalDefence(GLOB_AMOUNT_OF_START_DEFENCE), characterType(characterType),gameState(ALIVE), powerAmount(powerAmount)
{
	locationStart = new Point2d(x1,y1);
	locationEnd = new Point2d(x2,y2);
}

/*
Distractor
*/
Character::~Character(){
	delete this->locationStart;	
	delete this->locationEnd;
}

/*
get amount of damage and lowers my life.
User shields for minimize the damage.
*/
void Character::damage(const double damage) {
	
	//life -= (50 * 1) || (50 * 2)
	this->lifeAmount -= damage * this->totalDefence;

	if (this->lifeAmount <= 0) {
		this->gameState = DEAD;
	}
}

/*
getters
*/
const ECharacter& Character::getCharacterType()  const {
	return characterType;
}
const EModeOfLife& Character::getGameState()  const {
	return gameState;
}
Point2d* const Character::getLocationStart() const  {
	return locationStart;
}
Point2d* const Character::getLocationEnd() const  {
	return locationEnd;
}
const double& Character::getLifeAmount()  const {
	return lifeAmount;
}
const double& Character::getPowerAmount()  const {
	return powerAmount;
}

void Character::setGameState(const EModeOfLife newGameState) {
	this->gameState = newGameState;
}

/*
toString
*/
string Character::toString() const {

	return "(Health:" + to_string(this->lifeAmount) + ")(Power:" + 
		to_string(this->powerAmount) + ")(TotalPower:" + to_string(this->totalPower) + ")(TotalDefence:"
		+ to_string(this->totalDefence)
		+ ")(location:(" + to_string(this->locationStart->getX())
		+ "," + to_string(this->locationStart->getY()) + "))";
}
