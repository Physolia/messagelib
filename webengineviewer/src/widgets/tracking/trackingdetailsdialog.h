/*
   SPDX-FileCopyrightText: 2017-2023 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once

#include "webengineviewer_export.h"
#include <QDialog>

namespace KPIMTextEdit
{
class RichTextEditorWidget;
}

namespace WebEngineViewer
{
class WEBENGINEVIEWER_EXPORT TrackingDetailsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit TrackingDetailsDialog(QWidget *parent = nullptr);
    ~TrackingDetailsDialog() override;

    void setDetails(const QString &details);

private:
    WEBENGINEVIEWER_NO_EXPORT void writeConfig();
    WEBENGINEVIEWER_NO_EXPORT void readConfig();

    KPIMTextEdit::RichTextEditorWidget *const mDetails;
};
}
