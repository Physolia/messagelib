/*
   SPDX-FileCopyrightText: 2014-2023 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "globalparttest.h"
#include <../src/part/globalpart.h>
#include <QTest>
GlobalPartTest::GlobalPartTest(QObject *parent)
    : QObject(parent)
{
}

GlobalPartTest::~GlobalPartTest() = default;

void GlobalPartTest::shouldHaveDefaultValue()
{
    MessageComposer::GlobalPart globalpart;
    QVERIFY(globalpart.isGuiEnabled());
    QVERIFY(!globalpart.parentWidgetForGui());
    QVERIFY(!globalpart.isFallbackCharsetEnabled());
    QVERIFY(!globalpart.is8BitAllowed());
    QVERIFY(!globalpart.MDNRequested());
    QVERIFY(!globalpart.requestDeleveryConfirmation());
}

QTEST_GUILESS_MAIN(GlobalPartTest)

#include "moc_globalparttest.cpp"
