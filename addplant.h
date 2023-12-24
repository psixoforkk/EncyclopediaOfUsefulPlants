#ifndef ADDPLANT_H
#define ADDPLANT_H

#include <QDialog>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QBuffer>
#include <QByteArray>

namespace Ui {
class AddPlant;
}

class AddPlant : public QDialog
{
    Q_OBJECT

public:
    explicit AddPlant(QWidget *parent = nullptr);
    AddPlant(QSqlQuery query, QWidget *parent = 0);
    QString* getValues();
    QByteArray getByteArray();
    ~AddPlant();

private slots:
    void on_uploadButton_clicked();

    void on_deleteButton_clicked();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddPlant *ui;
    QString* values;
    QByteArray byteArray;
    QSqlQuery query;
    QString formatFile;
    QImage image;
};

#endif // ADDPLANT_H
