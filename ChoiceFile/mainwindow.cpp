#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // set table no Editable
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // debug code
    qDebug() << "hello world";
    QString defaultFileName = "/Users/aaron/Downloads/ChoiceFile/ChoiceFile/test.txt";

    // show text file path to lineEdit
    ui->qWidgetLineEditPath->setText(defaultFileName);

    // initial object vector by text content
    qVectorMemInfo =  getTextContent(defaultFileName);
    display2table();
    initQComboFilter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* 接口功能：点击“头像”按钮弹出图片查看对话框
 * 输入参数: 无
 * 输出参数: 无
 * 调用关系: “头像” 按钮槽函数
*/
void MainWindow::showAvator()
{
//    获取信号发送位置
    QPushButton *button = dynamic_cast<QPushButton *>(QObject::sender());
    QModelIndex index = ui->tableWidget->indexAt(button->pos());
    qDebug() << "Click Button: row: " << index.row() << " col: " <<  index.column();
    QVector<QString> suffixes = {".png", ".jpeg"};
    QString realSuffix;
    for (QString suffix:suffixes)
    {
        QFile file("/Users/aaron/Downloads/ChoiceFile/头像" + QString::number(index.row()+1) + suffix);
        if (file.exists())
        {
            realSuffix = suffix;
            break;
        }
    }
    Person person = qVectorMemInfo[index.row()].getPerson();
    QString shotPicName = person.btn->text();
    QString picPath = ":/new/prefix1/" + shotPicName + realSuffix;
    DialogPic *dialog = new DialogPic(picPath);
    dialog->exec();
}


// combox in table slot function
void MainWindow::on_ComboActivedFunc(int index)
{
    //获取信号发送位置
//    QComboBox *combo = dynamic_cast<QComboBox *>(QObject::sender());
//    QModelIndex position = ui->tableWidget->indexAt(combo->pos());
//    int selectRow = position.row();
//    qDebug() << "Click Combox: row: " << position.row() << " col: " <<  position.column();

    QVector<QString> checkOption;
    ui->qWidgetComboBoxBirth->clear();
    comboBoxShowBirthTableItem();
    ui->qWidgetComboBoxBirth->setCurrentText(provinces[index]);
    qDebug() << "index: " << index << " " << provinces[index];
}


// 表格选中 触发函数
void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
//    qDebug() << "row: " << row+1 << " col: " << column;
    if (column == FIRST_COL)
    {
        ui->qWidgetComboBoxName->setCurrentText(qVectorMemInfo[row].getPerson().name->text());

    }
    if (column == SECOND_COL)
    {
        ui->qWidgetComboBoxAge->setCurrentText(qVectorMemInfo[row].getPerson().age->text());
    }
    if(column == THIRD_COL)
    {
        ui->qWidgetComboBoxSex->setCurrentText(qVectorMemInfo[row].getPerson().sex->text());
    }
    if(column == FOURTH_COL)
    {
        ui->qWidgetComboBoxBirth->setCurrentText(qVectorMemInfo[row].getPerson().combo->currentText());
    }
//    if(column == FIFTH_COL)
//    {
//        ui->qWidgetComboBoxAvator->setCurrentText(qVectorMemInfo[row].getPerson().btn->text());
//    }
}



// “启动编辑” checkBox
void MainWindow::on_qWidgetCheckBoxTableEdit_stateChanged(int arg1)
{
    if(ui->qWidgetCheckBoxTableEdit->isChecked())
    {
        ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);
    }
    else
    {
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }

    for(QVector<MemberInfo>::iterator it = qVectorMemInfo.begin(); it != qVectorMemInfo.end(); ++it)
    {
         it->getPerson().combo->setEnabled(arg1);
    }
}


// "全部显示" button
void MainWindow::on_qWidgetPushButtonShowAll_clicked()
{
     for (int row=0; row<ui->tableWidget->rowCount(); row++)
     {
         ui->tableWidget->setRowHidden(row, false);
     }
     ui->tableWidget->horizontalHeader()->setSortIndicator(-1, Qt::AscendingOrder);
}


