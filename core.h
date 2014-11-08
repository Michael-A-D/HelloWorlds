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
    void updateTotal(const QString newTotal);
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
    bool isCustom;
    };

class characterC{
public:
    characterC();
    characterC(characterC *);
    QString name;
    QString description;
    bool NPC;
    int hp;
    int dmg;
    int hpCost;
    int dmgCost;
    QString avatar;
    QList<attributeC*> attributeList;
    int score();
    QString overview();
    QString fileName;
};

class worldC{
public:
    worldC();
    QString name;
    QString description;
    QList<characterC*> characterList;
    QString fileName;
};


class core
{
public:
    core();
};

#endif // CORE_H
