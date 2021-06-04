/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *imageLabel_;
    QLabel *infoLabel_;
    QPushButton *captureButton_;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1174, 711);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        imageLabel_ = new QLabel(Widget);
        imageLabel_->setObjectName(QString::fromUtf8("imageLabel_"));
        imageLabel_->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(imageLabel_);

        infoLabel_ = new QLabel(Widget);
        infoLabel_->setObjectName(QString::fromUtf8("infoLabel_"));
        infoLabel_->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(infoLabel_);

        captureButton_ = new QPushButton(Widget);
        captureButton_->setObjectName(QString::fromUtf8("captureButton_"));

        verticalLayout->addWidget(captureButton_);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        imageLabel_->setText(QCoreApplication::translate("Widget", "No image", nullptr));
        infoLabel_->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        captureButton_->setText(QCoreApplication::translate("Widget", "Capture Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
