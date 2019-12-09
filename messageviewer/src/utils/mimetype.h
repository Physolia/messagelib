/*
  Copyright (C) 2005 Till Adam <adam@kde.org>
  Copyright (c) 2016 Sandro Knauß <sknauss@kde.org>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#ifndef MESSAGEVIEWER_UTIL_MIMETYPE_H
#define MESSAGEVIEWER_UTIL_MIMETYPE_H

#include "messageviewer_export.h"

#include <QString>

namespace KMime {
class Content;
}

namespace MessageViewer {
/**
 * The Util namespace contains a collection of helper functions use in
 * various places.
 */
namespace Util {

Q_REQUIRED_RESULT QString MESSAGEVIEWER_EXPORT iconPathForContent(KMime::Content *node, int iconSize);

struct AttachmentDisplayInfo {
    QString label;
    QString icon;
    bool displayInHeader = false;
};

Q_REQUIRED_RESULT AttachmentDisplayInfo attachmentDisplayInfo(KMime::Content *node);
}
}
#endif
