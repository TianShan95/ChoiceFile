#include "dialogpic.h"
#include "ui_dialogpic.h"
#include <QDebug>

DialogPic::DialogPic(QString picPath, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPic)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(picPath));

}

DialogPic::~DialogPic()
{
    delete ui;
}
