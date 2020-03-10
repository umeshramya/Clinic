#ifndef SETTINGS_H
#define SETTINGS_H
#include "QString"
#include "QDir"
//Singleton class
class Settings
{

    static Settings* instance;
    Settings(){};
    QString DataBaseConnectionString = QString("E:/ClinicRecords/clinic/Database/clinicrecords.db");
    QString TemplateFolderPath = QString(QDir::homePath() + "/ClinicRecords/Template");
    int LetterPadHeaderHeight = 7;//lines
    QString LetterpadType = "A5";


public:

    static Settings* getInstance();


    QString getDataBaseConnectionString() const;
    void setDataBaseConnectionString(const QString &value);
    QString getTemplateFolderPath() const;
    void setTemplateFolderPath(const QString &value);
    int getLetterPadHeaderHeight() const;
    void setLetterPadHeaderHeight(int value);
    QString getLetterpadType() const;
    void setLetterpadType(const QString &value);
};

#endif // SETTINGS_H
