#include "Enemy.h"

/*
Constructor
*/
Enemy::Enemy(const double powerAmount, const ECharacter characterTypes, const  size_t x1, const  size_t y1, const  size_t x2, const  size_t y2)
	: Character(powerAmount, characterTypes, x1, y1, x2, y2)
{}

/*
Distractor
*/
Enemy::~Enemy() {}


/*
attack() and damage() functions Writtened in assumption that can be a future enemys with a shields and weapons
*/

/*
attack hero
*/
void Enemy::attack(Character* character)  {
	character->damage(this->totalPower);
}

string Enemy::toString() const {
	return "(Enemy:)" + Character::toString();
}