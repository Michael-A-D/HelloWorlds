#include "core.h"


abilityC::abilityC(){
    this->score = 0;
    this->name = "Name";
    this->cost = 1;
    this->value = 0;
}

abilityC::abilityC(abilityC *from){
    this->score = 0;
    this->name = from->name;
    this->cost = from->cost;
    this->value = 0;
}

attributeC::attributeC(){
    this->name = "Name";
    this->cost = 0;
    this->value = 0;
    this->isCustom = false;
}

attributeC::attributeC(attributeC *from){
    this->name = from->name;
    this->cost = from->cost;
    this->value = 0;
    this->isCustom = from->isCustom;
    foreach(abilityC *from_ability, from->abilityList){
        abilityC *ability = new abilityC(from_ability);
        this->abilityList.push_back(ability);
    }
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

characterC::characterC(characterC *from){
    this->name = "Name";
    this->description = "description";
    this->hp = from->hp;
    this->dmg = from->dmg;
    this->hpCost = from->hpCost;
    this->dmgCost = from->dmgCost;
    this->fileName = "";
    this->NPC = false;
    foreach(attributeC *from_attribute, from->attributeList){
        attributeC *attribute = new attributeC(from_attribute);
        this->attributeList.push_back(attribute);
    }
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
    score += hpCost * hp* (hp + 1) / 2 + dmgCost * dmg * (dmg + 1) / 2;
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
