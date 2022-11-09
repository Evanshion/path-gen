#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <gen.h>


QString classname;
int str=0, dex=0, coss=0, intt=0, wis=0, cha=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir directory("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/PSRD-Data-release/core_rulebook/class/core/");
    QStringList classes = directory.entryList(QStringList() << "*.json",QDir::Files);


    ui->classe->setText("scegli la classe");
    foreach(QString filename, classes){
        ui->classbox->addItem(filename.remove(".json"));
    }
    for(int i=1;i<21;i++){
        ui->levelbox->addItem(QString::number(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionParsing_triggered()
{
    //"C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/PSRD-Data-release/core_rulebook/class/core/"
    //"C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/Classes/"
    classparser("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/PSRD-Data-release/core_rulebook/class/core/", "C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/Classes/");
}




void MainWindow::on_classbox_currentTextChanged(const QString &arg1)
{
    classname=arg1;
    ui->classe->setText(arg1);
    QString filename = arg1+".json";
    QJsonDocument d = readJson("C:/Users/IENOGIUS/Documents/Progetti QT/Path-gen/PSRD-Data-release/core_rulebook/class/core/"+filename);
    QJsonObject o = readField(d);
    QString c = d.toJson(QJsonDocument::Indented),
                body = o["sections"][2]["sections"][0]["sections"][0]["body"].toString(),
                classname = o["name"].toString();

    ui->textEdit->setText(c);
    ui->field->setText(o["sections"][2]["sections"][0]["sections"][0]["body"].toString());
    ui->classjson->setText(parser(body, classname).toJson(QJsonDocument::Indented));

}


void MainWindow::on_str_returnPressed()
{
    QString arg1 = ui->str->text();
    int n;
    if (arg1.toInt()>=10){
        n = ((arg1.toInt() - 10)/2);
    }else{
        n = ((arg1.toInt() - 10)/2)+((arg1.toInt() - 10)%2);
    }
    str=n;

    if (n>=0){
        ui->lstr->setText("+"+QString::number(n));
    }else{
        ui->lstr->setText(QString::number(n));
    }
}


void MainWindow::on_dex_returnPressed()
{
    QString arg1 = ui->dex->text();
    int n;
    if (arg1.toInt()>=10){
        n = ((arg1.toInt() - 10)/2);
    }else{
        n = ((arg1.toInt() - 10)/2)+((arg1.toInt() - 10)%2);
    }
    dex=n;
    if (n>=0){
        ui->ldex->setText("+"+QString::number(n));
    }else{
        ui->ldex->setText(QString::number(n));
    }

}


void MainWindow::on_cos_returnPressed()
{
    QString arg1 = ui->cos->text();
    int n;
    if (arg1.toInt()>=10){
        n = ((arg1.toInt() - 10)/2);
    }else{
        n = ((arg1.toInt() - 10)/2)+((arg1.toInt() - 10)%2);
    }
    coss=n;
    if (n>=0){
        ui->lcos->setText("+"+QString::number(n));
    }else{
        ui->lcos->setText(QString::number(n));
    }
}


void MainWindow::on_int_2_returnPressed()
{
    QString arg1 = ui->int_2->text();
    int n;
    if (arg1.toInt()>=10){
        n = ((arg1.toInt() - 10)/2);
    }else{
        n = ((arg1.toInt() - 10)/2)+((arg1.toInt() - 10)%2);
    }
    intt=n;
    if (n>=0){
        ui->lint->setText("+"+QString::number(n));
    }else{
        ui->lint->setText(QString::number(n));
    }
}


void MainWindow::on_wis_returnPressed()
{
    QString arg1 = ui->wis->text();
    int n;
    if (arg1.toInt()>=10){
        n = ((arg1.toInt() - 10)/2);
    }else{
        n = ((arg1.toInt() - 10)/2)+((arg1.toInt() - 10)%2);
    }
    wis=n;
    if (n>=0){
        ui->lwis->setText("+"+QString::number(n));
    }else{
        ui->lwis->setText(QString::number(n));
    }
}


void MainWindow::on_cha_returnPressed()
{
    QString arg1 = ui->cha->text();
    int n;
    if (arg1.toInt()>=10){
        n = ((arg1.toInt() - 10)/2);
    }else{
        n = ((arg1.toInt() - 10)/2)+((arg1.toInt() - 10)%2);
    }
    cha=n;
    if (n>=0){
        ui->lcha->setText("+"+QString::number(n));
    }else{
        ui->lcha->setText(QString::number(n));
    }
}

