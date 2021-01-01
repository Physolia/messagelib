/*
   SPDX-FileCopyrightText: 2014-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: GPL-2.0-or-later
*/

#ifndef FOLLOWUPREMINDERSELECTDATEDIALOGTEST_H
#define FOLLOWUPREMINDERSELECTDATEDIALOGTEST_H

#include <QObject>

class QStandardItemModel;
class FollowupReminderSelectDateDialogTest : public QObject
{
    Q_OBJECT
public:
    explicit FollowupReminderSelectDateDialogTest(QObject *parent = nullptr);
    ~FollowupReminderSelectDateDialogTest();
private Q_SLOTS:
    void shouldHaveDefaultValue();
    void shouldDisableOkButtonIfDateIsEmpty();
    void shouldDisableOkButtonIfDateIsNotValid();
    void shouldDisableOkButtonIfModelIsEmpty();
private:
    QStandardItemModel *defaultItemModel();
};

#endif // FOLLOWUPREMINDERSELECTDATEDIALOGTEST_H
