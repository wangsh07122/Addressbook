# Addressbook
个人通讯录管理系统
基于 C++ 与 Qt 开发的桌面端个人通讯录管理系统，用于管理、检索及维护各类日常联系人信息。
核心功能
联系人管理：支持添加、修改、删除和查看联系人详细信息。
分类维护：支持按不同联系人类型（如同事、朋友、同学等）进行分类与快速筛选。
数据统计：支持按月份统计生日人数等实用功能。
数据持久化：支持将联系人信息自动保存至本地数据文件（.txt），并在启动时读取。
开发环境与依赖
编程语言：C++
GUI 框架：Qt (Qt 5 / Qt 6)
开发工具 / IDE：Visual Studio (已配置 Qt VS Tools 扩展)
编译器：MSVC
项目主要结构
addressbook.cpp / addressbook.h：主窗口界面与主要业务逻辑控制
AddDialog.cpp / AddDialog.h / AddDialog.ui：添加联系人对话框界面及交互逻辑
ModifyDialog.cpp / ModifyDialog.h：修改联系人信息对话框逻辑
colleague.h：联系人类与派生数据结构定义
addressbook.sln / addressbook.vcxproj：Visual Studio 工程与解决方案配置
AddressBook*.txt：本地联系人数据存储文件
编译与运行说明
1 克隆或下载本仓库源码到本地。
2 使用 Visual Studio 打开根目录下的 addressbook.sln 文件。
3 确保 Visual Studio 已正确加载 Qt VS Tools 并配置了对应的 Qt 版本。
4 切换构建模式为 Debug 或 Release（x64 / x86）。
5 点击 本地 Windows 调试器（快捷键 F5）直接编译并运行项目。
