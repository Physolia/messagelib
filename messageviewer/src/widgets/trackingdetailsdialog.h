/*
   SPDX-FileCopyrightText: 2017-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "messageviewer_private_export.h"
#include <QDialog>

namespace KPIMTextEdit
{
class RichTextEditorWidget;
}

namespace MessageViewer
{
class MESSAGEVIEWER_TESTS_EXPORT TrackingDetailsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit TrackingDetailsDialog(QWidget *parent = nullptr);
    ~TrackingDetailsDialog() override;

    void setDetails(const QString &details);

private:
    void writeConfig();
    void readConfig();

    KPIMTextEdit::RichTextEditorWidget *mDetails = nullptr;
};
}