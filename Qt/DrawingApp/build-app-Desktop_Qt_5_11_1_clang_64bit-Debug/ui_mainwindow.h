/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCircle;
    QAction *actionRectangle;
    QAction *actionLine;
    QAction *actionDrawCircle;
    QAction *actionSelectionTool;
    QAction *actionDrawRectangle;
    QAction *actionDrawLine;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionDelete;
    QAction *actionBring_To_Front;
    QAction *actionSend_to_Back;
    QAction *actionBring_Forward;
    QAction *actionSend_Backward;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionNew;
    QAction *actionAbout_me_3;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDraw;
    QMenu *menuEdit;
    QMenu *menuArrange;
    QMenu *menuAbout;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *VEProp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(683, 352);
        MainWindow->setFocusPolicy(Qt::ClickFocus);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName(QStringLiteral("actionCircle"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/resource/CircleIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon);
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QStringLiteral("actionRectangle"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/resource/RectangleIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon1);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName(QStringLiteral("actionLine"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/resource/LineIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon2);
        actionDrawCircle = new QAction(MainWindow);
        actionDrawCircle->setObjectName(QStringLiteral("actionDrawCircle"));
        actionDrawCircle->setCheckable(true);
        actionDrawCircle->setIcon(icon);
        actionSelectionTool = new QAction(MainWindow);
        actionSelectionTool->setObjectName(QStringLiteral("actionSelectionTool"));
        actionSelectionTool->setCheckable(true);
        actionSelectionTool->setChecked(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/resource/CursorIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelectionTool->setIcon(icon3);
        actionDrawRectangle = new QAction(MainWindow);
        actionDrawRectangle->setObjectName(QStringLiteral("actionDrawRectangle"));
        actionDrawRectangle->setCheckable(true);
        actionDrawRectangle->setIcon(icon1);
        actionDrawLine = new QAction(MainWindow);
        actionDrawLine->setObjectName(QStringLiteral("actionDrawLine"));
        actionDrawLine->setCheckable(true);
        actionDrawLine->setIcon(icon2);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/resource/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon4);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/resource/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon5);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Icons/resource/trash_can.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon6);
        actionBring_To_Front = new QAction(MainWindow);
        actionBring_To_Front->setObjectName(QStringLiteral("actionBring_To_Front"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Icons/resource/bringToFront.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBring_To_Front->setIcon(icon7);
        actionSend_to_Back = new QAction(MainWindow);
        actionSend_to_Back->setObjectName(QStringLiteral("actionSend_to_Back"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Icons/resource/sendToBack.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSend_to_Back->setIcon(icon8);
        actionBring_Forward = new QAction(MainWindow);
        actionBring_Forward->setObjectName(QStringLiteral("actionBring_Forward"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Icons/resource/bringForward.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBring_Forward->setIcon(icon9);
        actionSend_Backward = new QAction(MainWindow);
        actionSend_Backward->setObjectName(QStringLiteral("actionSend_Backward"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Icons/resource/sendBackward.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSend_Backward->setIcon(icon10);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Icons/resource/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon11);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Icons/resource/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon12);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Icons/resource/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon13);
        actionAbout_me_3 = new QAction(MainWindow);
        actionAbout_me_3->setObjectName(QStringLiteral("actionAbout_me_3"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 683, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDraw = new QMenu(menuBar);
        menuDraw->setObjectName(QStringLiteral("menuDraw"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuArrange = new QMenu(menuBar);
        menuArrange->setObjectName(QStringLiteral("menuArrange"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setFocusPolicy(Qt::ClickFocus);
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setFocusPolicy(Qt::ClickFocus);
        dockWidget->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        VEProp = new QFormLayout();
        VEProp->setSpacing(6);
        VEProp->setObjectName(QStringLiteral("VEProp"));

        verticalLayout_2->addLayout(VEProp);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuArrange->menuAction());
        menuBar->addAction(menuDraw->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionExit);
        menuDraw->addAction(actionCircle);
        menuDraw->addAction(actionRectangle);
        menuDraw->addAction(actionLine);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionDelete);
        menuArrange->addAction(actionBring_To_Front);
        menuArrange->addAction(actionSend_to_Back);
        menuArrange->addAction(actionBring_Forward);
        menuArrange->addAction(actionSend_Backward);
        menuAbout->addAction(actionAbout_me_3);
        menuAbout->addAction(actionAbout_Qt);
        toolBar->addAction(actionSelectionTool);
        toolBar->addAction(actionDrawRectangle);
        toolBar->addAction(actionDrawCircle);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Drawing App", nullptr));
        actionCircle->setText(QApplication::translate("MainWindow", "Circle", nullptr));
#ifndef QT_NO_STATUSTIP
        actionCircle->setStatusTip(QApplication::translate("MainWindow", "Draw a Circle", nullptr));
#endif // QT_NO_STATUSTIP
        actionRectangle->setText(QApplication::translate("MainWindow", "Rectangle", nullptr));
#ifndef QT_NO_STATUSTIP
        actionRectangle->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionLine->setText(QApplication::translate("MainWindow", "Line", nullptr));
        actionDrawCircle->setText(QApplication::translate("MainWindow", "DrawCircle", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDrawCircle->setToolTip(QApplication::translate("MainWindow", "Draw Circle", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDrawCircle->setStatusTip(QApplication::translate("MainWindow", "Click-drag to begin drawing; click on canvas to show Circle Draw Dialog", nullptr));
#endif // QT_NO_STATUSTIP
        actionSelectionTool->setText(QApplication::translate("MainWindow", "SelectionTool", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSelectionTool->setToolTip(QApplication::translate("MainWindow", "Selection Tool", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSelectionTool->setStatusTip(QApplication::translate("MainWindow", "Click to select; Shift-Select for multiple select", nullptr));
#endif // QT_NO_STATUSTIP
        actionDrawRectangle->setText(QApplication::translate("MainWindow", "DrawRectangle", nullptr));
#ifndef QT_NO_STATUSTIP
        actionDrawRectangle->setStatusTip(QApplication::translate("MainWindow", "Click-drag to begin drawing; click on canvas to show Rectangle Draw Dialog", nullptr));
#endif // QT_NO_STATUSTIP
        actionDrawLine->setText(QApplication::translate("MainWindow", "actionDrawLine", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDrawLine->setToolTip(QApplication::translate("MainWindow", "Draw Line", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionDrawLine->setStatusTip(QApplication::translate("MainWindow", "Click to draw 1st point, click again to finish it.", nullptr));
#endif // QT_NO_STATUSTIP
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_NO_SHORTCUT
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
#ifndef QT_NO_SHORTCUT
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_NO_SHORTCUT
        actionBring_To_Front->setText(QApplication::translate("MainWindow", "Bring to Front", nullptr));
        actionSend_to_Back->setText(QApplication::translate("MainWindow", "Send to Back", nullptr));
        actionBring_Forward->setText(QApplication::translate("MainWindow", "Bring Forward", nullptr));
#ifndef QT_NO_SHORTCUT
        actionBring_Forward->setShortcut(QApplication::translate("MainWindow", "Ctrl+}", nullptr));
#endif // QT_NO_SHORTCUT
        actionSend_Backward->setText(QApplication::translate("MainWindow", "Send Backward", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSend_Backward->setShortcut(QApplication::translate("MainWindow", "Ctrl+{", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout_me_3->setText(QApplication::translate("MainWindow", "About me :3", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt...", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuDraw->setTitle(QApplication::translate("MainWindow", "Draw", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuArrange->setTitle(QApplication::translate("MainWindow", "Arrange", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "Properties", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
