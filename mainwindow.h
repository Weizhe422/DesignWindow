#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"ui_ui_mainwindow.h"

class MainWindow : public QMainWindow,
                   public Ui_MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSaveTriggered();
    void onSaveAsTriggered();

private:
    QString currentFilePath;
    void saveToFile(const QString &filePath);
};
#endif // MAINWINDOW_H
