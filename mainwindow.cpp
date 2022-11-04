#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <gen.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir directory("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/PSRD-Data-release/core_rulebook/class/core/");
    QStringList classes = directory.entryList(QStringList() << "*.json",QDir::Files);
    foreach(QString filename, classes) {
    qDebug()<<"I'm doing .... " +filename;
    //extract_value(filename, 2, "BAB");
    QJsonDocument d = readJson("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/PSRD-Data-release/core_rulebook/class/core/"+filename);
    QJsonObject o = readField(d);
    QString c = d.toJson(QJsonDocument::Indented);

    ui->textEdit->setText(c);
    ui->field->setText(o["sections"][2]["sections"][0]["sections"][0]["body"].toString());
    ui->classjson->setText(parser(o["sections"][2]["sections"][0]["sections"][0]["body"].toString(),o["name"].toString()).toJson(QJsonDocument::Indented));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

