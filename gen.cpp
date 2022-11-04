#include "gen.h"

//void cleanjson

void extract_value(QString classe, int level, QString var){
    QJsonDocument d=readJson("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/Classes/"+classe);
    QJsonObject o = readField(d);
    qDebug()<<o["11th"][var];


};
