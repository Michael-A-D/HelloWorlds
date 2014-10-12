#include "xml.h"
#include "QDomElement"

characterLoader::characterLoader()
{
    this->reader = new QXmlStreamReader();
}

characterLoader::~characterLoader()
{
}

bool characterLoader::load(characterC *character, QString fileName){
    bool result = false;
    QFile* file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    this->reader->setDevice(file);
    attributeC* attribute;
    abilityC* ability;

    while (!this->reader->atEnd())
    {
        this->reader->readNext();
        if (this->reader->isStartElement())
        {
            if (this->reader->name() == "character")
            {
                result = true;
                foreach(const QXmlStreamAttribute &attr,this->reader->attributes())
                {
                    if (attr.name() == "name")
                        character->name = attr.value().toString();
                    if (attr.name() == "description")
                        character->description = attr.value().toString();
                    if (attr.name() == "npc")
                        character->NPC = attr.value().toInt();
                    if (attr.name() == "hp")
                        character->hp = attr.value().toInt();
                    if (attr.name() == "dmg")
                        character->dmg = attr.value().toInt();
                    if (attr.name() == "hpcost")
                        character->hpCost = attr.value().toInt();
                    if (attr.name() == "dmgcost")
                        character->dmgCost = attr.value().toInt();
                    if (attr.name() == "avatar")
                        character->avatar = attr.value().toString();
                }
            }
            if (this->reader->name() == "attribute")
            {
                attribute = new attributeC();
                character->attributeList.push_back(attribute);
                foreach(const QXmlStreamAttribute &attr,this->reader->attributes())
                {
                    if (attr.name() == "attname")
                        attribute->name = attr.value().toString();
                    if (attr.name() == "attvalue")
                        attribute->value = attr.value().toInt();
                    if (attr.name() == "attcustom")
                    {
                        attribute->isCustom = true;
                        attribute->cost = attr.value().toInt();
                    }
                }
            }
            if (this->reader->name() == "ability")
            {
                ability = new abilityC();
                attribute->abilityList.push_back(ability);
                foreach(const QXmlStreamAttribute &attr,this->reader->attributes())
                {
                    if (attr.name() == "abiname")
                        ability->name = attr.value().toString();
                    if (attr.name() == "abivalue")
                        ability->value = attr.value().toInt();
                    if (attr.name() == "abicost")
                        ability->cost = attr.value().toInt();
                }
            }
        }
    }
    return result;
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
    this->writer->writeAttribute("name",character->name);
    this->writer->writeAttribute("description",character->description);
    if (character->NPC)
    {
        this->writer->writeAttribute("npc","1");
    }
    else
    {
        this->writer->writeAttribute("npc","0");
    }
    this->writer->writeAttribute("hp",QString::number(character->hp));
    this->writer->writeAttribute("dmg",QString::number(character->dmg));
    this->writer->writeAttribute("hpcost",QString::number(character->hpCost));
    this->writer->writeAttribute("dmgcost",QString::number(character->dmgCost));
    this->writer->writeAttribute("avatar",character->avatar);
    for(int i = 0; i < character->attributeList.size(); i++)
    {
        this->writer->writeStartElement(QObject::tr("attribute"));
        this->writer->writeAttribute("attname",character->attributeList.at(i)->name);
        this->writer->writeAttribute("attvalue",QString::number(character->attributeList.at(i)->value));
        if (character->attributeList.at(i)->isCustom)
            this->writer->writeAttribute("attcustom",QString::number(character->attributeList.at(i)->cost));

        for (int j = 0; j < character->attributeList.at(i)->abilityList.size(); j++)
        {
            this->writer->writeStartElement(QObject::tr("ability"));
            this->writer->writeAttribute("abiname",character->attributeList.at(i)->abilityList.at(j)->name);
            this->writer->writeAttribute("abicost",QString::number(character->attributeList.at(i)->abilityList.at(j)->cost));
            this->writer->writeAttribute("abivalue",QString::number(character->attributeList.at(i)->abilityList.at(j)->value));
            this->writer->writeEndElement();
        }
        this->writer->writeEndElement();
    }
    this->writer->writeEndElement();
    this->writer->writeEndDocument();
    file->close();
}

worldLoader::worldLoader()
{
    this->reader = new QXmlStreamReader();
}

worldLoader::~worldLoader()
{
}

bool worldLoader::load(worldC *world, QString fileName)
{
    bool result = false;
    QFile* file = new QFile(fileName);
    file->open(QIODevice::ReadOnly);
    this->reader->setDevice(file);

    while (!this->reader->atEnd())
    {
        this->reader->readNext();
        if (this->reader->isStartElement()){
            if (this->reader->name() == "world")
            {
                result = true;
                foreach(const QXmlStreamAttribute &attr,this->reader->attributes())
                {
                    if (attr.name() == "name")
                        world->name = attr.value().toString();
                    if (attr.name() == "description")
                        world->description = attr.value().toString();
                }
            }
            if (this->reader->name() == "character")
            {
                characterC* characterData = new characterC();
                foreach(const QXmlStreamAttribute &attr,this->reader->attributes())
                {
                    if (attr.name() == "filename")
                    {
                        characterLoader* loader = new characterLoader();
                        loader->load(characterData,attr.value().toString());
                        delete loader;
                        world->characterList.push_back(characterData);
                    }
                }
            }
        }
    }
    return result;
}

worldWriter::worldWriter()
{
    this->writer = new QXmlStreamWriter();
}

worldWriter::~worldWriter()
{
}

void worldWriter::write(worldC *world, QString fileName){
    QFile* file = new QFile(fileName);
    file->open(QIODevice::WriteOnly);
    this->writer->setDevice(file);

    this->writer->writeStartDocument();
    this->writer->writeStartElement(QObject::tr("world"));
    this->writer->writeAttribute("name",world->name);
    this->writer->writeAttribute("description",world->description);
    for(int i = 0; i < world->characterList.size(); i++)
    {
        this->writer->writeStartElement(QObject::tr("character"));
        characterWriter* writerC = new characterWriter();
        QString characterFileName = fileName + QString::number(i);
        writerC->write(world->characterList.at(i),characterFileName);
        this->writer->writeAttribute("filename",characterFileName);
        delete writerC;
        this->writer->writeEndElement();
    }
    this->writer->writeEndDocument();
    file->close();
}
