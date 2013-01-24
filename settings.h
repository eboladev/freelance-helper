#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore/QVariant>
#include <QtCore/QPointer>
#include <QtCore/QSettings>

class Settings
{
public:
    Settings();
    static Settings *instance();

    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;
    void setValue(const QString &key, const QVariant &value);
    void sync();

private:
    QPointer<QSettings> settings_;
};

#endif // SETTINGS_H
