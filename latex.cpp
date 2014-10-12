#include "latex.h"
#include "QFile"
#include "QTextStream"
#include "QString"
#include "QObject"
#include "QProcess"
#include "stdio.h"

latex::latex()
{
}

void latex::write(characterC* characterData, QString fileName)
{
    QStringRef* fileNameReg = new QStringRef(&fileName);
    QString fileLocation = fileName.section("/",0,fileNameReg->count("/")-1);
    QString texfileName = fileName.section(".",0,fileNameReg->count(".")-1) + QObject::tr(".tex");
    QFile* file = new QFile(texfileName);
    file->open(QIODevice::WriteOnly);
    QTextStream* out = new QTextStream(file);
    *out << QObject::tr("\\documentclass[a4paper]{article}\\pagenumbering{gobble}\\usepackage[utf8]{inputenc}\\usepackage{LobsterTwo}\\usepackage{tabularx}\\usepackage{graphicx}\\usepackage{multirow}\\usepackage{titlesec}\\usepackage{multicol}\\usepackage[inner=0.5cm,outer=1cm]{geometry}\\newcommand{\\attribute}[2]{\\section*{#1: #2}}\\newcommand{\\ability}[4]{{\\Large{\\bf #1:} #2 + #3 = #4\\\\}}\\newcommand{\\general}[5]{\\vspace*{-4cm}\\section*{General}\\begin{tabular}{l|p{4cm}|p{8cm}|}\\cline{2-3}\\multirow{4}{*}{\\includegraphics[height=4cm]{#5}} &&\\\\&\\Huge{\\bf #1}&\\Huge{\\bf Inventory}\\\\&\\LARGE{#2} &\\\\&& \\\\&\\LARGE{{\\bf HP:} \\ \\ \\ \\ \\ / #3}&\\\\&& \\\\&\\LARGE{{\\bf DMG:} #4x}&\\\\\\cline{2-3}\\end{tabular}}\\titleformat*{\\section}{\\Huge\\bfseries}\\begin{document}");
    QString latexDelimiter = QObject::tr("}{");
    QString latexLine = QObject::tr("}\n");
    QString beginCol = QObject::tr("\\begin{multicols}{2}\\setlength{\\parindent}{0em}\n");
    QString endCol = QObject::tr("\\end{multicols}\n");
    *out <<
            (
                QObject::tr("\\general{") +
                characterData->name +
                latexDelimiter +
                characterData->description +
                latexDelimiter +
                QString::number(characterData->hp) +
                latexDelimiter +
                QString::number(characterData->dmg) +
                latexDelimiter +
                characterData->avatar +
                latexLine
            );
    foreach(attributeC* attribute,characterData->attributeList)
    {
        *out <<
                (QObject::tr("\\attribute{") +
                 attribute->name +
                 latexDelimiter +
                 QString::number(attribute->value) +
                 latexLine +
                 beginCol
                 );

        foreach(abilityC* ability,attribute->abilityList)
        {
            *out <<
                    (QObject::tr("\\ability{") +
                     ability->name +
                     latexDelimiter +
                     QString::number(ability->value) +
                     latexDelimiter +
                     QString::number(attribute->value) +
                     latexDelimiter +
                     QString::number(ability->value + attribute->value) +
                     latexLine
                     );
        }
        *out << endCol;
    }
    *out << QObject::tr("\\end{document}");
    file->close();
    QString command = QObject::tr("cd ") + fileLocation + QObject::tr(";pdflatex ") + texfileName;
    system(command.toUtf8().constData());
}
