/*
   SPDX-FileCopyrightText: 2019-2023 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QObject>

class DKIMRuleTest : public QObject
{
    Q_OBJECT
public:
    explicit DKIMRuleTest(QObject *parent = nullptr);
    ~DKIMRuleTest() override = default;
private Q_SLOTS:
    void shouldHaveDefaultValues();
};
