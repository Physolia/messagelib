/*
  SPDX-FileCopyrightText: 2015-2021 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-only
*/

#ifndef ZOOMACTIONMENUTEST_H
#define ZOOMACTIONMENUTEST_H

#include <QObject>

class ZoomActionMenuTest : public QObject
{
    Q_OBJECT
public:
    explicit ZoomActionMenuTest(QObject *parent = nullptr);
    ~ZoomActionMenuTest();
private Q_SLOTS:
    void shouldHaveDefaultValue();
    void shouldAssignZoomFactor();
};

#endif // ZOOMACTIONMENUTEST_H
