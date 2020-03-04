#ifndef SETTINGS_H
#define SETTINGS_H
#include "QString"

class Settings
{
    static QString DataBaseConnectionString;
    static QString TemplateFolderPath;
    static int LetterPadHeaderHeight;//lines


public:
    Settings();

    QString getDataBaseConnectionString();
    void setDataBaseConnectionString(const QString value);

    QString getTemplateFolderPath();
    void setTemplateFolderPath(const QString value);

    int getLetterPadHeaderHeight();
    void setLetterPadHeaderHeight(int value);
};

#endif // SETTINGS_H
