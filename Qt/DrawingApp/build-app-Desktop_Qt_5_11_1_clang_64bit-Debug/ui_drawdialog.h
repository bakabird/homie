/********************************************************************************
** Form generated from reading UI file 'drawdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAWDIALOG_H
#define UI_DRAWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DrawDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DrawDialog)
    {
        if (DrawDialog->objectName().isEmpty())
            DrawDialog->setObjectName(QStringLiteral("DrawDialog"));
        DrawDialog->resize(217, 222);
        DrawDialog->setModal(false);
        verticalLayout_2 = new QVBoxLayout(DrawDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);

        verticalLayout_2->addLayout(formLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(DrawDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(DrawDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), DrawDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DrawDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DrawDialog);
    } // setupUi

    void retranslateUi(QDialog *DrawDialog)
    {
        DrawDialog->setWindowTitle(QApplication::translate("DrawDialog", "Draw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DrawDialog: public Ui_DrawDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAWDIALOG_H
