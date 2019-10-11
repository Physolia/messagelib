/*
   Copyright (C) 2019 Laurent Montel <montel@kde.org>

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

#include "dkimwidgetinfotest.h"
#include "dkim-verify/dkimwidgetinfo.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QTest>

QTEST_MAIN(DKIMWidgetInfoTest)
DKIMWidgetInfoTest::DKIMWidgetInfoTest(QObject *parent)
    : QObject(parent)
{
}

void DKIMWidgetInfoTest::shouldHaveDefaultValues()
{
    MessageViewer::DKIMWidgetInfo w;
    QHBoxLayout *mainLayout = w.findChild<QHBoxLayout *>(QStringLiteral("mainlayout"));
    QVERIFY(mainLayout);
    QCOMPARE(mainLayout->contentsMargins(), QMargins(0, 0, 0, 0));

    QLabel *mLabel = w.findChild<QLabel *>(QStringLiteral("label"));
    QVERIFY(mLabel);
    QVERIFY(mLabel->text().isEmpty());
}