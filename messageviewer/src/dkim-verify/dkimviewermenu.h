/*
   SPDX-FileCopyrightText: 2019-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef DKIMVIEWERMENU_H
#define DKIMVIEWERMENU_H

#include "messageviewer_export.h"
#include <QObject>
class QMenu;
class QAction;
namespace MessageViewer
{
class MESSAGEVIEWER_EXPORT DKIMViewerMenu : public QObject
{
    Q_OBJECT
public:
    explicit DKIMViewerMenu(QObject *parent = nullptr);
    ~DKIMViewerMenu() override;
    QMenu *menu() const;

    void setEnableUpdateDkimKeyMenu(bool enabled);
Q_SIGNALS:
    void recheckSignature();
    void updateDkimKey();
    void showDkimRules();

private:
    void initialize();
    QMenu *const mMenu;
    QAction *mUpdateDKIMKey = nullptr;
};
}

#endif // DKIMVIEWERMENU_H
