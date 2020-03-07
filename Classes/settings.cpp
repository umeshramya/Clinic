#include "settings.h"
#include "QDir"

QString Settings::getDataBaseConnectionString()
{
    return DataBaseConnectionString;
}

void Settings::setDataBaseConnectionString(const QString value)
{
    DataBaseConnectionString = value;
}

QString Settings::getTemplateFolderPath()
{
    return TemplateFolderPath;
}

void Settings::setTemplateFolderPath(const QString value)
{
    TemplateFolderPath = value;
}

int Settings::getLetterPadHeaderHeight()
{
    return LetterPadHeaderHeight;
}

void Settings::setLetterPadHeaderHeight(int value)
{
    LetterPadHeaderHeight = value;
}

Settings::Settings()
{
    
}


QString Settings::DataBaseConnectionString = QString("E:/ClinicRecords/clinic/Database/clinicrecords.db");
QString Settings::TemplateFolderPath =QString(QDir::homePath() + "/ClinicRecords/Template");
int Settings::LetterPadHeaderHeight =7;
