#ifndef FRMSETTING_H
#define FRMSETTING_H

#include <QDialog>

namespace Ui {
class FrmSetting;
}

class FrmSetting : public QDialog
{
    Q_OBJECT

public:
    explicit FrmSetting(QWidget *parent = nullptr);
    ~FrmSetting();

private:
    Ui::FrmSetting *ui;
};

#endif // FRMSETTING_H
