/*
  Copyright (C) 2010 Klaralvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Copyright (c) 2010 Leo Franchi <lfranchi@kde.org>

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

#ifndef MESSAGECORE_TESTS_UTIL_H
#define MESSAGECORE_TESTS_UTIL_H

#include <gpgme++/key.h>
#include "objecttreesourceif.h"
#include <viewer/attachmentstrategy.h>
#include "viewer/bodypartformatterbasefactory.h"

namespace MessageViewer
{

namespace Test
{

/**
* setup a environment variables for tests:
* * set LC_ALL to C
* * set KDEHOME
*/
void setupEnv();

// We can't use EmptySource, since we need to control some emelnets of the source for tests to also test
// loadExternal and htmlMail.
class TestObjectTreeSource : public MessageViewer::ObjectTreeSourceIf
{
public:
    TestObjectTreeSource(MessageViewer::HtmlWriter *writer,
                         MessageViewer::CSSHelperBase *cssHelper)
        : mWriter(writer)
        , mCSSHelper(cssHelper)
        , mAttachmentStrategy(QStringLiteral("smart"))
        , mHtmlLoadExternal(false)
        , mHtmlMail(true)
        , mDecryptMessage(false)
    {
    }

    MessageViewer::HtmlWriter *htmlWriter() Q_DECL_OVERRIDE {
        return mWriter;
    }
    MessageViewer::CSSHelperBase *cssHelper() Q_DECL_OVERRIDE {
        return mCSSHelper;
    }

    bool htmlLoadExternal() const Q_DECL_OVERRIDE
    {
        return mHtmlLoadExternal;
    }

    void setHtmlLoadExternal(bool loadExternal)
    {
        mHtmlLoadExternal = loadExternal;
    }

    bool htmlMail() const Q_DECL_OVERRIDE
    {
        return mHtmlMail;
    }

    void setHtmlMail(bool htmlMail)
    {
        mHtmlMail = htmlMail;
    }

    void setAttachmentStrategy(QString strategy)
    {
        mAttachmentStrategy = strategy;
    }

    const AttachmentStrategy *attachmentStrategy() Q_DECL_OVERRIDE {
        return  AttachmentStrategy::create(mAttachmentStrategy);
    }

    bool autoImportKeys() const Q_DECL_OVERRIDE
    {
        return true;
    }

    bool showEmoticons() const Q_DECL_OVERRIDE
    {
        return false;
    }

    bool showExpandQuotesMark() const Q_DECL_OVERRIDE
    {
        return false;
    }

    const BodyPartFormatterBaseFactory *bodyPartFormatterFactory() Q_DECL_OVERRIDE
    {
	return &mBodyPartFormatterBaseFactory;
    }

    bool decryptMessage() const Q_DECL_OVERRIDE
    {
	return mDecryptMessage;
    }

    void setAllowDecryption(bool allowDecryption)
    {
	mDecryptMessage = allowDecryption;
    }

    bool showSignatureDetails() const Q_DECL_OVERRIDE
    {
        return false;
    }

    void setHtmlMode(MessageViewer::Util::HtmlMode mode) Q_DECL_OVERRIDE
    {
        Q_UNUSED(mode);
    }

    int levelQuote() const Q_DECL_OVERRIDE
    {
        return 1;
    }

    const QTextCodec *overrideCodec() Q_DECL_OVERRIDE
    {
	return Q_NULLPTR;
    }

    QString createMessageHeader(KMime::Message *message) Q_DECL_OVERRIDE
    {
        Q_UNUSED(message);
        return QString(); //do nothing
    }

    QObject *sourceObject() Q_DECL_OVERRIDE
    {
	return Q_NULLPTR;
    }

private:
    MessageViewer::HtmlWriter *mWriter;
    MessageViewer::CSSHelperBase *mCSSHelper;
    QString mAttachmentStrategy;
    BodyPartFormatterBaseFactory mBodyPartFormatterBaseFactory;
    bool mHtmlLoadExternal;
    bool mHtmlMail;
    bool mDecryptMessage;
};

}

}

#endif
