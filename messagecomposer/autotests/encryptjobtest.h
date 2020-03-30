/*
  Copyright (C) 2009 Klaralvdalens Datakonsult AB, a KDAB Group company, info@kdab.net
  Copyright (c) 2009 Leo Franchi <lfranchi@kde.org>

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Library General Public License as published by
  the Free Software Foundation; either version 2 of the License, or (at your
  option) any later version.

  This library is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
  License for more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; see the file COPYING.LIB.  If not, write to the
  Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
  02110-1301, USA.
*/

#ifndef ENCRYPTJOBTEST_H
#define ENCRYPTJOBTEST_H

#include <QObject>

#include <gpgme++/key.h>
#include <gpgme++/keylistresult.h>

namespace MessageComposer {
class EncryptJob;
}

class EncryptJobTest : public QObject
{
    Q_OBJECT

public Q_SLOTS:
    void initTestCase();

private Q_SLOTS:
    void testContentDirect();
    void testContentChained();
    void testContentSubjobChained();
    void testHeaders();

    void testProtectedHeaders_data();
    void testProtectedHeaders();

private:
    void checkEncryption(MessageComposer::EncryptJob *eJob);
};

#endif
