#include "gen.h"

//void cleanjson

QJsonValue extract_value(QString classe, int level, QString var){
    QJsonDocument d=readJson("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/Classes/"+classe);
    QJsonValue o = readField(d)["Levels"][level-1][var];
    //qDebug()<<o["Levels"][level-1][var];
    return o;
};
