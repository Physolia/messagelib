/*
   Copyright (C) 2013-2020 Laurent Montel <montel@kde.org>

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

#ifndef GRANTLEEHEADERSTYLE_H
#define GRANTLEEHEADERSTYLE_H

#include "messageviewer/headerstyle.h"

namespace MessageViewer {
class GrantleeHeaderStylePrivate;
/**
 * @brief The GrantleeHeaderStyle class
 * @author Laurent Montel <montel@kde.org>
 */
class MESSAGEVIEWER_EXPORT GrantleeHeaderStyle : public HeaderStyle
{
public:
    GrantleeHeaderStyle();
    ~GrantleeHeaderStyle() override;

public:
    const char *name() const override;

    Q_REQUIRED_RESULT QString format(KMime::Message *message) const override;
private:
    GrantleeHeaderStylePrivate *const d;
};
}
#endif // GRANTLEEHEADERSTYLE_H
