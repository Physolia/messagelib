/*
   SPDX-FileCopyrightText: 2019-2023 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QObject>

class ConvertVariablesJobTest : public QObject
{
    Q_OBJECT
public:
    explicit ConvertVariablesJobTest(QObject *parent = nullptr);
    ~ConvertVariablesJobTest() override = default;
private Q_SLOTS:
    void shouldHaveDefaultValues();
    void shouldCanStart();
    void shouldConvertVariables();
    void shouldConvertVariables_data();
};
