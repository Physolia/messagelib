/*
   Copyright (C) 2018-2019 Laurent Montel <montel@kde.org>

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

#include "dkimchecksignaturejob.h"
#include "messageviewer_debug.h"
using namespace MessageViewer;
DKIMCheckSignatureJob::DKIMCheckSignatureJob(QObject *parent)
    : QObject(parent)
{
}

DKIMCheckSignatureJob::~DKIMCheckSignatureJob()
{
}

void DKIMCheckSignatureJob::start()
{
    if (!canStart()) {
        qCWarning(MESSAGEVIEWER_LOG) << "Impossible to start job";
        deleteLater();
        return;
    }
    //TODO
    deleteLater();
}

bool DKIMCheckSignatureJob::canStart() const
{
    //TODO
    return false;
}

QString DKIMCheckSignatureJob::dkimValue() const
{
    return mDkimValue;
}

void DKIMCheckSignatureJob::setDkimValue(const QString &dkimValue)
{
    mDkimValue = dkimValue;
}
