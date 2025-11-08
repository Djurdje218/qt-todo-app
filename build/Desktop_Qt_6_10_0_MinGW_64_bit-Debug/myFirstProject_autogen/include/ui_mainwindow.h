/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *taskInput;
    QSpacerItem *verticalSpacer_2;
    QPushButton *addButton;
    QPushButton *removeButton;
    QSpacerItem *verticalSpacer;
    QPushButton *removeAllButton;
    QListWidget *taskList;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(493, 329);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        taskInput = new QLineEdit(centralwidget);
        taskInput->setObjectName("taskInput");
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        taskInput->setFont(font);
        taskInput->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        taskInput->setAutoFillBackground(false);
        taskInput->setStyleSheet(QString::fromUtf8("#taskInput {\n"
"    padding: 4px;\n"
"    border: 1px solid #555;\n"
"    border-radius: 4px;\n"
"    background: #2b2b2b;\n"
"    color: #f0f0f0;              /* color */\n"
"    selection-background-color: #3d7cff;\n"
"}\n"
""));
        taskInput->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(taskInput);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        verticalLayout->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        verticalLayout->addWidget(removeButton);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        removeAllButton = new QPushButton(centralwidget);
        removeAllButton->setObjectName("removeAllButton");

        verticalLayout->addWidget(removeAllButton);


        horizontalLayout->addLayout(verticalLayout);

        taskList = new QListWidget(centralwidget);
        taskList->setObjectName("taskList");
        taskList->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

        horizontalLayout->addWidget(taskList);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 493, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        taskInput->setText(QString());
        taskInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter task", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        removeAllButton->setText(QCoreApplication::translate("MainWindow", "Remove All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
