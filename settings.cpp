#include "settings.h"

#include <QtCore/QCoreApplication>

Settings::Settings()
{
    settings_ = new QSettings ("freelance_helper.ini",QSettings::IniFormat,
                               qApp);
}

Settings *Settings::instance()
{
    static Settings instance_;
    return &instance_;
}

QVariant Settings::value(const QString &key, const QVariant &defaultValue) const
{
    return settings_->value(key, defaultValue);
}

void Settings::setValue(const QString &key, const QVariant &value)
{
    settings_->setValue(key, value);
}

void Settings::sync()
{
    return  settings_->sync();
}

