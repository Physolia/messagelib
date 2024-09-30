/*
  SPDX-FileCopyrightText: 2024 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "searchlinecommandwidget.h"
#include "searchlinecommandflowlayout.h"
#include <KLocalizedString>
#include <QPushButton>
#include <QVBoxLayout>
using namespace MessageList::Core;
SearchLineCommandWidget::SearchLineCommandWidget(QWidget *parent)
    : QWidget{parent}
{
    auto flowLayout = new SearchLineCommandFlowLayout(this);
    flowLayout->setObjectName(QStringLiteral("flowLayout"));
    flowLayout->setContentsMargins({});
    flowLayout->setSpacing(0);
    fillWidgets();
    Q_ASSERT(!mButtonsList.isEmpty());
    for (const auto &info : std::as_const(mButtonsList)) {
        flowLayout->addWidget(createPushButton(info.needSpace, info.i18n, info.identifier));
    }
}

SearchLineCommandWidget::~SearchLineCommandWidget() = default;

QPushButton *SearchLineCommandWidget::createPushButton(bool needSpace, const QString &i18nStr, const QString &commandStr)
{
    auto pushButton = new QPushButton(i18nStr, this);
    pushButton->setObjectName(commandStr);
    connect(pushButton, &QPushButton::clicked, this, [this, commandStr, needSpace]() {
        const QString str = commandStr + (needSpace ? QStringLiteral(" ") : QString());
        Q_EMIT insertCommand(str);
    });
    return pushButton;
}

void SearchLineCommandWidget::fillWidgets()
{
    mButtonsList = {
        {false, QStringLiteral("from:"), i18n("From")},
        {false, QStringLiteral("to:"), i18n("To")},
        {false, QStringLiteral("cc:"), i18n("Cc")},
        {false, QStringLiteral("bcc:"), i18n("Bcc")},
        {true, QStringLiteral("has:attachment"), i18n("Has Attachment")},
        {true, QStringLiteral("is:read"), i18n("Read")},
        {true, QStringLiteral("is:unread"), i18n("Unread")},
        {true, QStringLiteral("is:important"), i18n("Important")},
        // TODO add more
    };
}

#include "moc_searchlinecommandwidget.cpp"
