/*
  SPDX-FileCopyrightText: 2020-2023 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include <PimCommon/PurposeMenuWidget>
namespace MessageViewer
{
class MailWebEngineView;
class ViewerPurposeMenuWidget : public PimCommon::PurposeMenuWidget
{
    Q_OBJECT
public:
    explicit ViewerPurposeMenuWidget(QWidget *parentWidget, QObject *parent = nullptr);
    ~ViewerPurposeMenuWidget() override;

    Q_REQUIRED_RESULT QByteArray text() override;
    void setViewer(MailWebEngineView *viewer);

private:
    MailWebEngineView *mViewer = nullptr;
};
}
