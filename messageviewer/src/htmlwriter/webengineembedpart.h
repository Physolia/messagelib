/*
  SPDX-FileCopyrightText: 2016-2020 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#ifndef WEBENGINEEMBEDPART_H
#define WEBENGINEEMBEDPART_H

#include <QObject>
#include <QMap>
namespace MessageViewer {
class WebEngineEmbedPart : public QObject
{
    Q_OBJECT
public:
    explicit WebEngineEmbedPart(QObject *parent = nullptr);
    ~WebEngineEmbedPart() override;

    void clear();
    Q_REQUIRED_RESULT bool isEmpty() const;

    Q_REQUIRED_RESULT QMap<QString, QString> embeddedPartMap() const;

    void addEmbedPart(const QByteArray &contentId, const QString &contentURL);
    Q_REQUIRED_RESULT QString contentUrl(const QString &contentId) const;

    static WebEngineEmbedPart *self();
private:
    // Key is Content-Id, value is URL
    QMap<QString, QString> mEmbeddedPartMap;
};
}
#endif // WEBENGINEEMBEDPART_H
