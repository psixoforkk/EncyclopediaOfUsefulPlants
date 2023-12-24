#include "encyclopediawindow.h"
#include "ui_encyclopediawindow.h"

EncyclopediaWindow::EncyclopediaWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EncyclopediaWindow)
{
        ui->setupUi(this);
        db = QSqlDatabase::addDatabase("QSQLITE", "db");
        db.setDatabaseName("D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db");
        if(db.open()){
            ui->statusBar->showMessage("Database open", 3000);
        }
        else{
            ui->statusBar->showMessage("Database not open", 3000);
        }
        query = QSqlQuery(db);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(1 , QHeaderView::Stretch);
        ui->tableWidget->setSortingEnabled(true);
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        loadPlantsDataBase();
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
        timer->start(60000);

}

void EncyclopediaWindow::loadPlantsDataBase() {
    ui->tableWidget->setRowCount(0);
    if (!query.exec("SELECT ID, name, info FROM plants")){
        ui->statusBar->showMessage("Database table 'Plants' not open", 3000);
        return;
    }
    while (query.next()) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        for (int i = 0; i < 2; i++) ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
    }
}

EncyclopediaWindow::~EncyclopediaWindow()
{
    delete ui;
}

void EncyclopediaWindow::on_changePlant_clicked()
{
    if (ui->tableWidget->selectedItems().isEmpty()) return;
    QString ID = ui->tableWidget->selectedItems()[0]->text();
    if (!query.exec("SELECT * FROM plants WHERE ID = " +ID)){
        ui->statusBar->showMessage("Database table 'Plants' not open", 3000);
        return;
    }
    QString* values = new QString[5];
    QByteArray byteArray;
    while(query.next()){
        for (int i = 0; i < 5; ++i) values[i] = query.value(i).toString();
        byteArray = query.value(3).toByteArray();
    }
    watchPlant = new WatchPlant(values, byteArray, this);
    if (watchPlant->exec() == QDialog::Accepted) {

    }
}

void EncyclopediaWindow::on_refreshPlant_clicked()
{
    loadPlantsDataBase();
}

void EncyclopediaWindow::timerUpdate() {
    loadPlantsDataBase();
}

void EncyclopediaWindow::on_deletePlant_clicked()
{
    if (ui->tableWidget->selectedItems().isEmpty()) return;
    QString ID = ui->tableWidget->selectedItems()[0]->text();
    if (!query.exec("DELETE FROM plants WHERE ID = " + ID)){
        ui->statusBar->showMessage("Not index", 3000);
        return;
    }
    emit this->on_refreshPlant_clicked();
}

void EncyclopediaWindow::on_addPlant_clicked()
{
    addPlant = new AddPlant(query, this);
    if(addPlant->exec() == QDialog::Accepted){
        QString* values = addPlant->getValues();
        QByteArray array = addPlant->getByteArray();
        query.prepare( "INSERT INTO plants (ID, name, info, picture, useage) "
                       "VALUES (?,?,?,?,?)");
        counter++;
        query.addBindValue(counter);
        query.addBindValue(values[1]);
        query.addBindValue(values[2]);
        query.addBindValue(array);
        query.addBindValue(values[4]);
        if(!query.exec()){
            ui->statusBar->showMessage("Can't insert new plant to database", 3000);
            return;
        }
        emit this->on_refreshPlant_clicked();
    }
}

void EncyclopediaWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);
    emit this->on_changePlant_clicked();
}

void EncyclopediaWindow::on_tableWidget_cellClicked(int row, int column)
{
    Q_UNUSED(row);
    Q_UNUSED(column);
}

