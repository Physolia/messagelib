/*
  Copyright (c) 2011-2020 Laurent Montel <montel@kde.org>

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef TEMPLATEPARSER_TEMPLATESUTIL_P_H
#define TEMPLATEPARSER_TEMPLATESUTIL_P_H

#include "templateparser_private_export.h"
#include <QString>
class QString;
class QStringList;
namespace TemplateParser {
namespace Util {
Q_REQUIRED_RESULT QStringList keywords();
Q_REQUIRED_RESULT QStringList keywordsWithArgs();
TEMPLATEPARSER_TESTS_EXPORT Q_REQUIRED_RESULT QString removeSpaceAtBegin(const QString &selection);
}
}

#endif
