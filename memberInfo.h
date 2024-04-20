/***********************************************************
* Copyright (C) 200X-2024   北京四方继保自动化股份有限公司/主站研发部
* All rights reserved.
*
* 文件名称：memberInfo.h
* 摘    要：抽象表格组件里每一条数据显示
* 当前版本：0.0.1,<完成日期2024-03-22>,<作者/田山>,<修改概述:以对象化的思想重构表格处理方法>
*
* 历史记录：<旧版本号0.0.0>,<完成日期2024-03-22>,<作者/田山>,<修改概述：以对象化的思想>
*            V0.0.1，2024-03-22，田山，添加函数on_tableWidget_cellChanged(int row, int column)
*            … …
*
************************************************************/
#ifndef MEMBERINFO_H
#define MEMBERINFO_H

#include <QStringList>
#include <QComboBox>
#include <QPushButton>
#include <QDebug>
#include <QTableWidgetItem>


#define NAME_INDEX 0
#define AGE_INDEX 1
#define SEX_INDEX 2
#define BIRTH_INDEX 3
#define AVATOR_INDEX 4
#define ATTR_NUM 5

extern QStringList provinces;

struct Person
{
    QTableWidgetItem*  name;
    QTableWidgetItem* age;
    QTableWidgetItem* sex;
    QComboBox *combo;
    QPushButton *btn;
};

class MemberInfo
{
private:
    Person person;
    bool shot=true;

public:
    MemberInfo();
    MemberInfo(QStringList);
    Person getPerson();
    bool getShot();
    void setShot(bool status);
};


#endif // MEMBERINFO_H
