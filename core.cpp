#include "core.h"


abilityC::abilityC(){
    this->score = 0;
    this->name = "Name";
    this->cost = 1;
    this->value = 0;
}

attributeC::attributeC(){
    this->name = "Name";
    this->cost = 0;
    this->value = 0;
}

characterC::characterC(){
    this->name = "Name";
    this->description = "description";
}

int attributeC::score(){
    int score = 0;
    for(int i=0; i<this->abilityList.length(); i++)
        score += this->abilityList.at(i)->score;
    score += this->value * this->cost;
    return score;
}

int attributeC::calculatedCost(){
    int cost = 0;
    for(int i=0; i<this->abilityList.length(); i++)
        cost += this->abilityList.at(i)->cost;
    return cost;
}

int characterC::score(){
    int score = 0;
    for(int i=0; i<this->attributeList.length(); i++)
        score += this->attributeList.at(i)->score();
    return score;
}

void abilityC::updateValue(int newValue){
    this->score = newValue * (newValue +1) / 2 * this->cost;
    this->value = newValue;
}

core::core()
{
}
