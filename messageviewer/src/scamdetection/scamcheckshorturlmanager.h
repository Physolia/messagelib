/*
  SPDX-FileCopyrightText: 2016-2022 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: LGPL-2.0-or-later

*/

#pragma once

#include "messageviewer_export.h"
#include <QObject>
#include <memory>
namespace MessageViewer
{
class ScamCheckShortUrl;
class ScamCheckShortUrlManagerPrivate;
/**
 * @brief The ScamCheckShortUrlManager class
 * @author Laurent Montel <montel@kde.org>
 */
class MESSAGEVIEWER_EXPORT ScamCheckShortUrlManager : public QObject
{
    Q_OBJECT
public:
    explicit ScamCheckShortUrlManager(QObject *parent = nullptr);
    ~ScamCheckShortUrlManager() override;
    static ScamCheckShortUrlManager *self();
    Q_REQUIRED_RESULT ScamCheckShortUrl *scamCheckShortUrl() const;

private:
    std::unique_ptr<ScamCheckShortUrlManagerPrivate> const d;
};
}
