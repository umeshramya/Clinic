#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>

namespace Ui {
class NewUser;
}

class NewUser : public QDialog
{
    Q_OBJECT

public:
    explicit NewUser(QWidget *parent = nullptr);
    ~NewUser();

private slots:
    void on_pushButton_newUser_clicked();

private:
    Ui::NewUser *ui;
};

#endif // NEWUSER_H
