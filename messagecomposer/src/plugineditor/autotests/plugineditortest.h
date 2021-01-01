/*
   SPDX-FileCopyrightText: 2015-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef PLUGINEDITORTEST_H
#define PLUGINEDITORTEST_H

#include <QObject>

class PluginEditorTest : public QObject
{
    Q_OBJECT
public:
    explicit PluginEditorTest(QObject *parent = nullptr);
    ~PluginEditorTest() = default;
private Q_SLOTS:
    void shouldHaveDefaultValues();
};

#endif // PLUGINEDITORTEST_H
