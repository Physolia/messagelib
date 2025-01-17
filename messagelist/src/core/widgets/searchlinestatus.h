/*
  SPDX-FileCopyrightText: 2016-2023 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include "messagelist_private_export.h"
#include "quicksearchline.h"
#include <Akonadi/MessageStatus>
#include <QIcon>
#include <QLineEdit>
class QStringListModel;
class QAction;
namespace MessageList
{
namespace Core
{
class FilterSavedMenu;
class Filter;
class MESSAGELIST_TESTS_EXPORT SearchLineStatus : public QLineEdit
{
    Q_OBJECT
public:
    explicit SearchLineStatus(QWidget *parent = nullptr);
    ~SearchLineStatus() override;

    void setLocked(bool b);
    [[nodiscard]] bool locked() const;

    void setContainsOutboundMessages(bool containsOutboundMessages);
    [[nodiscard]] bool containsOutboundMessages() const;
    [[nodiscard]] QuickSearchLine::SearchOptions searchOptions() const;
    void setSearchOptions(QuickSearchLine::SearchOptions opts);
    void setFilterMessageStatus(const QList<Akonadi::MessageStatus> &newLstStatus);
    void addCompletionItem(const QString &str);
    void slotClearHistory();
    void clearFilterButtonClicked();
Q_SIGNALS:
    void filterActionChanged(const QList<Akonadi::MessageStatus> &lst);
    void searchOptionChanged();
    void clearButtonClicked();
    void forceLostFocus();
    void saveFilter();
    void activateFilter(MessageList::Core::Filter *f);

protected:
    void contextMenuEvent(QContextMenuEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;

private:
    void slotToggledLockAction();
    void showMenu();
    void slotFilterActionClicked(QAction *act);
    void clearFilterAction();
    void createFilterAction(const QIcon &icon, const QString &text, int value);
    void createMenuSearch();
    void updateLockAction();
    void initializeActions();
    void updateFilterActionIcon();
    void updateFilters();
    void createFilterByAction();
    void clearFilterByAction();
    void changeSearchAgainstFromOrToText();
    void slotClear();
    void showSavedFiltersMenu();
    void slotConfigureFilters();
    void slotActivateFilter(const QString &identifier);

    bool mLocked = false;
    bool mHasFilter = false;
    QIcon mWithoutFilter;
    QIcon mWithFilter;
    QAction *mLockAction = nullptr;
    QAction *mFiltersAction = nullptr;
    QAction *mSaveFilterAction = nullptr;
    QMenu *mFilterMenu = nullptr;
    QCompleter *const mCompleter;
    QList<QAction *> mFilterListActions;
    QAction *mSearchEveryWhereAction = nullptr;
    QAction *mSearchAgainstBodyAction = nullptr;
    QAction *mSearchAgainstSubjectAction = nullptr;
    QAction *mSearchAgainstFromOrToAction = nullptr;
    QAction *mSearchAgainstBccAction = nullptr;
    QStringListModel *const mCompleterListModel;
    FilterSavedMenu *mFilterSavedMenu = nullptr;
    QStringList mListCompetion;
    QString mColorName;
    bool mContainsOutboundMessages = false;
};
}
}
