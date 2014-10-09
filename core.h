#ifndef CORE_H
#define CORE_H
#include "QString"
#include "QList"
#include "QLabel"

class abilityC{
public:
    abilityC();
    QString name;
    int cost;
    int value;
    int score;
    QLabel* total;
    void updateValue(int newValue);
    };

class attributeC{
public:
    attributeC();
    QString name;
    int cost;
    int value;
    QList<abilityC*> abilityList;
    int score();
    int calculatedCost();
    };

class characterC{
public:
    characterC();
    QString name;
    QString description;
    bool NPC;
    int hp;
    int dmg;
    int hpCost;
    int dmgCost;
    QList<attributeC*> attributeList;
    int score();
    QString overview();
};


class core
{
public:
    core();
};

#endif // CORE_H
