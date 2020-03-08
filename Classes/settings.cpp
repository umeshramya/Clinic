#include "settings.h"


QString Settings::getTemplateFolderPath() const
{
    return TemplateFolderPath;
}

void Settings::setTemplateFolderPath(const QString &value)
{
    TemplateFolderPath = value;
}

int Settings::getLetterPadHeaderHeight() const
{
    return LetterPadHeaderHeight;
}

void Settings::setLetterPadHeaderHeight(int value)
{
    LetterPadHeaderHeight = value;
}

Settings *Settings::getInstance()
{
    if(!instance){
        instance = new Settings;
    }
    return instance;
}

QString Settings::getDataBaseConnectionString() const
{
    return DataBaseConnectionString;
}

void Settings::setDataBaseConnectionString(const QString &value)
{
    DataBaseConnectionString = value;
}

Settings* Settings::instance = 0;
