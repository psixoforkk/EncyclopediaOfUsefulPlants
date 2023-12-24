#ifndef ENCYCLOPEDIAWINDOW_H
#define ENCYCLOPEDIAWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QListView>
#include <QDate>
#include <QTableWidgetItem>
#include <QTimer>

#include "addplant.h"
#include "watchplant.h"

namespace Ui {
class EncyclopediaWindow;
}

class EncyclopediaWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EncyclopediaWindow(QWidget *parent = nullptr);
    ~EncyclopediaWindow();

private slots:
    void on_changePlant_clicked();

    void on_refreshPlant_clicked();

    void on_deletePlant_clicked();

    void on_addPlant_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_cellClicked(int row, int column);

    void timerUpdate();

    void on_aButton_clicked();

    void on_bButton_clicked();

    void on_v1Button_clicked();

    void on_gButton_clicked();

    void on_dButton_clicked();

    void on_eButton_clicked();

    void on_jButton_clicked();

    void on_zButton_clicked();

    void on_iButton_clicked();

    void on_kButton_clicked();

    void on_lButton_clicked();

    void on_mButton_clicked();

    void on_nButton_clicked();

    void on_oButton_clicked();

    void on_pButton_clicked();

    void on_rButton_clicked();

    void on_cButton_clicked();

    void on_tButton_clicked();

    void on_uButton_clicked();

    void on_fButton_clicked();

    void on_xButton_clicked();

    void on_czButton_clicked();

    void on_chButton_clicked();

    void on_shButton_clicked();

    void on_shchButton_clicked();

    void on_efButton_clicked();

    void on_yuButton_clicked();

    void on_yaButton_clicked();

    void on_resetButton_clicked();

    void on_searchingButton_clicked();

    void on_clearButton_clicked();

    void on_newDB_triggered();

    void on_exportDB_triggered();

    void on_importDB_triggered();

    void on_searchLine_textChanged(const QString &arg1);

private:
    Ui::EncyclopediaWindow *ui;
    QSqlDatabase db;
    QSqlQuery query;
    void loadPlantsDataBase();
    AddPlant *addPlant;
    WatchPlant *watchPlant;
    int counter = 50;
    QTimer *timer;
};

#endif // ENCYCLOPEDIAWINDOW_H
