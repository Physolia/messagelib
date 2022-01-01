/*
   SPDX-FileCopyrightText: 2019-2022 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include <QObject>

class ConvertSnippetVariablesUtilTest : public QObject
{
    Q_OBJECT
public:
    explicit ConvertSnippetVariablesUtilTest(QObject *parent = nullptr);
    ~ConvertSnippetVariablesUtilTest() override = default;
private Q_SLOTS:
    void shouldTranslateVariables();
};

