#include "mainwindow.h"
#include"ui_ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    
    // 美化功能表列 - 夜間模式暗黑風格
    QString menuStyle = R"(
        QMenuBar {
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1,
                                        stop:0 #2d2d2d, stop:1 #1a1a1a);
            border-bottom: 2px solid #3d3d3d;
            padding: 2px;
        }
        QMenuBar::item {
            background: transparent;
            color: #e0e0e0;
            padding: 8px 16px;
            border-radius: 4px;
            margin: 2px;
            font-weight: bold;
        }
        QMenuBar::item:selected {
            background: rgba(255, 255, 255, 0.1);
            color: #ffffff;
        }
        QMenuBar::item:pressed {
            background: rgba(255, 255, 255, 0.15);
        }
        QMenu {
            background-color: #2d2d2d;
            border: 1px solid #3d3d3d;
            border-radius: 4px;
            padding: 4px 0px;
        }
        QMenu::item {
            padding: 8px 30px;
            color: #e0e0e0;
        }
        QMenu::item:selected {
            background-color: #404040;
            color: #ffffff;
        }
        QMenu::separator {
            height: 1px;
            background-color: #3d3d3d;
            margin: 4px 10px;
        }
    )";
    
    menubar->setStyleSheet(menuStyle);
}

MainWindow::~MainWindow() {}
