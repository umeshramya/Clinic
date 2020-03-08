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




}

FrmSetting::~FrmSetting()
{
    delete ui;
}
