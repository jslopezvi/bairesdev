/********************************************************************************
** Form generated from reading UI file 'potentialsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POTENTIALSEARCH_H
#define UI_POTENTIALSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BairesWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *vboxLayout;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout1;
    QTableView *customersTable;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *executeQueryButton;
    QLabel *label;
    QComboBox *filterByCombo;
    QPushButton *rankButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QTableView *resultsTable;

    void setupUi(QMainWindow *BairesWindow)
    {
        if (BairesWindow->objectName().isEmpty())
            BairesWindow->setObjectName(QStringLiteral("BairesWindow"));
        BairesWindow->resize(644, 420);
        centralWidget = new QWidget(BairesWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        vboxLayout = new QVBoxLayout(centralWidget);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QStringLiteral("vboxLayout"));
        vboxLayout->setContentsMargins(9, 9, 9, 9);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        vboxLayout1 = new QVBoxLayout(groupBox);
        vboxLayout1->setSpacing(6);
        vboxLayout1->setObjectName(QStringLiteral("vboxLayout1"));
        vboxLayout1->setContentsMargins(9, 9, 9, 9);
        customersTable = new QTableView(groupBox);
        customersTable->setObjectName(QStringLiteral("customersTable"));
        customersTable->setSelectionBehavior(QAbstractItemView::SelectRows);

        vboxLayout1->addWidget(customersTable);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(groupBox_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);


        vboxLayout1->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        executeQueryButton = new QPushButton(groupBox);
        executeQueryButton->setObjectName(QStringLiteral("executeQueryButton"));

        horizontalLayout->addWidget(executeQueryButton);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        filterByCombo = new QComboBox(groupBox);
        filterByCombo->setObjectName(QStringLiteral("filterByCombo"));

        horizontalLayout->addWidget(filterByCombo);

        rankButton = new QPushButton(groupBox);
        rankButton->setObjectName(QStringLiteral("rankButton"));

        horizontalLayout->addWidget(rankButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        vboxLayout1->addLayout(horizontalLayout);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        resultsTable = new QTableView(groupBox_3);
        resultsTable->setObjectName(QStringLiteral("resultsTable"));

        verticalLayout_2->addWidget(resultsTable);


        vboxLayout1->addWidget(groupBox_3);


        vboxLayout->addWidget(groupBox);

        BairesWindow->setCentralWidget(centralWidget);

        retranslateUi(BairesWindow);

        QMetaObject::connectSlotsByName(BairesWindow);
    } // setupUi

    void retranslateUi(QMainWindow *BairesWindow)
    {
        BairesWindow->setWindowTitle(QApplication::translate("BairesWindow", "BairesDev Potential Customer Search", 0));
        groupBox->setTitle(QApplication::translate("BairesWindow", "BairesDev Potential Customer Search", 0));
        groupBox_2->setTitle(QApplication::translate("BairesWindow", "SQL Query", 0));
        executeQueryButton->setText(QApplication::translate("BairesWindow", "Execute Query", 0));
        label->setText(QApplication::translate("BairesWindow", "Select your industry of interest (ordered by industry size):", 0));
        rankButton->setText(QApplication::translate("BairesWindow", "Rank Potential Customers", 0));
        groupBox_3->setTitle(QApplication::translate("BairesWindow", "Results", 0));
    } // retranslateUi

};

namespace Ui {
    class BairesWindow: public Ui_BairesWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POTENTIALSEARCH_H
