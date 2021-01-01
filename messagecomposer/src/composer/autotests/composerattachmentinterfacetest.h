/*
   SPDX-FileCopyrightText: 2019-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef COMPOSERATTACHMENTINTERFACETEST_H
#define COMPOSERATTACHMENTINTERFACETEST_H

#include <QObject>

class ComposerAttachmentInterfaceTest : public QObject
{
    Q_OBJECT
public:
    explicit ComposerAttachmentInterfaceTest(QObject *parent = nullptr);
    ~ComposerAttachmentInterfaceTest() = default;
private Q_SLOTS:
    void shouldHaveDefaultValues();
};

#endif // COMPOSERATTACHMENTINTERFACETEST_H
