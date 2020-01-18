/*
   Copyright (C) 2019-2020 Laurent Montel <montel@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#include "dkimrulewidgettest.h"
#include "dkim-verify/dkimrulewidget.h"
#include "dkim-verify/dkimmanagerulescombobox.h"
#include <QCheckBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QTest>

QTEST_MAIN(DKIMRuleWidgetTest)
DKIMRuleWidgetTest::DKIMRuleWidgetTest(QObject *parent)
    : QObject(parent)
{
}

void DKIMRuleWidgetTest::shouldHaveDefaultValues()
{
    MessageViewer::DKIMRuleWidget w;
    QVERIFY(!w.rule().isValid());

    QFormLayout *layout = w.findChild<QFormLayout *>(QStringLiteral("layout"));
    QCOMPARE(layout->contentsMargins(), QMargins(0, 0, 0, 0));

    QCheckBox *mEnabled = w.findChild<QCheckBox *>(QStringLiteral("enabled"));
    QVERIFY(mEnabled);
    QVERIFY(!mEnabled->text().isEmpty());
    QVERIFY(mEnabled->isChecked());

    QLineEdit *mDomain = w.findChild<QLineEdit *>(QStringLiteral("domain"));
    QVERIFY(mDomain);
    QVERIFY(mDomain->text().isEmpty());
    QVERIFY(mDomain->isClearButtonEnabled());

    QLineEdit *mListId = w.findChild<QLineEdit *>(QStringLiteral("listid"));
    QVERIFY(mListId);
    QVERIFY(mListId->text().isEmpty());
    QVERIFY(mListId->isClearButtonEnabled());

    QLineEdit *mFrom = w.findChild<QLineEdit *>(QStringLiteral("from"));
    QVERIFY(mFrom);
    QVERIFY(mFrom->text().isEmpty());
    QVERIFY(mFrom->isClearButtonEnabled());

    QLineEdit *mSignatureDomainIdentifier = w.findChild<QLineEdit *>(QStringLiteral("signaturedomainidentifier"));
    QVERIFY(mSignatureDomainIdentifier);
    QVERIFY(mSignatureDomainIdentifier->text().isEmpty());
    QVERIFY(mSignatureDomainIdentifier->isClearButtonEnabled());

    MessageViewer::DKIMManageRulesComboBox *mRuleType = w.findChild<MessageViewer::DKIMManageRulesComboBox *>(QStringLiteral("ruletype"));
    QVERIFY(mRuleType);

    QSpinBox *mPriority = w.findChild<QSpinBox *>(QStringLiteral("priority"));
    QVERIFY(mPriority);
    QCOMPARE(mPriority->value(), 1000);
}
