#ifndef DIALOGEDITNAME_H
#define DIALOGEDITNAME_H

#include <QDialog>
#include <QPushButton> // 包含 QPushButton 的头文件

namespace Ui {
class DialogEditName;
}

class DialogEditName : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditName(QWidget *parent = nullptr);
    ~DialogEditName();

private slots:
    void on_buttonBox_accepted();
    
private:
    Ui::DialogEditName *ui;

signals:
    void textEntered(const QString &text);

};

#endif // DIALOGEDITNAME_H
