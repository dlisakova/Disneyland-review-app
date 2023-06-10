#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "csvfile.h"
#include <QTableWidget>
#include "about.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void open();
    void save();
    void save_as();
    void addColumn();
    void addRow();
    void next();
    void cellEdit(QTableWidgetItem*);
    void infoPage();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    CSVFile *parser = nullptr;
};

#endif // MAINWINDOW_H
