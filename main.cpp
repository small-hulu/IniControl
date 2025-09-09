#include "IniControl.h"
#include <QWidget>
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //验证
    using namespace CONTROLLER;
    auto&& ini = IniControl::instance();
    QString sys_version = ini[KI::version_].toString();
    QString info = ini[KI::changelog].toString();

    //显示
    QWidget window;
    window.setWindowTitle("System Version");
    QLabel *label = new QLabel("SysVersion: " + info, &window);
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(100, 100, 400, 100);
    window.resize(600, 300);

    window.show();

    return a.exec();
}
