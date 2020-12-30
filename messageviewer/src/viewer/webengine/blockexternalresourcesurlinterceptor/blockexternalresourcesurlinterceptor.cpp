/*
   SPDX-FileCopyrightText: 2016-2020 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "blockexternalresourcesurlinterceptor.h"
#include "remote-content/remotecontentmanager.h"
#include <QDebug>
using namespace MessageViewer;

BlockExternalResourcesUrlInterceptor::BlockExternalResourcesUrlInterceptor(QObject *parent)
    : WebEngineViewer::NetworkPluginUrlInterceptorInterface(parent)
{
}

BlockExternalResourcesUrlInterceptor::~BlockExternalResourcesUrlInterceptor()
{
}

bool BlockExternalResourcesUrlInterceptor::interceptRequest(const QUrl &url, QWebEngineUrlRequestInfo::ResourceType resourceType, QWebEngineUrlRequestInfo::NavigationType navigationType)
{
    const QString scheme = url.scheme();
    if (scheme == QLatin1String("data")
        || scheme == QLatin1String("file")) {
        return false;
    }

    if (resourceType == QWebEngineUrlRequestInfo::ResourceTypeMedia
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypePing
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypePrefetch
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeFavicon
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeXhr
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeObject
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeScript
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeServiceWorker
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeSharedWorker
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeWorker
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeSubResource
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypePluginResource
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeCspReport
        || resourceType == QWebEngineUrlRequestInfo::ResourceTypeUnknown) {
        return true;
    } else if (navigationType == QWebEngineUrlRequestInfo::NavigationTypeFormSubmitted) {
        Q_EMIT formSubmittedForbidden();
        return true;
    } else if (navigationType == QWebEngineUrlRequestInfo::NavigationTypeReload
               || navigationType == QWebEngineUrlRequestInfo::NavigationTypeTyped
               || navigationType == QWebEngineUrlRequestInfo::NavigationTypeBackForward
               || navigationType == QWebEngineUrlRequestInfo::NavigationTypeOther
               || navigationType == QWebEngineUrlRequestInfo::NavigationTypeRedirect
               ) {
        return true;
    }
    bool contains = false;
    if (MessageViewer::RemoteContentManager::self()->isAutorized(url, contains)) {
        return false;
    }
    if (!contains) { //Don't block it if it's not in list of url in remote content manager
        return false;
    } else {
        return true;
    }
    return false;
}

bool BlockExternalResourcesUrlInterceptor::interceptRequest(QWebEngineUrlRequestInfo &info)
{
    const QWebEngineUrlRequestInfo::ResourceType resourceType = info.resourceType();
    const QWebEngineUrlRequestInfo::NavigationType navigationType = info.navigationType();

    return interceptRequest(info.requestUrl(), resourceType, navigationType);
}
