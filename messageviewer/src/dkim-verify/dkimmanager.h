/*
   Copyright (C) 2019 Laurent Montel <montel@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef DKIMMANAGER_H
#define DKIMMANAGER_H

#include <QObject>
#include "messageviewer_export.h"
#include "dkimchecksignaturejob.h"
#include <KMime/Message>
#include <AkonadiCore/Item>
namespace MessageViewer {
class MESSAGEVIEWER_EXPORT DKIMManager : public QObject
{
    Q_OBJECT
public:
    explicit DKIMManager(QObject *parent = nullptr);
    ~DKIMManager();
    static DKIMManager *self();

    void checkDKim(const KMime::Message::Ptr &message);
    void checkDKim(const Akonadi::Item &item);

Q_SIGNALS:
    void result(const MessageViewer::DKIMCheckSignatureJob::CheckSignatureResult &checkResult);

private:
    void storeKey(const QString &key, const QString &domain, const QString &selector);
    void slotResult(const MessageViewer::DKIMCheckSignatureJob::CheckSignatureResult &checkResult);
};
}

#endif // DKIMMANAGER_H