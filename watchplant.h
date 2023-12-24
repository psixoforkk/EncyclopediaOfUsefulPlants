#ifndef WATCHPLANT_H
#define WATCHPLANT_H

#include <QDialog>

namespace Ui {
class WatchPlant;
}

class WatchPlant : public QDialog
{
    Q_OBJECT

public:
    explicit WatchPlant(QString* values, QByteArray byteArray, QWidget *parent = 0);
    ~WatchPlant();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::WatchPlant *ui;
};

#endif // WATCHPLANT_H