// Cell Changed
void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    if (column == FIRST_COL)
    {
        ui->qWidgetComboBoxName->setCurrentText(qVectorMemInfo[row].getPerson().name->text());
        ui->qWidgetComboBoxName->clear();
        comboBoxShowNameTableItem();
    }
    if(column == SECOND_COL)
    {
        ui->qWidgetComboBoxAge->setCurrentText(qVectorMemInfo[row].getPerson().age->text());
        ui->qWidgetComboBoxAge->clear();
        comboBoxShowAgeTableItem();
    }
    if(column == THIRD_COL)
    {
        ui->qWidgetComboBoxSex->setCurrentText(qVectorMemInfo[row].getPerson().sex->text());
        ui->qWidgetComboBoxSex->clear();
        comboBoxShowSexTableItem();
    }
    if(column == FOURTH_COL)
    {
        ui->qWidgetComboBoxBirth->setCurrentText(qVectorMemInfo[row].getPerson().combo->currentText());
        ui->qWidgetComboBoxBirth->clear();
        comboBoxShowBirthTableItem();
    }
//    if(column == FIFTH_COL)
//    {
//        ui->qWidgetComboBoxAvator->setCurrentText(qVectorMemInfo[row].getPerson().btn->text());
//    }

}


void MainWindow::display2table()
{
    int lineCount = qVectorMemInfo.count();

    this->ui->tableWidget->setRowCount(lineCount);
    // 表格内容
    for(int i = 0; i < lineCount; i++)
    {
        if(qVectorMemInfo[i].getShot())
        {
            Person person = qVectorMemInfo[i].getPerson();

            ui -> tableWidget -> setItem(i, FIRST_COL, person.name);
            ui -> tableWidget -> setItem(i, SECOND_COL, person.age);
            ui -> tableWidget -> setItem(i, THIRD_COL, person.sex);
            ui -> tableWidget -> setCellWidget(i, FOURTH_COL, person.combo);
            ui->tableWidget->setCellWidget(i, FIFTH_COL, person.btn);

            QObject::connect(person.combo,SIGNAL(activated(int)), this, SLOT(on_ComboActivedFunc(int)));
            QObject::connect(person.btn, SIGNAL(clicked()), this, SLOT(showAvator()));
        }
    }
    ui->tableWidget->setSortingEnabled(true);
}


QVector<MemberInfo> MainWindow::getTextContent(const QString fileName)
{
    QVector<MemberInfo> t_data;

    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this, QObject::tr("Error"), QObject::tr("文件打开错误: %1").arg(file.errorString()));
        return t_data;
    }
    QTextStream t_in(&file);
    // 把文件内容加载到字符串列表
    while (!t_in.atEnd())
    {
        QString t_line = t_in.readLine();
        QStringList t_list = t_line.split('\t');
        t_data.append(MemberInfo(t_list));
    }
    return t_data;
}

// show name combobox
void MainWindow::comboBoxShowNameTableItem()
{
    QVector<QString> checkOption;

    for (int i=0; i<qVectorMemInfo.count(); i++)
    {
        QString name = qVectorMemInfo[i].getPerson().name->text();
        if (!checkOption.contains(name))
        {
            checkOption.append(name);
            ui->qWidgetComboBoxName->addItem(name);
        }
    }
}

// show age combobox
void MainWindow::comboBoxShowAgeTableItem()
{
    QVector<QString> checkOption;
    for (int i=0; i<qVectorMemInfo.count(); i++)
    {
        QString age = qVectorMemInfo[i].getPerson().age->text();
        if(!checkOption.contains(age))
        {
            checkOption.append(age);
            ui->qWidgetComboBoxAge->addItem(age);
        }
    }
}

// show sex combobox
void MainWindow::comboBoxShowSexTableItem()
{
    QVector<QString> checkOption;
    for(int i=0; i<qVectorMemInfo.count(); i++)
    {
        QString sex = qVectorMemInfo[i].getPerson().sex->text();
        if(!checkOption.contains(sex))
        {
            checkOption.append(sex);
            ui->qWidgetComboBoxSex->addItem(sex);
        }
    }
}

// show birthplace combobox
void MainWindow::comboBoxShowBirthTableItem()
{
    QVector<QString> checkOption;
    for(int i=0; i<qVectorMemInfo.count(); i++)
    {
        QString birth = qVectorMemInfo[i].getPerson().combo->currentText();
        if(!checkOption.contains(birth))
        {
            checkOption.append(birth);
            ui->qWidgetComboBoxBirth->addItem(QString::fromStdString("birth"));
        }
    }
}

