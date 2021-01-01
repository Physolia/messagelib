/*
   SPDX-FileCopyrightText: 2016-2021 Laurent Montel <montel@kde.org>

   SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef CREATEPHISHINGURLDATABASEGUI_H
#define CREATEPHISHINGURLDATABASEGUI_H

#include <QWidget>
#include "../createphishingurldatabasejob.h"
class QPlainTextEdit;
class QComboBox;
class CreatePhisingUrlDataBaseGui : public QWidget
{
    Q_OBJECT
public:
    explicit CreatePhisingUrlDataBaseGui(QWidget *parent = nullptr);
    ~CreatePhisingUrlDataBaseGui();
private Q_SLOTS:
    void slotResult(const QByteArray &data);
    void slotDownloadFullDatabase();
    void slotDebugJSon(const QByteArray &data);
    void slotDownloadPartialDatabase();
    void slotSaveResultToDisk();
private:
    WebEngineViewer::CreatePhishingUrlDataBaseJob::ContraintsCompressionType compressionType();
    void clear();
    QPlainTextEdit *mResult;
    QPlainTextEdit *mJson;
    QComboBox *mCompressionType;
};

#endif // CREATEPHISHINGURLDATABASEGUI_H
