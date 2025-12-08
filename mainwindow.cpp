#include "mainwindow.h"
#include"ui_ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi(this);
    
    // 夜間模式暗黑風格 - 整個視窗背景
    QString windowStyle = R"(
        QMainWindow {
            background-color: #1e1e1e;
        }
        QWidget#centralwidget {
            background-color: #1e1e1e;
        }
        QStatusBar {
            background-color: #2d2d2d;
            color: #e0e0e0;
            border-top: 1px solid #3d3d3d;
        }
    )";
    this->setStyleSheet(windowStyle);
    
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
    
    // 文字編輯器暗黑風格
    QString textEditStyle = R"(
        QTextEdit {
            background-color: #1e1e1e;
            color: #e0e0e0;
            border: 1px solid #3d3d3d;
            selection-background-color: #404040;
            selection-color: #ffffff;
            font-family: "Consolas", "Monaco", "Courier New", monospace;
        }
    )";
    
    textEdit->setStyleSheet(textEditStyle);
    
    // 連接 Save 和 Save As 動作
    connect(action_S, &QAction::triggered, this, &MainWindow::onSaveTriggered);
    connect(action_A, &QAction::triggered, this, &MainWindow::onSaveAsTriggered);
}

MainWindow::~MainWindow() {}

void MainWindow::onSaveTriggered()
{
    if (currentFilePath.isEmpty()) {
        // 如果沒有當前檔案路徑，則呼叫另存為
        onSaveAsTriggered();
    } else {
        // 儲存到當前檔案
        saveToFile(currentFilePath);
    }
}

void MainWindow::onSaveAsTriggered()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("另存檔案"),
        "",
        tr("文字檔案 (*.txt);;所有檔案 (*.*)")
    );
    
    if (!fileName.isEmpty()) {
        saveToFile(fileName);
        currentFilePath = fileName;
    }
}

void MainWindow::saveToFile(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("儲存錯誤"), 
                           tr("無法儲存檔案: %1").arg(file.errorString()));
        return;
    }
    
    QTextStream out(&file);
    out << textEdit->toPlainText();
    file.close();
    
    statusbar->showMessage(tr("檔案已儲存: %1").arg(filePath), 3000);
}
