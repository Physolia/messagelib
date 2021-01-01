/*
   SPDX-FileCopyrightText: 2015-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/

#ifndef SENDLATERDIALOGTEST_H
#define SENDLATERDIALOGTEST_H

#include <QObject>

class SendLaterDialogTest : public QObject
{
    Q_OBJECT
public:
    explicit SendLaterDialogTest(QObject *parent = nullptr);
    ~SendLaterDialogTest();
private Q_SLOTS:
    void shouldHaveDefaultValue();
    void initTestCase();
};

#endif // SENDLATERDIALOGTEST_H
