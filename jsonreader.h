#ifndef JSONREADER_H
#define JSONREADER_H

#endif // JSONREADER_H

#include <QApplication>
#include <QDebug>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QMainWindow>
#include <QtNetwork/QNetworkAccessManager>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QFile>
#include <QPushButton>
#include <iostream>
#include <QDir>

QJsonDocument readJson(QString path);
QJsonObject readField(QJsonDocument d);
QJsonDocument parser(QString f, QString classname);
QJsonArray bab(QString q);
void classparser(QString path, QString pathdestination);

//file
void writeFile(QString path, QJsonDocument data);
