#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settings.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(1));
    ui->lineEdit_2->setText(QString::number(5));

    QObject::connect(ui->actOpen,    &QAction::triggered, this, &MainWindow::open);
    QObject::connect(ui->actSave,    &QAction::triggered, this, &MainWindow::save);
    QObject::connect(ui->actSaveAs,    &QAction::triggered, this, &MainWindow::save_as);
    QObject::connect(ui->tableWidget, &QTableWidget::itemChanged, this, &MainWindow::cellEdit);
    QObject::connect(ui->add_row,    &QAction::triggered, this, &MainWindow::addRow);
    QObject::connect(ui->add_column,    &QAction::triggered, this, &MainWindow::addColumn);
    QObject::connect(ui->actionabout, &QAction::triggered, this, &MainWindow::infoPage);
}

void MainWindow::infoPage()
{
    About about;
    if (about.exec())
    {

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::next()
{
    QDialog about;
    if (about.exec())
    {

    }
}

void MainWindow::addRow()
{
    if (parser){
        parser->NewRow();
        ui->tableWidget->setRowCount(parser->rowCount());
        ui->statusBar->showMessage(QString("Добавленна строка"));
    }else{
        QMessageBox::warning(this, "INVALID OPERATION", "Open a file");
    }
}

void MainWindow::addColumn()
{
     if (parser){
        parser->NewColumn();
        ui->tableWidget->setColumnCount(parser->columnCount());
        ui->statusBar->showMessage(QString("Добавлен столбец"));
     }else{
         QMessageBox::warning(this, "INVALID OPERATION", "Open a file");
     }
}

void MainWindow::save()
{
    if (parser){
        auto path = parser->getFileName();
        parser->save(path);
        ui->statusBar->showMessage(QString("Файл сохранен"));
    }else{
        QMessageBox::warning(this, "INVALID OPERATION", "Open a file");
    }

}

void MainWindow::save_as()
{
    if (parser){
        auto path = QFileDialog::getSaveFileName(this);
        ui->statusBar->showMessage(QString("Файл сохранен в ") + path);
        parser->save(path.toStdString());
    }else{
        QMessageBox::warning(this, "INVALID OPERATION", "Open a file");
    }
}

void MainWindow::open()
{
    if (parser) {
        QMessageBox::StandardButton reply;
          reply = QMessageBox::question(this, "Open", "Whant to save?",
                                        QMessageBox::Yes|QMessageBox::No);
          if (reply == QMessageBox::Yes) {
              save();
              auto path = QFileDialog::getOpenFileName(this);
              if (path.isEmpty()) {
                  return;
              }

              ui->statusBar->showMessage(QString("Открыт файл ") + path);
              try{
                  parser = new CSVFile(path.toStdString());
              }catch(exception &problem){
                  QMessageBox::warning(this, "INVALID FILE", "Open another file");
              }

              ui->tableWidget->setRowCount(parser->rowCount());
              ui->tableWidget->setColumnCount(parser->columnCount());

              for (size_t row = 0; row < parser->rowCount(); row++) {
                  Row rowVal = parser->getRow(row);
                  for (size_t col = 0; col < rowVal.size(); col++) {
                      QTableWidgetItem *newItem = new QTableWidgetItem(QString::fromStdString(rowVal[col]));
                      ui->tableWidget->setItem(row, col, newItem);
                  }
              }
          } else if(reply == QMessageBox::No) {
              auto path = QFileDialog::getOpenFileName(this);
              if (path.isEmpty()) {
                  return;
              }

              ui->statusBar->showMessage(QString("Открыт файл ") + path);

              try{
                  parser = new CSVFile(path.toStdString());
              }catch(exception &problem){
                  QMessageBox::warning(this, "INVALID FILE", "Open another file");
              }

              ui->tableWidget->setRowCount(parser->rowCount());
              ui->tableWidget->setColumnCount(parser->columnCount());

              for (size_t row = 0; row < parser->rowCount(); row++) {
                  Row rowVal = parser->getRow(row);
                  for (size_t col = 0; col < rowVal.size(); col++) {
                      QTableWidgetItem *newItem = new QTableWidgetItem(QString::fromStdString(rowVal[col]));
                      ui->tableWidget->setItem(row, col, newItem);
                  }
              }
          }

    }else {
        auto path = QFileDialog::getOpenFileName(this);
        if (path.isEmpty()) {
            return;
        }

        ui->statusBar->showMessage(QString("Открыт файл ") + path);

        try{
            parser = new CSVFile(path.toStdString());
        }catch(exception &problem){
            QMessageBox::warning(this, "INVALID FILE", "Open another file");
        }

        ui->tableWidget->setRowCount(parser->rowCount());
        ui->tableWidget->setColumnCount(parser->columnCount());

        for (size_t row = 0; row < parser->rowCount(); row++) {
            Row rowVal = parser->getRow(row);
            for (size_t col = 0; col < rowVal.size(); col++) {
                QTableWidgetItem *newItem = new QTableWidgetItem(QString::fromStdString(rowVal[col]));
                ui->tableWidget->setItem(row, col, newItem);
            }
        }
    }
}


void MainWindow::cellEdit(QTableWidgetItem *item)
{
    parser->setValue(item->row(), item->column(), item->text().toStdString());
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->menuhelp->title() == QString("file"))
    {
        ui->menuhelp->setTitle("файл");
    }
    else if(ui->menuhelp->title() == QString("файл"))
    {
        ui->menuhelp->setTitle("file");
    }
    if(ui->pushButton->text() == QString("change language"))
    {
        ui->pushButton->setText("изменить язык");
    }
    else if(ui->pushButton->text() == QString("изменить язык"))
    {
        ui->pushButton->setText("change language");
    }
    if(ui->pushButton_2->text() == QString("filter"))
    {
        ui->pushButton_2->setText("фильтр");
    }
    else if(ui->pushButton_2->text() == QString("фильтр"))
    {
        ui->pushButton_2->setText("filter");
    }
    if(ui->menuhelp_2->title() == QString("help"))
    {
        ui->menuhelp_2->setTitle("помощь");
    }
    else if(ui->menuhelp_2->title() == QString("помощь"))
    {
        ui->menuhelp_2->setTitle("help");
    }
    if(ui->actOpen->text() == QString("open"))
    {
        ui->actOpen->setText("открыть");
    }
    else if(ui->actOpen->text() == QString("открыть"))
    {
        ui->actOpen->setText("open");
    }
    if(ui->menuhelp->title() == QString("table"))
    {
        ui->menuhelp->setTitle("таблица");
    }
    else if(ui->menuhelp->title() == QString("таблица"))
    {
        ui->menuhelp->setTitle("table");
    }
    if(ui->menutable->title() == QString("table"))
    {
        ui->menutable->setTitle("таблица");
    }
    else if(ui->menutable->title() == QString("таблица"))
    {
        ui->menutable->setTitle("table");
    }
    if(ui->actSave->text() == QString("save"))
    {
        ui->actSave->setText("сохранить");
    }
    else if(ui->actSave->text() == QString("сохранить"))
    {
        ui->actSave->setText("save");
    }
    if(ui->actSaveAs->text() == QString("save as"))
    {
        ui->actSaveAs->setText("сохранить как");
    }
    else if(ui->actSaveAs->text() == QString("сохранить как"))
    {
        ui->actSaveAs->setText("save as");
    }
    if(ui->add_column->text() == QString("add column"))
    {
        ui->add_column->setText("добавить столбец");
    }
    else if(ui->add_column->text() == QString("добавить столбец"))
    {
        ui->add_column->setText("add column");
    }
    if(ui->add_row->text() == QString("add row"))
    {
        ui->add_row->setText("добавить ряд");
    }
    else if(ui->add_row->text() == QString("добавить ряд"))
    {
        ui->add_row->setText("add row");
    }
    if(ui->actionabout->text() == QString("about"))
    {
        ui->actionabout->setText("о нас");
    }
    else if(ui->actionabout->text() == QString("о нас"))
    {
        ui->actionabout->setText("about");
    }
    if(ui->label->text() == QString("minimum rating (1-5)"))
    {
        ui->label->setText("минимальный рейтинг (1-5)");
    }
    else if(ui->label->text() == QString("минимальный рейтинг (1-5)"))
    {
        ui->label->setText("minimum rating (1-5)");
    }
    if(ui->label_2->text() == QString("maximum rating (1-5)"))
    {
        ui->label_2->setText("максимальный рейтинг (1-5)");
    }
    else if(ui->label_2->text() == QString("максимальный рейтинг (1-5)"))
    {
        ui->label_2->setText("maximum rating (1-5)");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    settings::instanse()->setmin_rating(stoi((ui->lineEdit->text()).toStdString()));
    settings::instanse()->setmax_rating(stoi((ui->lineEdit_2->text()).toStdString()));
}

