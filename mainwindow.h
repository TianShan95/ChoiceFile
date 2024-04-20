/***********************************************************
* Copyright (C) 200X-2024   北京四方继保自动化股份有限公司/主站研发部
* All rights reserved.
*
* 文件名称：mainwindow.h
* 摘    要：显示表格处理工具界面；处理表格数据显示
* 当前版本：0.0.1,<完成日期2024-03-22>,<作者/田山>,<修改概述:以对象化的思想重构表格处理方法;修改变量名和函数名更加易懂>
*
* 历史记录：<旧版本号0.0.0>,<完成日期2024-03-22>,<作者/田山>,<修改概述：以对象化的思想>
*            V0.0.1，2024-03-22，田山，添加函数on_tableWidget_cellChanged(int row, int column)
*            … …
*
************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "ui_dialog.h"
#include "ui_dialogeditname.h"
#include "dialogpic.h"
#include "dialogeditname.h"
#include "memberInfo.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTextStream>
#include <QButtonGroup>


#define FIRST_COL 0
#define SECOND_COL 1
#define THIRD_COL 2
#define FOURTH_COL 3
#define FIFTH_COL 4

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    // 存储表格内容

    // 是否选中了省份选择
    bool shotProvince=false;
    bool shotPic=false;

    QVector<MemberInfo> qVectorMemInfo;

    static const int attrNum=5;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showAvator();

    void on_ComboActivedFunc(int);

    void on_tableWidget_cellClicked(int row, int column);

    void on_qWidgetCheckBoxTableEdit_stateChanged(int arg1);

    void on_qWidgetPushButtonShowAll_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_qWidgetPushButtonFilter_clicked();

    void on_qWidgetPushButtonImport_clicked();

    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    void display2table();
    QVector<MemberInfo> getTextContent(const QString fileName);
    void comboBoxShowNameTableItem();
    void comboBoxShowAgeTableItem();
    void comboBoxShowSexTableItem();
    void comboBoxShowBirthTableItem();
    void comboBoxShowAvatorTableItem();
    void renewTable();
    QString getTextFileName();
    void initQComboFilter();
};

#endif // MAINWINDOW_H
