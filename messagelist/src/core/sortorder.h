/******************************************************************************
 *
 *  SPDX-FileCopyrightText: 2009 Thomas McGuire <mcguire@kde.org>
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *
 *******************************************************************************/
#pragma once

#include "core/aggregation.h"

#include <KConfigGroup>

namespace MessageList
{
namespace Core
{
/**
 * A class which holds information about sorting, e.g. the sorting and sort direction
 * of messages and groups.
 */
class SortOrder
{
    Q_GADGET
    Q_ENUMS(GroupSorting)
    Q_ENUMS(SortDirection)
    Q_ENUMS(MessageSorting)

public:
    /**
     * How to sort the groups
     * If you add values here please look at the implementations of the enumerate* functions
     * and add appropriate descriptors.
     */
    enum GroupSorting : uint8_t {
        NoGroupSorting, ///< Don't sort the groups at all, add them as they come in
        SortGroupsByDateTime, ///< Sort groups by date/time of the group
        SortGroupsByDateTimeOfMostRecent, ///< Sort groups by date/time of the most recent message
        SortGroupsBySenderOrReceiver, ///< Sort groups by sender or receiver (makes sense only with GroupBySenderOrReceiver)
        SortGroupsBySender, ///< Sort groups by sender (makes sense only with GroupBySender)
        SortGroupsByReceiver ///< Sort groups by receiver (makes sense only with GroupByReceiver)
        // Never add enum entries in the middle: always add them at the end (numeric values are stored in configuration)
    };

    /**
     * The "generic" sort direction: used for groups and for messages
     * If you add values here please look at the implementations of the enumerate* functions
     * and add appropriate descriptors.
     */
    enum SortDirection : uint8_t {
        Ascending,
        Descending,
    };

    /**
     * The available message sorting options.
     * If you add values here please look at the implementations of the enumerate* functions
     * and add appropriate descriptors.
     */
    enum MessageSorting {
        NoMessageSorting, ///< Don't sort the messages at all
        SortMessagesByDateTime, ///< Sort the messages by date and time
        SortMessagesByDateTimeOfMostRecent, ///< Sort the messages by date and time of the most recent message in subtree
        SortMessagesBySenderOrReceiver, ///< Sort the messages by sender or receiver
        SortMessagesBySender, ///< Sort the messages by sender
        SortMessagesByReceiver, ///< Sort the messages by receiver
        SortMessagesBySubject, ///< Sort the messages by subject
        SortMessagesBySize, ///< Sort the messages by size
        SortMessagesByActionItemStatus, ///< Sort the messages by the "Action Item" flag of status
        SortMessagesByUnreadStatus, ///< Sort the messages by the "Unread" flags of status
        SortMessagesByImportantStatus, /// Sort the messages By "Important" flags of status
        SortMessagesByAttachmentStatus, /// Sort the messages By "Attachment" flags of status
        // Warning: Never add enum entries in the middle: always add them at the end (numeric values are stored in configuration)
    };

    SortOrder();

    /**
     * Returns the GroupSorting
     */
    [[nodiscard]] GroupSorting groupSorting() const;

    /**
     * Sets the GroupSorting option.
     * This may not have any effect, depending on the Aggregation this sort order
     * is used in.
     */
    void setGroupSorting(GroupSorting gs);

    /**
     * Returns the current group SortDirection.
     */
    [[nodiscard]] SortDirection groupSortDirection() const;

    /**
     * Sets the SortDirection for the groups.
     * Note that this option has no meaning if group sorting is set to NoGroupSorting.
     */
    void setGroupSortDirection(SortDirection groupSortDirection);

    /**
     * Returns the current message sorting option
     */
    [[nodiscard]] MessageSorting messageSorting() const;

    /**
     * Sets the current message sorting option
     */
    void setMessageSorting(MessageSorting ms);

    /**
     * Returns the current message SortDirection.
     */
    [[nodiscard]] SortDirection messageSortDirection() const;

    /**
     * Sets the SortDirection for the message.
     * Note that this option has no meaning if message sorting is set to NoMessageSorting.
     */
    void setMessageSortDirection(SortDirection messageSortDirection);

