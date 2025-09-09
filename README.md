# 普迈德通用INI文件访问API

本项目为普迈德全设备提供一款通用的INI文件访问API，旨在简化系统中配置文件的读取和写入操作。

## 背景
解决系统版本号传递问题,云平台将自动生成 system_version.ini 文件，该文件包含软件的部分版本信息。该API将能够方便地使设备软件读取和更新此INI文件中的相关数据。

## 功能概述

- 提供简单的接口访问INI文件内容。
- 支持读取和修改INI文件中的版本信息。
- 生成和更新`system_version.ini`文件。
  
## system_version.ini 文件示例

`system_version.ini` 文件示例如下：

```ini
[SVersion]
equipment_=PMDT9810
version_=V1.0.1.0 2025-10-10
changelog=测试ini实例无理要求
software_type=通用


