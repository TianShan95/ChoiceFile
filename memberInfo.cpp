#include "memberInfo.h"


QStringList provinces =
{
    "北京", "上海", "天津", "重庆",
    "广东", "江苏", "浙江", "福建", "山东", "安徽", "江西", "河南", "湖北", "湖南",
    "广西", "海南", "四川", "贵州", "云南", "西藏",
    "陕西", "甘肃", "青海", "宁夏", "新疆",
    "河北", "山西", "辽宁", "吉林", "黑龙江",
    "内蒙古", "香港", "澳门", "台湾"
};

MemberInfo::MemberInfo()
{

}

MemberInfo::MemberInfo(QStringList text_list)
{
    this->person.name = new QTableWidgetItem(text_list[NAME_INDEX]);
    this->person.age = new QTableWidgetItem(text_list[AGE_INDEX]);
    this->person.sex = new QTableWidgetItem(text_list[SEX_INDEX]);
    this->person.combo = new QComboBox;
    this->person.combo->addItems(provinces);
    this->person.combo->setCurrentText(text_list[BIRTH_INDEX]);
    this->person.combo->setEnabled(false);
    this->person.btn=new QPushButton;
    this->person.btn->setText(text_list[AVATOR_INDEX]);
}



bool MemberInfo::getShot()
{
    return this->shot;
};

Person MemberInfo::getPerson()
{
    return person;
}


void MemberInfo::setShot(bool status)
{
    this->shot = status;
}