// show Avator combobox
void MainWindow::comboBoxShowAvatorTableItem()
{
    QVector<QString> checkOption;
    for(int i=0; i<qVectorMemInfo.count(); i++)
    {
QString avator = qVectorMemInfo[i].getPerson().btn->text();
        if(!checkOption.contains(avator))
        {
            checkOption.append(avator);
            ui->qWidgetComboBoxAvator->addItem(avator);
        }
    }
}


// "过滤"按钮
void MainWindow::on_qWidgetPushButtonFilter_clicked()
{
    QString targetNameStr = ui->qWidgetComboBoxName->currentText();
    QString targetAgeStr = ui->qWidgetComboBoxAge->currentText();
    QString targetSexStr = ui->qWidgetComboBoxSex->currentText();
    QString targetBirthStr = ui->qWidgetComboBoxBirth->currentText();
    QString targetAvatorStr = ui->qWidgetComboBoxAvator->currentText();

    for(QVector<MemberInfo>::iterator it = qVectorMemInfo.begin(); it != qVectorMemInfo.end(); ++it)
    {
        it->setShot(true);
        if((ui->qWidgetCheckBoxName -> isChecked()) && (it->getPerson().name->text() != targetNameStr))
        {
            it->setShot(false);
            continue;
        }
        if((ui->qWidgetCheckBoxAge -> isChecked())
           && (it->getPerson().age->text() != targetAgeStr))
        {
            it->setShot(false);
            continue;
        }
        if((ui->qWidgetCheckBoxSex->isChecked()) && (it->getPerson().sex->text() != targetSexStr))
        {
            it->setShot(false);
            continue;
        }
        if((ui->qWidgetCheckBoxBirth->isChecked()) && (it->getPerson().combo->currentText() != targetBirthStr))
        {
            it->setShot(false);
            continue;
        }
        if((ui->qWidgetCheckBoxAvator->isChecked()) && (it->getPerson().btn->text() != targetAvatorStr))
        {
            it->setShot(false);
            continue;
        }
    }
    renewTable();

}

// renew table Widget refer to weather to show the obj
void MainWindow::renewTable()
{
    int i = 0;
   for(QVector<MemberInfo>::iterator it = qVectorMemInfo.begin(); it != qVectorMemInfo.end(); ++it)
    {
        if(it->getShot())
        {
            ui->tableWidget->setRowHidden(i, false);
        }
        else
        {
            ui->tableWidget->setRowHidden(i, true);
        }
        i++;
    }
}

void MainWindow::on_qWidgetPushButtonImport_clicked()
{
    QString fileName;
    // Open file dialog to get filename
    fileName = getTextFileName();
    // get text content
    qVectorMemInfo =  getTextContent(fileName);
    if(qVectorMemInfo.count())
    {
        // initalize vector value for table dispaly
        // display data content to table
        display2table();
        // set Item ComboBox initial value
        initQComboFilter();
    }
}

// get fileName
QString MainWindow::getTextFileName()
{
    qDebug() << "Come in utils OpenText function";
    QString fileName;
    // 存储表格内容

    fileName = QFileDialog::getOpenFileName(this, QObject::tr("文件"), "", QObject::tr("text(*.txt)"));
    if(!fileName.isNull())
    {
        //显示文件名到界面
        //fileName是选择的文件名
        ui->qWidgetLineEditPath -> setText(fileName);
    }
    return fileName;

}

void MainWindow::initQComboFilter()
{
    comboBoxShowNameTableItem();
    comboBoxShowAgeTableItem();
    comboBoxShowSexTableItem();
    comboBoxShowBirthTableItem();
    comboBoxShowAvatorTableItem();
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    if(column == FIRST_COL)
    {
        editNameRow = row;
        editNameCol = column;

        DialogEditName *dialogEditName = new DialogEditName();
        disconnect(dialogEditName, &DialogEditName::textEntered, this, &MainWindow::setNameInTable);

        connect(dialogEditName, &DialogEditName::textEntered, this, &MainWindow::setNameInTable);
        dialogEditName->exec();
    }
}

void MainWindow::setNameInTable(const QString &name)
{
    QTableWidgetItem *existingItem = ui->tableWidget->item(editNameRow, editNameCol);
    if (existingItem)
    {
        existingItem->setText(name);
    }
}
