#include "watchplant.h"
#include "ui_watchplant.h"

WatchPlant::WatchPlant(QString *values, QByteArray byteArray, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WatchPlant)
{
    ui->setupUi(this);
    ui->mainName->setText(values[1]);
    ui->mainInfo->setText(values[2]);
    ui->mainUsage->setText(values[4]);
    QPixmap pix = QPixmap();
    pix.loadFromData(byteArray);
    int width = 371;
    int height = 571;
    ui->image->setScaledContents(true);
    pix = pix.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->image->setPixmap(pix);
    ui->mainInfo->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->mainInfo->setReadOnly(true);
    ui->mainName->setReadOnly(true);
    ui->mainUsage->setReadOnly(true);
}

WatchPlant::~WatchPlant()
{
    delete ui;
}

void WatchPlant::on_buttonBox_accepted()
{
    this->accept();
}

void WatchPlant::on_buttonBox_rejected()
{
    this->reject();
}
