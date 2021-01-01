/*
   SPDX-FileCopyrightText: 2018-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef DKIMMANAGERKEYWIDGETTEST_H
#define DKIMMANAGERKEYWIDGETTEST_H

#include <QObject>

class DKIMManagerKeyWidgetTest : public QObject
{
    Q_OBJECT
public:
    explicit DKIMManagerKeyWidgetTest(QObject *parent = nullptr);
    ~DKIMManagerKeyWidgetTest() = default;
private Q_SLOTS:
    void shouldHaveDefaultValue();
};

#endif // DKIMMANAGERKEYWIDGETTEST_H
