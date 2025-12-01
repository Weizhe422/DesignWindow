/********************************************************************************
** Form generated from reading UI file 'ui_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_MAINWINDOW_H
#define UI_UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_N;
    QAction *action_O;
    QAction *action_C;
    QAction *action_S;
    QAction *action_A;
    QAction *action_X;
    QAction *action_U;
    QAction *action_T;
    QAction *action_C_2;
    QAction *action_A_2;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu_E;
    QMenu *menu_E_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action_N = new QAction(MainWindow);
        action_N->setObjectName("action_N");
        action_O = new QAction(MainWindow);
        action_O->setObjectName("action_O");
        action_C = new QAction(MainWindow);
        action_C->setObjectName("action_C");
        action_S = new QAction(MainWindow);
        action_S->setObjectName("action_S");
        action_A = new QAction(MainWindow);
        action_A->setObjectName("action_A");
        action_X = new QAction(MainWindow);
        action_X->setObjectName("action_X");
        action_U = new QAction(MainWindow);
        action_U->setObjectName("action_U");
        action_T = new QAction(MainWindow);
        action_T->setObjectName("action_T");
        action_C_2 = new QAction(MainWindow);
        action_C_2->setObjectName("action_C_2");
        action_A_2 = new QAction(MainWindow);
        action_A_2->setObjectName("action_A_2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName("menu_E");
        menu_E_2 = new QMenu(menubar);
        menu_E_2->setObjectName("menu_E_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu_E_2->menuAction());
        menu_E->addAction(action_N);
        menu_E->addAction(action_O);
        menu_E->addAction(action_C);
        menu_E->addSeparator();
        menu_E->addAction(action_S);
        menu_E->addAction(action_A);
        menu_E->addSeparator();
        menu_E->addAction(action_X);
        menu_E_2->addAction(action_U);
        menu_E_2->addAction(action_T);
        menu_E_2->addAction(action_C_2);
        menu_E_2->addAction(action_A_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_N->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236(N)", nullptr));
#if QT_CONFIG(shortcut)
        action_N->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_O->setText(QCoreApplication::translate("MainWindow", "\351\226\213\345\225\237(O)", nullptr));
#if QT_CONFIG(shortcut)
        action_O->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        action_C->setText(QCoreApplication::translate("MainWindow", "\351\227\234\351\226\211(C)", nullptr));
        action_S->setText(QCoreApplication::translate("MainWindow", "\345\204\262\345\255\230(S)", nullptr));
#if QT_CONFIG(shortcut)
        action_S->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_A->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230(A)", nullptr));
        action_X->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272(X)", nullptr));
        action_U->setText(QCoreApplication::translate("MainWindow", "\351\202\204\345\216\237(U)", nullptr));
#if QT_CONFIG(shortcut)
        action_U->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_T->setText(QCoreApplication::translate("MainWindow", "\345\211\252\344\270\213(T)", nullptr));
#if QT_CONFIG(shortcut)
        action_T->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        action_C_2->setText(QCoreApplication::translate("MainWindow", "\350\244\207\350\243\275(C)", nullptr));
#if QT_CONFIG(shortcut)
        action_C_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        action_A_2->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\201\270(A)", nullptr));
#if QT_CONFIG(shortcut)
        action_A_2->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\346\252\224\346\241\210(E)", nullptr));
        menu_E_2->setTitle(QCoreApplication::translate("MainWindow", "\347\267\250\350\274\257(E)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_MAINWINDOW_H
