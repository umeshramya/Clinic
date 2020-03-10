#include "frmsetting.h"
#include "ui_frmsetting.h"
#include "Classes/settings.h"
#include "QFile"
#include "QDebug"
#include "QTextStream"

FrmSetting::FrmSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmSetting)
{
    ui->setupUi(this);
    Settings* setting = Settings::getInstance();


    QFile settingFile("settingFile.txt");//create file inside direct

    if(!settingFile.open(QFile::ReadOnly| QFile::Text)){//check for if exist
        settingFile.open(QFile::WriteOnly | QFile::Text);//if not exist create new file with defualt6 parametrs
        QTextStream out(&settingFile);//set write stream for file
        QString fileData =QString(setting->getDataBaseConnectionString() + "\n");
        fileData.append(setting->getTemplateFolderPath() + "\n");
        fileData.append(QString::number(setting->getLetterPadHeaderHeight()) + "\n");
        fileData.append(setting->getLetterpadType() + "\n");
        out << fileData;
        settingFile.flush();//flush after writing into file
        settingFile.close();//close file

    }else{//if file exist read the content
        QTextStream in(&settingFile);//create reading stream
        setting->setDataBaseConnectionString(in.readLine());//read line by line
        setting->setTemplateFolderPath(in.readLine());
        setting->setLetterPadHeaderHeight(in.readLine().toInt());
        setting->setLetterpadType(in.readLine());
        settingFile.close();

    }






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
    ui->comboBox_LetterPadType->setCurrentText(setting->getLetterpadType());





}

FrmSetting::~FrmSetting()
{
    delete ui;
}
