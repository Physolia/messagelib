/*
  SPDX-FileCopyrightText: 2021-2022 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: LGPL-2.0-or-later

*/
#include "scamdetectionwhitelistsettingsmanager.h"

#include <KConfigGroup>
#include <KSharedConfig>

namespace
{
static const char myScamDetectionWhiteListGroupName[] = "ScamDetectionWhiteList";
}
using namespace MessageViewer;
ScamDetectionWhiteListSettingsManager::ScamDetectionWhiteListSettingsManager(QObject *parent)
    : QObject{parent}
{
    loadSettings();
}

ScamDetectionWhiteListSettingsManager::~ScamDetectionWhiteListSettingsManager()
{
    writeSettings();
}

ScamDetectionWhiteListSettingsManager *ScamDetectionWhiteListSettingsManager::self()
{
    static ScamDetectionWhiteListSettingsManager s_self;
    return &s_self;
}

void ScamDetectionWhiteListSettingsManager::loadSettings()
{
    mScamDetectionInfoList.clear();
    KSharedConfig::Ptr config = KSharedConfig::openConfig();
    KConfigGroup group(config, myScamDetectionWhiteListGroupName);
    // TODO
}

void ScamDetectionWhiteListSettingsManager::writeSettings()
{
    KSharedConfig::Ptr config = KSharedConfig::openConfig();
    KConfigGroup group(config, myScamDetectionWhiteListGroupName);
    // TODO
}
