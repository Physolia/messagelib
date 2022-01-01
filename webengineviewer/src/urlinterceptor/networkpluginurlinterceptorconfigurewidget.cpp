/*
   SPDX-FileCopyrightText: 2016-2022 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "networkpluginurlinterceptorconfigurewidget.h"

using namespace WebEngineViewer;

NetworkPluginUrlInterceptorConfigureWidget::NetworkPluginUrlInterceptorConfigureWidget(QWidget *parent)
    : QWidget(parent)
{
}

NetworkPluginUrlInterceptorConfigureWidget::~NetworkPluginUrlInterceptorConfigureWidget() = default;

QString NetworkPluginUrlInterceptorConfigureWidget::helpAnchor() const
{
    return {};
}
