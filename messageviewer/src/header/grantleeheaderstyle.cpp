/*
   SPDX-FileCopyrightText: 2013-2022 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "grantleeheaderstyle.h"
#include "header/grantleeheaderformatter.h"
#include "header/headerstrategy.h"
#include <GrantleeTheme/GrantleeTheme>

#include <KMime/KMimeMessage>

using namespace MessageViewer;
class MessageViewer::GrantleeHeaderStylePrivate
{
public:
    GrantleeHeaderStylePrivate()
    {
        mGrantleeFormatter = new GrantleeHeaderFormatter;
    }

    ~GrantleeHeaderStylePrivate()
    {
        delete mGrantleeFormatter;
    }

    GrantleeHeaderFormatter *mGrantleeFormatter = nullptr;
};

GrantleeHeaderStyle::GrantleeHeaderStyle()
    : HeaderStyle()
    , d(new MessageViewer::GrantleeHeaderStylePrivate)
{
}

GrantleeHeaderStyle::~GrantleeHeaderStyle() = default;

const char *GrantleeHeaderStyle::name() const
{
    return "grantlee";
}

QString GrantleeHeaderStyle::format(KMime::Message *message) const
{
    if (!message) {
        return {};
    }

    GrantleeHeaderFormatter::GrantleeHeaderFormatterSettings settings;
    settings.isPrinting = isPrinting();
    settings.theme = theme();
    settings.style = this;
    settings.message = message;
    settings.showEmoticons = showEmoticons();
    return d->mGrantleeFormatter->toHtml(settings);
}
