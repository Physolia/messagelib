/*
   Copyright (C) 2016-2019 Laurent Montel <montel@kde.org>

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

#ifndef WEBHITTEST_H
#define WEBHITTEST_H

#include <QObject>
#include "webengineviewer_export.h"
#include <QPoint>
class QWebEnginePage;
namespace WebEngineViewer {
class WebHitTestResult;
class WebHitTestPrivate;
/**
 * @brief The WebHitTest class
 * @author Laurent Montel <montel@kde.org>
 */
class WEBENGINEVIEWER_EXPORT WebHitTest : public QObject
{
    Q_OBJECT
public:
    explicit WebHitTest(QWebEnginePage *page, const QPoint &zoomedPos, const QPoint &pos, QObject *parent = nullptr);
    ~WebHitTest();

Q_SIGNALS:
    void finished(const WebEngineViewer::WebHitTestResult &result);

private Q_SLOTS:
    void handleHitTest(const QVariant &result);
private:
    WebHitTestPrivate *const d;
};
}

#endif // WEBHITTEST_H
