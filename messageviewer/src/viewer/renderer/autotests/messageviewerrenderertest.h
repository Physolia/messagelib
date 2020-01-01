/*
   Copyright (C) 2019-2020 Laurent Montel <montel@kde.org>

   Code based on ARHParser.jsm from dkim_verifier (Copyright (c) Philippe Lieser)
   (This software is licensed under the terms of the MIT License.)

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

#ifndef MESSAGEVIEWERRENDERERTEST_H
#define MESSAGEVIEWERRENDERERTEST_H

#include <QObject>

class MessageViewerRendererTest : public QObject
{
    Q_OBJECT
public:
    explicit MessageViewerRendererTest(QObject *parent = nullptr);
    ~MessageViewerRendererTest() = default;
private Q_SLOTS:
    void shouldHaveDefaultValue();
};

#endif // MESSAGEVIEWERRENDERERTEST_H
