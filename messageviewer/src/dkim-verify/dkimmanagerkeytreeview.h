/*
   SPDX-FileCopyrightText: 2023 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/
#pragma once
#include "messageviewer_private_export.h"
#include <QTreeView>
namespace MessageViewer
{
class MESSAGEVIEWER_TESTS_EXPORT DKIMManagerKeyTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit DKIMManagerKeyTreeView(QWidget *parent = nullptr);
    ~DKIMManagerKeyTreeView() override;
};
}