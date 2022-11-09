#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <jsonreader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionParsing_triggered();

    //void on_comboBox_activated(int index);

    //void on_comboBox_currentTextChanged(const QString &arg1);

    void on_classbox_currentTextChanged(const QString &arg1);

    void on_str_textChanged(const QString &arg1);

    void on_str_returnPressed();

    void on_dex_returnPressed();

    void on_cos_returnPressed();

    void on_int_2_returnPressed();

    void on_wis_returnPressed();

    void on_cha_returnPressed();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
