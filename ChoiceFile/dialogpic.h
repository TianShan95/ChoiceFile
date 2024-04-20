#ifndef DIALOGPIC_H
#define DIALOGPIC_H

#include <QDialog>

namespace Ui {
class DialogPic;
}

class DialogPic : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPic(QString picPath, QWidget *parent = nullptr);

    ~DialogPic();


private:
    Ui::DialogPic *ui;
    QString picPath;
};

#endif // DIALOGPIC_H
