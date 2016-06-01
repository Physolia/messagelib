/*
   Copyright (C) 2016 Laurent Montel <montel@kde.org>

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

#ifndef PRINTPREVIEWPAGEVIEWER_H
#define PRINTPREVIEWPAGEVIEWER_H

#include <QScrollArea>

class QLabel;
namespace Poppler
{
class Page;
}
namespace WebEngineViewer
{
class PrintPreviewPageViewer : public QScrollArea
{
    Q_OBJECT
public:
    explicit PrintPreviewPageViewer(QWidget *parent = Q_NULLPTR);
    ~PrintPreviewPageViewer();

    void showPage(Poppler::Page *page);

    void setZoom(qreal zoom);
    qreal zoom() const;

Q_SIGNALS:
    void reloadPage();

protected:
    void wheelEvent(QWheelEvent *e) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void slotPageUp();
    void slotPageDown();

private:
    void initializeActions();
    int mDpiX;
    int mDpiY;
    qreal mZoom;
    QLabel *mImage;
};
}

#endif // PRINTPREVIEWPAGEVIEWER_H
