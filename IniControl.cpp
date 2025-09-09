#include "IniControl.h"

#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <mutex>
#include <QTextCodec>
namespace CONTROLLER {
IniControl::IniControl() {

    static std::once_flag flag;
    std::call_once(flag, [this]() {
        QString path = to_absoluteFilePath(KI::Path_IniFolder);
        QDir().mkpath(path);
        path = QDir(path).filePath(KI::Path_IniFile);

        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
        m_ini.reset(new QSettings(path, QSettings::IniFormat));
        m_ini->setIniCodec("UTF-8");

    });

    {
        QSettings::SettingsMap smap;
        //无文件时的默认值
        smap[KI::version_] = "V1.0.1.0 2025-9-9";
        smap[KI::equipment_] = "PMDT9810";
        smap[KI::software_type] = "通用";
        smap[KI::changelog_] = "测试ini实例";
        for (auto it = smap.begin(); it != smap.end(); it += 1) {
            auto key  = it.key();
            auto data = it.value();
            if (m_ini->contains(key) == false) {
                m_ini->setValue(key, data);
            }
        }
        m_ini->sync();
    }
}

}  // namespace CONTROLLER
