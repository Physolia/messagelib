/*
  SPDX-FileCopyrightText: 2024-2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "searchlinecommandbuttonswidgettest.h"
#include "core/widgets/searchlinecommandbuttonswidget.h"
#include "core/widgets/searchlinecommandflowlayout.h"
#include <QTest>
QTEST_MAIN(SearchLineCommandButtonsWidgetTest)

SearchLineCommandButtonsWidgetTest::SearchLineCommandButtonsWidgetTest(QObject *parent)
    : QObject{parent}
{
}

void SearchLineCommandButtonsWidgetTest::shouldHaveDefaultValues()
{
    MessageList::Core::SearchLineCommandButtonsWidget w;

    auto flowLayout = w.findChild<MessageList::Core::SearchLineCommandFlowLayout *>(QStringLiteral("flowLayout"));
    QVERIFY(flowLayout);
    QCOMPARE(flowLayout->contentsMargins(), QMargins{});
    QCOMPARE(flowLayout->spacing(), 0);
    QCOMPARE(flowLayout->count(), 22);
    QCOMPARE(flowLayout->horizontalSpacing(), 0);
    QCOMPARE(flowLayout->verticalSpacing(), 0);
}

#include "moc_searchlinecommandbuttonswidgettest.cpp"
