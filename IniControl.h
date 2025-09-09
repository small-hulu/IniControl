#ifndef INICONTROL_H
#define INICONTROL_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QSettings>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
namespace CONTROLLER {

namespace KI {
const char* const Path_IniFolder = "./";       ///文件存放目录
const char* const Path_IniFile   = "system_version.ini";

const QString SVersion    = "SVersion";
const QString version_ = SVersion + QString("/version_");
const QString equipment_ = SVersion + QString("/equipment_");
const QString software_type = SVersion + QString("/software_type");
const QString changelog_ = SVersion + QString("/changelog_");

}


class IniControl {
public:
    using Self = IniControl;
    static Self &instance() {
        static Self ini{};
        return ini;
    }

private:
    QScopedPointer<QSettings> m_ini;

public:
    IniControl();

public:
    QString to_string() const {
        QJsonObject json;
        for (auto key : m_ini->allKeys()) {
            json[key] = m_ini->value(key).toString();
        }
        return QString::fromUtf8(QJsonDocument(json).toJson(QJsonDocument::Indented));
    }

public:
    void setValue(const QString &key, QVariant var) {
        qInfo() << QString("%1 = [%2] -> [%3]")
                   .arg(key)
                   .arg(m_ini->value(key).toString())
                   .arg(var.toString());
        m_ini->setValue(key, var);
        m_ini->sync();
    }

    inline QString to_absoluteFilePath(const QString& path) {
        return QFileInfo(QCoreApplication::applicationDirPath(), path).absoluteFilePath();
    }

    QVariant operator[](const QString &key) {
        return m_ini->value(key);
    }
};
}  // namespace CONTROLLER

#endif  // INICONTROL_H
