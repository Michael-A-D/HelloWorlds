#include "xml.h"
#include "iostream"

characterLoader::characterLoader()
{
    this->reader = new QXmlStreamReader();
}

characterLoader::~characterLoader()
{
}

void characterLoader::load(characterC *character, QString fileName){
    QFile* file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    this->reader->setDevice(file);

    while (!this->reader->atEnd())
    {
        this->reader->readNext();
        std::cout << reader->attributes().size()<< std::endl;
    }
}

characterWriter::characterWriter()
{
    this->writer = new QXmlStreamWriter();
}

characterWriter::~characterWriter()
{
}

void characterWriter::write(characterC *character, QString fileName){
    QFile* file = new QFile(fileName);
    file->open(QIODevice::WriteOnly);
    this->writer->setDevice(file);

    this->writer->writeStartDocument();
    this->writer->writeStartElement(QObject::tr("character"));
    this->writer->writeAttribute("Name",character->name);
    this->writer->writeAttribute("Description",character->description);
    if (character->NPC)
    {
        this->writer->writeAttribute("NPC","1");
    }
    else
    {
        this->writer->writeAttribute("NPC","0");
    }
    this->writer->writeAttribute("HP",QString::number(character->hp));
    this->writer->writeAttribute("DMG",QString::number(character->dmg));
    this->writer->writeAttribute("HPCost",QString::number(character->hpCost));
    this->writer->writeAttribute("DMGCost",QString::number(character->dmgCost));
    this->writer->writeAttribute("avatar",character->avatar);
    for(int i = 0; i < character->attributeList.size(); i++)
    {
        this->writer->writeStartElement(QObject::tr("attribute"));
        this->writer->writeAttribute("AttName",character->attributeList.at(i)->name);
        this->writer->writeAttribute("AttValue",QString::number(character->attributeList.at(i)->value));
        if (character->attributeList.at(i)->isCustom)
            this->writer->writeAttribute("AttCustom",QString::number(character->attributeList.at(i)->cost));

        for (int j = 0; j < character->attributeList.at(i)->abilityList.size(); j++)
        {
            this->writer->writeStartElement(QObject::tr("ability"));
            this->writer->writeAttribute("AbiName",character->attributeList.at(i)->abilityList.at(j)->name);
            this->writer->writeAttribute("AbiCost",QString::number(character->attributeList.at(i)->abilityList.at(j)->cost));
            this->writer->writeAttribute("AbiValue",QString::number(character->attributeList.at(i)->abilityList.at(j)->value));
            this->writer->writeEndElement();
        }
        this->writer->writeEndElement();
    }
    this->writer->writeEndElement();
    this->writer->writeEndDocument();
    file->close();
}
