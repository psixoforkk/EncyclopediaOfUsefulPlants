#include "addplant.h"
#include "ui_addplant.h"

AddPlant::AddPlant(QSqlQuery query, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPlant)
{
    values = new QString[5];
    ui->setupUi(this);
    emit ui->deleteButton->click();
    this->query = query;
}

QString* AddPlant::getValues()
{
    return values;
}

QByteArray AddPlant::getByteArray()
{
    return byteArray;
}
AddPlant::~AddPlant()
{
    delete ui;
}

void AddPlant::on_uploadButton_clicked()
{
    QString photoname = QFileDialog::getOpenFileName(this, "Open file", QDir::currentPath(), "Images (*.png *.jpeg *.jpg)");
    if (!photoname.isEmpty()){
        QStringList lst = photoname.split('.');
        formatFile = lst[lst.size()-1];
        formatFile = formatFile.toUpper();
        image.load(photoname);
        ui->image->setPixmap(QPixmap::fromImage(image));
    }
}

void AddPlant::on_deleteButton_clicked()
{
    int width = 316;
    int height = 453;
    ui->image->setScaledContents(true);
    image.load(":/resources/images/LuckyCloverNo.jpg");
    ui->image->setPixmap(QPixmap::fromImage(image.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation)));
    formatFile = "JPG";
}

void AddPlant::on_buttonBox_accepted()
{
    values[1] = ui->mainName->text();
    values[2] = ui->mainInfo->toPlainText();
    values[4] = ui->mainUsage->toPlainText();
    QString name = ui->mainName->text();
    if (name == "") {
        QMessageBox::information(this, "Ошибка строк", "Необходимо заполнить название", QMessageBox::Ok);
        return;
    }
    name = ui->mainInfo->toPlainText();
    if (name == "") {
        QMessageBox::information(this, "Ошибка строк", "Необходимо заполнить общую информацию", QMessageBox::Ok);
        return;
    }
    name = ui->mainUsage->toPlainText();
    if (name == "") {
        QMessageBox::information(this, "Ошибка строк", "Необходимо заполнить область применения", QMessageBox::Ok);
        return;
    }
    for (int i = 1; i < 2; i++){
        for (int j = 0; j < values[i].length(); ++j){
            if (!values[i][j].isLetter()){
                QMessageBox::information(this, "Ошибка строк", "В названии только буквы", QMessageBox::Ok);
                return;
            }
        }
    }
    for (int i = 1; i < 2; i++){
        for (int j = 0; j < 1; ++j){
            if (!values[i][j].isUpper()){
                QMessageBox::information(this, "Ошибка строк", "Название, должно начинаться с большой буквы", QMessageBox::Ok);
                return;
            }
        }
    }
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    if (formatFile == "PNG") image.save(&buffer, "PNG");
    else if (formatFile == "JPG") image.save(&buffer, "JPG");
    else image.save(&buffer, "JPEG");
    emit this->accept();
}


void AddPlant::on_buttonBox_rejected()
{
    emit this->reject();
}
