#include "frmsetting.h"
#include "ui_frmsetting.h"
#include "Classes/settings.h"

FrmSetting::FrmSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmSetting)
{
    ui->setupUi(this);
    Settings* setting = Settings::getInstance();
    ui->lineEdi_databaseConnection->setText(setting->getDataBaseConnectionString());
    ui->lineEdit_TemplateFolderPath->setText(setting->getTemplateFolderPath());
    ui->spinBox_LetterpadHeaderLines->setValue(setting->getLetterPadHeaderHeight());
    QString LetterpadType[7] ={"A4", "A5", "A3"};
    for (int i =0;i<LetterpadType->length();i++) {
        ui->comboBox_LetterPadType->addItem(LetterpadType[i]);

    }






}

FrmSetting::~FrmSetting()
{
    delete ui;
}
