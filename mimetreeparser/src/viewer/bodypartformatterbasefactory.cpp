/*
    bodypartformatterfactory.cpp

    This file is part of KMail, the KDE mail client.
    Copyright (c) 2004 Marc Mutz <mutz@kde.org>,
                       Ingo Kloecker <kloecker@kde.org>

    KMail is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    KMail is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

    In addition, as a special exception, the copyright holders give
    permission to link the code of this program with any edition of
    the Qt library by Trolltech AS, Norway (or with modified versions
    of Qt that use the same license as Qt), and distribute linked
    combinations including the two.  You must obey the GNU General
    Public License in all respects for all of the code used other than
    Qt.  If you modify this file, you may extend this exception to
    your version of the file, but you are not obligated to do so.  If
    you do not wish to do so, delete this exception statement from
    your version.
*/

#include "bodypartformatterbasefactory.h"
#include "bodypartformatterbasefactory_p.h"
#include "mimetreeparser_debug.h"

#include <assert.h>

using namespace MimeTreeParser;

BodyPartFormatterBaseFactoryPrivate::BodyPartFormatterBaseFactoryPrivate(BodyPartFormatterBaseFactory *factory)
    : q(factory)
{
}

void BodyPartFormatterBaseFactoryPrivate::setup()
{
    if (all.empty()) {
        messageviewer_create_builtin_bodypart_formatters();
        q->loadPlugins();
    }
    assert(!all.empty());
}

void BodyPartFormatterBaseFactoryPrivate::insert(const QByteArray &type, const QByteArray &subtype, const Interface::BodyPartFormatter *formatter)
{
    if (type.isEmpty() || subtype.isEmpty() || !formatter) {
        return;
    }

    TypeRegistry::iterator type_it = all.find(type);
    if (type_it == all.end()) {
        qCDebug(MIMETREEPARSER_LOG) << "BodyPartFormatterBaseFactory: instantiating new Subtype Registry for \""
                                    << type << "\"";
        type_it = all.insert(std::make_pair(type, SubtypeRegistry())).first;
        assert(type_it != all.end());
    }

    SubtypeRegistry &subtype_reg = type_it->second;

    subtype_reg.insert(std::make_pair(subtype, formatter));
}

BodyPartFormatterBaseFactory::BodyPartFormatterBaseFactory()
    : d(new BodyPartFormatterBaseFactoryPrivate(this))
{
}

BodyPartFormatterBaseFactory::~BodyPartFormatterBaseFactory()
{
    delete d;
}

void BodyPartFormatterBaseFactory::insert(const QByteArray &type, const QByteArray &subtype, const Interface::BodyPartFormatter *formatter)
{
    d->insert(type, subtype, formatter);
}

QVector<const Interface::BodyPartFormatter*> BodyPartFormatterBaseFactory::formattersForType(const QByteArray &type, const QByteArray &subtype) const
{
    QVector<const Interface::BodyPartFormatter*> r;
    d->setup();

    auto type_it = d->all.find(type);
    if (type_it == d->all.end()) {
        type_it = d->all.find("*");
    }
    assert(type_it != d->all.end()); // cannot happen, */* always exists

    const auto &subtype_reg = type_it->second;
    assert(!subtype_reg.empty()); // same

    // exact match
    auto range = subtype_reg.equal_range(subtype);
    for (auto it = range.first; it != range.second; ++it)
        r.push_back((*it).second);

    // wildcard match
    range = subtype_reg.equal_range("*");
    for (auto it = range.first; it != range.second; ++it)
        r.push_back((*it).second);

    assert(!r.empty());
    return r;
}

void BodyPartFormatterBaseFactory::loadPlugins()
{
    qCDebug(MIMETREEPARSER_LOG) << "plugin loading is not enabled in libmimetreeparser";
}
