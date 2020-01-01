/*
   Copyright (C) 2019-2020 Laurent Montel <montel@kde.org>

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

#ifndef DKIMMANAGERRULES_H
#define DKIMMANAGERRULES_H

#include <QObject>
#include "messageviewer_export.h"
#include <MessageViewer/DKIMRule>
#include <QVector>
#include <KSharedConfig>
namespace MessageViewer {
/**
 * @brief The DKIMManagerRules class
 * @author Laurent Montel <montel@kde.org>
 */
class MESSAGEVIEWER_EXPORT DKIMManagerRules : public QObject
{
    Q_OBJECT
public:
    explicit DKIMManagerRules(QObject *parent = nullptr);
    ~DKIMManagerRules();
    static DKIMManagerRules *self();

    void addRule(const DKIMRule &rule);

    Q_REQUIRED_RESULT QVector<DKIMRule> rules() const;

    void saveRules(const QVector<DKIMRule> &lst);

    void clear();

    void importRules(const QString &fileName);
    void exportRules(const QString &fileName);

private:
    void loadRules(const QString &fileName = QString());
    void save(const QString &fileName = QString());
    Q_REQUIRED_RESULT QStringList ruleGroups(const KSharedConfig::Ptr &config) const;
    QVector<DKIMRule> mRules;
};
}

#endif // DKIMMANAGERRULES_H
