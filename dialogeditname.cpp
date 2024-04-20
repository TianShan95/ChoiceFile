#include "dialogeditname.h"
#include "ui_dialogeditname.h"

DialogEditName::DialogEditName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogEditName)
{
    ui->setupUi(this);
    // 根据按钮框的布局，获取 OK 按钮
    QPushButton *okButton = ui->buttonBox->button(QDialogButtonBox::Ok);
    // 设置 OK 按钮的文本
    okButton->setText("确定");
    QPushButton *cancelButton = ui->buttonBox->button(QDialogButtonBox::Cancel);
    // 设置 OK 按钮的文本
    cancelButton->setText("取消");
}

DialogEditName::~DialogEditName()
{
    delete ui;
}

void DialogEditName::on_buttonBox_accepted()
{

}
