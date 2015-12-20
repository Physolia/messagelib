/* Copyright (C) 2011-2015 Laurent Montel <montel@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "findbarmailwebview.h"
#include "PimCommon/LineEditWithCompleter"
#include "viewer/mailwebview.h"

#include <KLocalizedString>
#include <QMenu>
using namespace MessageViewer;

FindBarMailWebView::FindBarMailWebView(MailWebView *view, QWidget *parent)
    : FindBarBase(parent), mView(view)
{
    QMenu *options = optionsMenu();
    mHighlightAll = options->addAction(i18n("Highlight all matches"));
    mHighlightAll->setCheckable(true);
    mFindInSelection = options->addAction(i18n("Find in selection first"));
    mFindInSelection->setCheckable(true);
    connect(mHighlightAll, &QAction::toggled, this, &FindBarMailWebView::slotHighlightAllChanged);
    connect(mFindInSelection, &QAction::toggled, this, &FindBarMailWebView::slotFindSelectionFirstChanged);
}

FindBarMailWebView::~FindBarMailWebView()
{
}

void FindBarMailWebView::searchText(bool backward, bool isAutoSearch)
{
    QWebPage::FindFlags searchOptions = QWebPage::FindWrapsAroundDocument;

    if (backward) {
        searchOptions |= QWebPage::FindBackward;
    }
    if (mCaseSensitiveAct->isChecked()) {
        searchOptions |= QWebPage::FindCaseSensitively;
    }
    if (mHighlightAll->isChecked()) {
        searchOptions |= QWebPage::HighlightAllOccurrences;
    }
    if (mFindInSelection->isChecked()) {
        searchOptions |= QWebPage::FindBeginsInSelection;
    }
    const QString searchWord(mSearch->text());
    if (!isAutoSearch && !mLastSearchStr.contains(searchWord, Qt::CaseSensitive)) {
        clearSelections();
    }
    mView->findText(QString(), QWebPage::HighlightAllOccurrences); //Clear an existing highligh

    mLastSearchStr = searchWord;
    const bool found = mView->findText(mLastSearchStr, searchOptions);

    setFoundMatch(found);
}

void FindBarMailWebView::updateHighLight(bool highLight)
{
    bool found = false;
    if (highLight) {
        QWebPage::FindFlags searchOptions = QWebPage::FindWrapsAroundDocument;
        if (mCaseSensitiveAct->isChecked()) {
            searchOptions |= QWebPage::FindCaseSensitively;
        }
        searchOptions |= QWebPage::HighlightAllOccurrences;
        found = mView->findText(mLastSearchStr, searchOptions);
    } else {
        found = mView->findText(QString(), QWebPage::HighlightAllOccurrences);
    }
    setFoundMatch(found);
}

void FindBarMailWebView::updateSensitivity(bool sensitivity)
{
    QWebPage::FindFlags searchOptions = QWebPage::FindWrapsAroundDocument;
    if (sensitivity) {
        searchOptions |= QWebPage::FindCaseSensitively;
        mView->findText(QString(), QWebPage::HighlightAllOccurrences); //Clear an existing highligh
    }
    if (mHighlightAll->isChecked()) {
        searchOptions |= QWebPage::HighlightAllOccurrences;
    }
    const bool found = mView->findText(mLastSearchStr, searchOptions);
    setFoundMatch(found);
}

void FindBarMailWebView::slotFindSelectionFirstChanged(bool findSectionFirst)
{
    QWebPage::FindFlags searchOptions = QWebPage::FindWrapsAroundDocument;
    if (findSectionFirst) {
        searchOptions |= QWebPage::FindBeginsInSelection;
        mView->findText(QString(), QWebPage::HighlightAllOccurrences); //Clear an existing highligh
    }
    if (mHighlightAll->isChecked()) {
        searchOptions |= QWebPage::HighlightAllOccurrences;
    }
    const bool found = mView->findText(mLastSearchStr, searchOptions);
    setFoundMatch(found);
}

void FindBarMailWebView::clearSelections()
{
    mView->clearFindSelection();
    mLastSearchStr.clear();
    FindBarBase::clearSelections();
}

