/*
   SPDX-FileCopyrightText: 2015-2022 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#pragma once
#include "messagecomposer_export.h"
#include <PimCommon/AbstractGenericPlugin>
#include <QObject>
#include <memory>
namespace MessageComposer
{
class PluginEditorPrivate;
/**
 * @brief The PluginEditor class
 * @author Laurent Montel <montel@kde.org>
 */
class MESSAGECOMPOSER_EXPORT PluginEditor : public PimCommon::AbstractGenericPlugin
{
    Q_OBJECT
public:
    explicit PluginEditor(QObject *parent = nullptr);
    ~PluginEditor() override;
    void setOrder(int order);
    Q_REQUIRED_RESULT int order() const;

    Q_REQUIRED_RESULT virtual bool canProcessKeyEvent() const;

private:
    std::unique_ptr<PluginEditorPrivate> const d;
};
}
