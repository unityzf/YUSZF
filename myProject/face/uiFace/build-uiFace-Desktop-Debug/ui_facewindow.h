/********************************************************************************
** Form generated from reading UI file 'facewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEWINDOW_H
#define UI_FACEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_faceWindow
{
public:
    QWidget *centralWidget;
    QLabel *picShow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *faceWindow)
    {
        if (faceWindow->objectName().isEmpty())
            faceWindow->setObjectName(QStringLiteral("faceWindow"));
        faceWindow->resize(773, 513);
        centralWidget = new QWidget(faceWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        picShow = new QLabel(centralWidget);
        picShow->setObjectName(QStringLiteral("picShow"));
        picShow->setGeometry(QRect(130, 40, 511, 361));
        faceWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(faceWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 773, 26));
        faceWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(faceWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        faceWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(faceWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        faceWindow->setStatusBar(statusBar);

        retranslateUi(faceWindow);

        QMetaObject::connectSlotsByName(faceWindow);
    } // setupUi

    void retranslateUi(QMainWindow *faceWindow)
    {
        faceWindow->setWindowTitle(QApplication::translate("faceWindow", "faceWindow", Q_NULLPTR));
        picShow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class faceWindow: public Ui_faceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEWINDOW_H
