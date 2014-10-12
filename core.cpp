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
    this->isCustom = false;
}

characterC::characterC(){
    this->name = "Name";
    this->description = "description";
    this->hp = 10;
    this->dmg = 2;
    this->hpCost = 15;
    this->dmgCost = 15;
    this->fileName = "";
    this->NPC = false;
}

worldC::worldC(){
    this->name = "Name";
    this->description = "description";
    this->fileName="";
}

int attributeC::score(){
    int score = 0;
    for(int i=0; i<this->abilityList.length(); i++)
        score += this->abilityList.at(i)->score;
    score += this->value * (this->value + 1) / 2 * this->cost;
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
    score += hpCost * hp + dmgCost * dmg;
    return score;
}

void abilityC::updateValue(int newValue){
    this->score = newValue * (newValue +1) / 2 * this->cost;
    this->value = newValue;
}

void abilityC::updateTotal(const QString newTotal){
    this->total->setText(newTotal);
}

core::core()
{
}
