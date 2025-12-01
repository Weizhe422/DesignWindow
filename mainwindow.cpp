#include "mainwindow.h"
#include"ui_ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    
    // 美化功能表列
    QString menuStyle = R"(
        QMenuBar {
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                        stop:0 #4a90d9, stop:1 #357abd);
            border-bottom: 2px solid #2a5a8a;
            padding: 2px;
        }
        QMenuBar::item {
            background: transparent;
            color: white;
            padding: 8px 16px;
            border-radius: 4px;
            margin: 2px;
            font-weight: bold;
        }
        QMenuBar::item:selected {
            background: rgba(255, 255, 255, 0.2);
        }
        QMenuBar::item:pressed {
            background: rgba(255, 255, 255, 0.3);
        }
        QMenu {
            background-color: #ffffff;
            border: 1px solid #c0c0c0;
            border-radius: 4px;
            padding: 4px 0px;
        }
        QMenu::item {
            padding: 8px 30px;
            color: #333333;
        }
        QMenu::item:selected {
            background-color: #4a90d9;
            color: white;
        }
        QMenu::separator {
            height: 1px;
            background-color: #e0e0e0;
            margin: 4px 10px;
        }
    )";
    
    menubar->setStyleSheet(menuStyle);
}

MainWindow::~MainWindow() {}