    /**
     * Enumerates the message sorting options compatible with the specified Threading setting.
     * The returned descriptors are pairs in that the first item is the localized description
     * of the option value and the second item is the integer option value itself.
     */
    [[nodiscard]] static QList<QPair<QString, int>> enumerateMessageSortingOptions(Aggregation::Threading t);

    /**
     * Enumerates the available message sorting directions for the specified MessageSorting option.
     * The returned descriptors are pairs in that the first item is the localized description
     * of the option value and the second item is the integer option value itself.
     * If the returned list is empty then the value of the option is meaningless in the current context.
     */
    [[nodiscard]] static QList<QPair<QString, int>> enumerateMessageSortDirectionOptions(MessageSorting ms);

    /**
     * Enumerates the group sorting options compatible with the specified Grouping.
     * The returned descriptors are pairs in that the first item is the localized description
     * of the option value and the second item is the integer option value itself.
     * If the returned list is empty then the value of the option is meaningless in the current context.
     */
    [[nodiscard]] static QList<QPair<QString, int>> enumerateGroupSortingOptions(Aggregation::Grouping g);

    /**
     * Enumerates the group sort direction options compatible with the specified Grouping and GroupSorting.
     * The returned descriptors are pairs in that the first item is the localized description
     * of the option value and the second item is the integer option value itself.
     * If the returned list is empty then the value of the option is meaningless in the current context.
     */
    [[nodiscard]] static QList<QPair<QString, int>> enumerateGroupSortDirectionOptions(Aggregation::Grouping g, GroupSorting groupSorting);

    /**
     * Checks if this sort order can be used in combination with the given aggregation.
     * Some combinations are not valid, for example the message sorting
     * "most recent in subtree" with a non-threaded aggregation.
     */
    [[nodiscard]] bool validForAggregation(const Aggregation *aggregation) const;

    /**
     * Returns the default sort order for the given aggregation.
     * @param aggregation the given aggregation.
     * @param oldSortOrder the previously used sort order. If possible, the new sort order
     *                     will be based on that old sort order, i.e. the message sorting and
     *                     message sort direction is adopted.
     */
    [[nodiscard]] static SortOrder defaultForAggregation(const Aggregation *aggregation, SortOrder oldSortOrder);

    /**
     * Returns true if the ms parameter specifies a valid MessageSorting option.
     */
    [[nodiscard]] static bool isValidMessageSorting(SortOrder::MessageSorting ms);

    /**
     * Reads the sort order from a config group.
     * @param conf the config group.
     * @param storageId the id of the folder, which is prepended to each key. This way,
     *                  more than one sort order can be saved in the same config group
     * @param storageUsesPrivateSortOrder this boolean will be true if the sort order
     *                                    is private for that folder, and false if the
     *                                    sort order is the global sort order.
     */
    void readConfig(KConfigGroup &conf, const QString &storageId, bool *storageUsesPrivateSortOrder);

    /**
     * Writes the sort order to a config group.
     * @param conf the config group.
     * @param storageId the storage identifier.
     * @param storageUsesPrivateSortOrder if false, this sort order will be saved as the
     *                                    global sort order.
     * @sa readConfig
     */
    void writeConfig(KConfigGroup &conf, const QString &storageId, bool storageUsesPrivateSortOrder) const;

private:
    // Helper function to convert an enum value to a string and back
    [[nodiscard]] static const QString nameForSortDirection(SortDirection sortDirection);
    [[nodiscard]] static const QString nameForMessageSorting(MessageSorting messageSorting);
    [[nodiscard]] static const QString nameForGroupSorting(GroupSorting groupSorting);
    [[nodiscard]] static SortDirection sortDirectionForName(const QString &name);
    [[nodiscard]] static MessageSorting messageSortingForName(const QString &name);
    [[nodiscard]] static GroupSorting groupSortingForName(const QString &name);

    [[nodiscard]] bool readConfigHelper(KConfigGroup &conf, const QString &id);

    MessageSorting mMessageSorting = SortMessagesByDateTime;
    SortDirection mMessageSortDirection = Descending;
    GroupSorting mGroupSorting = NoGroupSorting;
    SortDirection mGroupSortDirection = Ascending;
};
} // namespace Core
} // namespace MessageList
