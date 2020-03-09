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
    QStringList LetterpadType;
    LetterpadType.append("A1");
    LetterpadType.append("A2");
    LetterpadType.append("A3");
    LetterpadType.append("A4");
    LetterpadType.append("A5");
    LetterpadType.append("B3");
    LetterpadType.append("B4");


    ui->comboBox_LetterPadType->addItems(LetterpadType);


    ui->comboBox_LetterPadType->setCurrentText("A5");





}

FrmSetting::~FrmSetting()
{
    delete ui;
}
