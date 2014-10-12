#ifndef XML_H
#define XML_H
#include <core.h>
#include <QtXml>
#include <QObject>

class characterLoader
{
public:
    characterLoader();
    ~characterLoader();
    bool load(characterC* character, QString fileName);
private:
    QXmlStreamReader* reader;
};

class characterWriter
{
public:
    characterWriter();
    ~characterWriter();
    void write(characterC* character, QString fileName);
private:
    QXmlStreamWriter* writer;
};

class worldLoader
{
public:
    worldLoader();
    ~worldLoader();
    bool load(worldC* character, QString fileName);
private:
    QXmlStreamReader* reader;
};

class worldWriter
{
public:
    worldWriter();
    ~worldWriter();
    void write(worldC* world, QString fileName);
private:
    QXmlStreamWriter* writer;
};


#endif // XML_H
