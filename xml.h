#ifndef XML_H
#define XML_H
#include <core.h>
#include <QtXml>

class characterLoader
{
public:
    characterLoader();
    ~characterLoader();
    void load(characterC* character, QString fileName);
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

#endif // XML_H
