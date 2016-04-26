/*
  Copyright (c) 2016 Montel Laurent <montel@kde.org>

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License, version 2, as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef SCAMDETECTIONWEBENGINE_H
#define SCAMDETECTIONWEBENGINE_H

#include <QObject>
#include <QVariant>
#include "messageviewer_export.h"
class QWebEnginePage;
namespace MessageViewer
{
class ScamCheckShortUrl;
class ScamDetectionWebEnginePrivate;
class MESSAGEVIEWER_EXPORT ScamDetectionWebEngine : public QObject
{
    Q_OBJECT
public:
    explicit ScamDetectionWebEngine(QObject *parent = Q_NULLPTR);
    ~ScamDetectionWebEngine();

    void scanPage(QWebEnginePage *page);

public Q_SLOTS:
    void showDetails();

private Q_SLOTS:
    void handleScanPage(const QVariant &result);

Q_SIGNALS:
    void messageMayBeAScam();
    void resultScanDetection(bool foundScam);

private:
    ScamDetectionWebEnginePrivate *const d;
};
}
#endif // SCAMDETECTIONWEBENGINE_H
