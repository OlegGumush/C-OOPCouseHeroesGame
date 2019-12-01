#include "Potion.h"

/*
Constractor
*/
Potion::Potion(const size_t x, const size_t y, const EPotion type, const double amount)
	:Item(x,y,POTION) , type(type) , amount(amount)
{}


/*
Distractor
*/
Potion::~Potion() {
}

/*
getters
*/
const EPotion& Potion::getType() const{
	return type;
}
const double& Potion::getAmount() const{
	return amount;
}

/*
toString
*/
string Potion::toString() const {
	return "(Potion:)(HealthAmount:" + to_string(this->amount) + ")" + Item::toString();
}