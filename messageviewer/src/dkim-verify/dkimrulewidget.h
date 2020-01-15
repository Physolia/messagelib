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

#ifndef DKIMRULEWIDGET_H
#define DKIMRULEWIDGET_H
#include <QWidget>
#include "messageviewer_private_export.h"
#include <MessageViewer/DKIMRule>
class QCheckBox;
class QLineEdit;
namespace MessageViewer {
class DKIMManageRulesComboBox;
class MESSAGEVIEWER_TESTS_EXPORT DKIMRuleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DKIMRuleWidget(QWidget *parent = nullptr);
    ~DKIMRuleWidget();
    void loadRule(const MessageViewer::DKIMRule &rule);
    Q_REQUIRED_RESULT MessageViewer::DKIMRule rule() const;

Q_SIGNALS:
    void updateOkButtonRequested(bool enabled);

private:
    void updateOkButton();
    QCheckBox *mEnabled = nullptr;
    QLineEdit *mDomain = nullptr;
    QLineEdit *mSignatureDomainIdentifier = nullptr;
    QLineEdit *mFrom = nullptr;
    QLineEdit *mListId = nullptr;
    QLineEdit *mPriority = nullptr;
    DKIMManageRulesComboBox *mRuleType = nullptr;
};
}
#endif // DKIMRULEWIDGET_H