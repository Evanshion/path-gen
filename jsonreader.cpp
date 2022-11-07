#include "mainwindow.h"
#include "jsonreader.h"



using namespace std;




QJsonDocument readJson(QString path)
   {
      QString val;
      QFile file;
      file.setFileName(path);
      //file.setFileName("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/PSRD-Data-release/core_rulebook/class/core/sorcerer.json");
      file.open(QIODevice::ReadOnly | QIODevice::Text);
      val = file.readAll();
      file.close();
      QJsonParseError parseError;
      QJsonDocument d = QJsonDocument::fromJson(val.toUtf8(), &parseError);
      // Fail if the JSON is invalid.
          if (parseError.error != QJsonParseError::NoError)
          {
              qWarning() << "Failed to parse assets index file:" << parseError.errorString()
                           << "at offset " << QString::number(parseError.offset);
          }

      return d;
   }


QJsonObject readField(QJsonDocument d){
    if (!d.isObject())
        {
            qWarning() << "Invalid assets index JSON: Root should be an array.";
        }
    QJsonObject o = d.object();
    return o;
}



void writeFile(QString path, QJsonDocument data){
    QFile file(path);
          if(file.open(QIODevice::WriteOnly | QIODevice::Text))
          {
              // We're going to streaming text to the file
              QTextStream stream(&file);
              //qDebug()<<"dataciao";

              stream << data.toJson(QJsonDocument::Compact);

              file.close();
              qDebug() << "Writing finished at "+path;
          }
}


QJsonDocument parser(QString f, QString classname){
    qDebug().noquote() << classname;
    QString values[20] = {"Level","BAB","fort","ref","vol","special","0spell","1spell","2spell","3spell","4spell","5spell","6spell","7spell","8spell","9spell",
                          "Flurry","Unarmed Damage","AC Bonus","Fast Movement"};

    QString spellcaster[4]={"Cleric", "Druid", "Wizard", "Sorcerer"};
    QString halfspellcaster[3]={"Bard", "Ranger"};
    //qDebug() << values[0];
    QString regex = "(<td>)(.*?)(</td>)|(<td style=\"white-space: normal;\">)(.*?)(</td>)|(<td style=\"white-space: normal;word-wrap: break-word;\">)(.*?)(</wbr></td>)";
    QRegularExpression re(regex);
    QRegularExpressionMatchIterator i = re.globalMatch(f);

    //Json variables
    QJsonObject classobject, level;
    QJsonArray livelli;
    //QJsonArray levelarray;
    classobject["Class"] = classname;
    //classobject.insert("Class", QJsonValue::fromVariant(classname));
    QRegularExpressionMatch match = i.next();
    QString t =match.captured(2);


    QString re1 = "st|nd|rd|th";
    QString l;

    while (i.hasNext()) {
        QRegularExpression re(re1) ;
        if (re.match(t).hasMatch()){
            l = t;
            //qDebug().noquote() << t+"___________";
            int j=1;
            match = i.next();
            t =match.captured(2);
            while (!re.match(t).hasMatch()){
                //qDebug().noquote() << match.captured(2)+"____F";
                if (j==6 &&((classname==halfspellcaster[0])|(classname==halfspellcaster[1])|(classname=="Monk")) &&!
                        ((classname==spellcaster[0])|(classname==spellcaster[1])|(classname==spellcaster[2])|(classname==spellcaster[3]))){
                    if (classname=="Monk"){
                        j=16;
                    }else{
                        j++;
                    }
                }
                if (j==5){ //if per le capacità di classe
                    level[values[j]]= match.captured(5);
                }else if(j==16){ //if per la flurry del monaco
                    level[values[j]]= match.captured(8);
                }else {
                    if (match.captured(2)=="&mdash;"){
                        level[values[j]]= "-";
                    }else{
                        level[values[j]]= match.captured(2);
                    }
                }
                if (i.hasNext()){
                    match = i.next();
                    t=match.captured(2);
                } else{
                    break;
                }
                j++;

            };
//test22
            livelli.push_back(level);
            //classobject.insert(l,level);
        }
        classobject.insert("Levels", livelli);
    }
    QJsonDocument doc(classobject);
    writeFile("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/Classes/"+classname+".json", doc);
    return doc;
    //qDebug() << doc.
}