void EncyclopediaWindow::on_aButton_clicked()
{
    const QString data = "А";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_bButton_clicked()
{
    const QString data = "Б";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_v1Button_clicked()
{
    const QString data = "В";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_gButton_clicked()
{
    const QString data = "Г";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_dButton_clicked()
{
    const QString data = "Д";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_eButton_clicked()
{
    const QString data = "Е";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_jButton_clicked()
{
    const QString data = "Ж";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_zButton_clicked()
{
    const QString data = "З";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_iButton_clicked()
{
    const QString data = "И";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_kButton_clicked()
{
    const QString data = "К";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_lButton_clicked()
{
    const QString data = "Л";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_mButton_clicked()
{
    const QString data = "М";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_nButton_clicked()
{
    const QString data = "Н";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_oButton_clicked()
{
    const QString data = "О";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_pButton_clicked()
{
    const QString data = "П";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_rButton_clicked()
{
    const QString data = "Р";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_cButton_clicked()
{
    const QString data = "С";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_tButton_clicked()
{
    const QString data = "Т";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_uButton_clicked()
{
    const QString data = "У";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_fButton_clicked()
{
    const QString data = "Ф";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_xButton_clicked()
{
    const QString data = "Х";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_czButton_clicked()
{
    const QString data = "Ц";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_chButton_clicked()
{
    const QString data = "Ч";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_shButton_clicked()
{
    const QString data = "Ш";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_shchButton_clicked()
{
    const QString data = "Щ";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_efButton_clicked()
{
    const QString data = "Э";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_yuButton_clicked()
{
    const QString data = "Ю";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_yaButton_clicked()
{
    const QString data = "Я";
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
       if (table->item(i, 1)->text()[0] != data) {
          table->setRowHidden(i, true);
       }
       else {
           table->setRowHidden(i, false);
       }
    }
}

void EncyclopediaWindow::on_resetButton_clicked()
{
    QTableWidget *table = ui->tableWidget;
    for(int i = 0; i < table->rowCount(); i++) {
          table->setRowHidden(i, false);
    }
}

void EncyclopediaWindow::on_searchingButton_clicked()
{
    if (ui->searchLine->text() != "") {
        query.exec(QString("SELECT ID, name FROM plants WHERE name LIKE '%1%'").arg(ui->searchLine->text()));
        ui->tableWidget->setRowCount(0);
        while (query.next()) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for (int i = 0; i < 2; i++) ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }
    else {
        loadPlantsDataBase();
    }
}

void EncyclopediaWindow::on_clearButton_clicked()
{
    ui->searchLine->clear();
    loadPlantsDataBase();
}

void EncyclopediaWindow::on_newDB_triggered(){
    int ret = QMessageBox::question(this, "Создание новой базы данных", "Создание новой базы данных удалит текущую. Вы согласны?", QMessageBox::Ok | QMessageBox::Cancel);
    if (ret == QMessageBox::Ok){
        if (QFile::exists("D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db")){
            db.close();
            QFile::remove("D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db");
        }
        if(!QFile::copy("D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/newDatabase.db", "D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db"))
            QMessageBox::information(this,"Ошибка копирования","Не получилось импортировать файл");
        db.open();
    }
}

void EncyclopediaWindow::on_exportDB_triggered(){
    QString filename = QFileDialog::getSaveFileName(this,"Export Database", QDir::currentPath() + "/PlantsLits.db", "Databases (*.db)");
    if (filename.isEmpty()) return;
    if (QFile::exists(filename))
        QFile::remove(filename);
    if(!QFile::copy("D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db", filename))
        QMessageBox::information(this,"Ошибка копирования","Не получилось экспортировать файл");
}

void EncyclopediaWindow::on_importDB_triggered(){
    QString filename = QFileDialog::getOpenFileName(this,"Import Database", QDir::currentPath() + "/PlantsLits.db", "Databases (*.db)");
    if (filename.isEmpty()) return;
    if (QFile::exists("D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db")){
        db.close();
        QFile::remove("D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db");
    }
    if(!QFile::copy(filename, "D:/qtkal/kurs2/EncyclopediaOfUsefulPlants/PlantsLits.db"))
        QMessageBox::information(this,"Ошибка копирования","Не получилось импортировать файл");
    db.open();
}


void EncyclopediaWindow::on_searchLine_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    if (ui->searchLine->text() != "") {
        query.exec(QString("SELECT ID, name FROM plants WHERE name LIKE '%1%'").arg(ui->searchLine->text()));
        ui->tableWidget->setRowCount(0);
        while (query.next()) {
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());
            for (int i = 0; i < 2; i++) ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem(query.value(i).toString()));
        }
    }
    else {
        loadPlantsDataBase();
    }
}
