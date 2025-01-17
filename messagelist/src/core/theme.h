/******************************************************************************
 *
 *  SPDX-FileCopyrightText: 2008 Szymon Tomasz Stefanek <pragma@kvirc.net>
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *
 *******************************************************************************/

#pragma once

#include <QColor>
#include <QList>
#include <QPair>
#include <QString>

#include <core/optionset.h>
#include <core/sortorder.h>

class QPixmap;

namespace MessageList
{
namespace Core
{
/**
 * The Theme class defines the visual appearance of the MessageList.
 *
 * The core structure of the theme is made up of Column objects which
 * are mapped to View (QTreeView) columns. Each theme must provide at least one column.
 *
 * Each column contains a set of Row objects dedicated to message items
 * and a set of Row objects dedicated to group header items. There must be at least
 * one message row and one group header row in each column. Rows are visually
 * ordered from top to bottom.
 *
 * Each Row contains a set of left aligned and a set of right aligned ContentItem objects.
 * The right aligned items are painted from right to left while the left aligned
 * ones are painted from left to right. In Right-To-Left mode the ThemeDelegate
 * follows the exact opposite convention.
 *
 * Each ContentItem object specifies a visual element to be displayed in a View
 * row. The visual elements may be pieces of text (Subject, Date) or icons.
 *
 * The Theme is designed to strictly interoperate with the ThemeDelegate class
 * which takes care of rendering the contents when attached to an QAbstractItemView.
 */
class Theme : public OptionSet
{
public:
    /**
     * The ContentItem class defines a content item inside a Row.
     * Content items are data items extracted from a message or a group header:
     * they can be text, spacers, separators or icons.
     */
    class ContentItem
    {
    private:
        /**
         * Bits for composing the Type enumeration members.
         * We'll be able to test these bits to quickly figure out item properties.
         */
        enum TypePropertyBits {
            /**
             * Item can use the custom color property
             */
            CanUseCustomColor = (1 << 16),
            /**
             * Item can be in a disabled state (for example the attachment icon when there is no attachment)
             */
            CanBeDisabled = (1 << 17),
            /**
             * Item displays some sort of text
             */
            DisplaysText = (1 << 18),
            /**
             * Item makes sense (and can be applied) for messages
             */
            ApplicableToMessageItems = (1 << 19),
            /**
             * Item makes sense (and can be applied) for group headers
             */
            ApplicableToGroupHeaderItems = (1 << 20),
            /**
             * The item takes more horizontal space than the other text items (at the time of writing it's only the subject)
             */
            LongText = (1 << 21),
            /**
             * The item displays an icon
             */
            IsIcon = (1 << 22),
            /**
             * The item is a small spacer
             */
            IsSpacer = (1 << 23),
            /**
             * The item is clickable
             */
            IsClickable = (1 << 24)
        };

    public:
        /**
         * The available ContentItem types.
         * Note that the values in this enum are unique values or'ed with the TypePropertyBits above.
         */
        enum Type {
            /**
             * Display the subject of the message item. This is a long text.
             */
            Subject = 1 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems | LongText,
            /**
             * Formatted date time of the message/group
             */
            Date = 2 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems | ApplicableToGroupHeaderItems,
            /**
             * From: or To: strip, depending on the folder settings
             */
            SenderOrReceiver = 3 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems,
            /**
             * From: strip, always
             */
            Sender = 4 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems,
            /**
             * To: strip, always
             */
            Receiver = 5 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems,
            /**
             * Formatted size of the message
             */
            Size = 6 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems,
            /**
             * The icon that displays the unread/read state (never disabled)
             */
            ReadStateIcon = 7 | ApplicableToMessageItems | IsIcon,
            /**
             * The icon that displays the attachment state (may be disabled)
             */
            AttachmentStateIcon = 8 | CanBeDisabled | ApplicableToMessageItems | IsIcon,
            /**
             * The icon that displays the replied/forwarded state (may be disabled)
             */
            RepliedStateIcon = 9 | CanBeDisabled | ApplicableToMessageItems | IsIcon,
            /**
             * The group header label
             */
            GroupHeaderLabel = 10 | DisplaysText | CanUseCustomColor | ApplicableToGroupHeaderItems,
            /**
             * The ActionItem state icon. May be disabled. Clickable (cycles todo->nothing)
             */
            ActionItemStateIcon = 11 | CanBeDisabled | ApplicableToMessageItems | IsIcon | IsClickable,
            /**
             * The Important tag icon. May be disabled. Clickable (cycles important->nothing)
             */
            ImportantStateIcon = 12 | CanBeDisabled | ApplicableToMessageItems | IsIcon | IsClickable,
            /**
             * The Spam/Ham state icon. May be disabled. Clickable (cycles spam->ham->nothing)
             */
            SpamHamStateIcon = 13 | CanBeDisabled | ApplicableToMessageItems | IsIcon | IsClickable,
            /**
             * The Watched/Ignored state icon. May be disabled. Clickable (cycles watched->ignored->nothing)
             */
            WatchedIgnoredStateIcon = 14 | CanBeDisabled | ApplicableToMessageItems | IsIcon | IsClickable,
            /**
             * The Expanded state icon for group headers. May be disabled. Clickable (expands/collapses the group)
             */
            ExpandedStateIcon = 15 | CanBeDisabled | ApplicableToGroupHeaderItems | IsIcon | IsClickable,
            /**
             * The Encryption state icon for messages. May be disabled (no encryption).
             */
            EncryptionStateIcon = 16 | CanBeDisabled | ApplicableToMessageItems | IsIcon,
            /**
             * The Signature state icon for messages. May be disabled (no signature)
             */
            SignatureStateIcon = 17 | CanBeDisabled | ApplicableToMessageItems | IsIcon,
            /**
             * A vertical separation line.
             */
            VerticalLine = 18 | CanUseCustomColor | ApplicableToMessageItems | ApplicableToGroupHeaderItems | IsSpacer,
            /**
             * A small empty spacer usable as separator.
             */
            HorizontalSpacer = 19 | ApplicableToMessageItems | ApplicableToGroupHeaderItems | IsSpacer,
            /**
             * The date of the most recent message in subtree
             */
            MostRecentDate = 20 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems | ApplicableToGroupHeaderItems,
            /**
             * The combined icon that displays the unread/read/replied/forwarded state (never disabled)
             */
            CombinedReadRepliedStateIcon = 21 | ApplicableToMessageItems | IsIcon,
            /**
             * The list of MessageItem::Tag entries
             */
            TagList = 22 | ApplicableToMessageItems | IsIcon,
            /**
             * Whether the message has a annotation/note
             */
            AnnotationIcon = 23 | ApplicableToMessageItems | IsIcon | CanBeDisabled | IsClickable,

            /**
             * Whether the message is an invitation
             */
            InvitationIcon = 24 | ApplicableToMessageItems | IsIcon,
            /**
             * Folder of the message
             */
            Folder = 25 | DisplaysText | CanUseCustomColor | ApplicableToMessageItems
#if 0
                     TotalMessageCount
                     UnreadMessageCount
                     NewMessageCount
#endif
        };

        enum Flags {
            HideWhenDisabled = 1, ///< In disabled state the icon should take no space (overrides SoftenByBlendingWhenDisabled)
            SoftenByBlendingWhenDisabled = (1 << 1), ///< In disabled state the icon should be still shown, but made very soft by alpha blending
            UseCustomColor = (1 << 2), ///< For text and vertical line. If set then always use a custom color, otherwise use default text color
            IsBold = (1 << 3), ///< For text items. If set then always show as bold, otherwise use the default font weight
            IsItalic = (1 << 4), ///< Fot text items. If set then always show as italic, otherwise use the default font style
            SoftenByBlending = (1 << 5) ///< For text items: use 60% opacity.
        };

    private:
        Type mType; ///< The type of item
        unsigned int mFlags; ///< The flags of the item

        QColor mCustomColor; ///< The color to use with this content item, meaningful only if canUseCustomColor() return true.

    public:
        /**
         * Creates a ContentItem with the specified type.
         * A content item must be added to a theme Row.
         */
        explicit ContentItem(Type type);
        /**
         * Creates a ContentItem that is a copy of the content item src.
         * A content item must be added to a theme Row.
         */
        explicit ContentItem(const ContentItem &src);

    public:
        /**
         * Returns the type of this content item
         */
        [[nodiscard]] Type type() const;

        /**
         * Returns true if this ContentItem can be in a "disabled" state.
         * The attachment state icon, for example, can be disabled when the related
         * message has no attachments. For such items the HideWhenDisabled
         * and SoftenByBlendingWhenDisabled flags are meaningful.
         */
        [[nodiscard]] bool canBeDisabled() const;

        /**
         * Returns true if this ContentItem can make use of a custom color.
         */
        [[nodiscard]] bool canUseCustomColor() const;

        /**
         * Returns true if this item displays some kind of text.
         * Items that display text make use of the customFont() setting.
         */
        [[nodiscard]] bool displaysText() const;

        /**
         * Returns true if this item displays a long text.
         * The returned value makes sense only if displaysText() returned true.
         */
        [[nodiscard]] bool displaysLongText() const;

        /**
         * Returns true if this item displays an icon.
         */
        [[nodiscard]] bool isIcon() const;
        /**
         * Returns true if clicking on this kind of item can perform an action
         */
        [[nodiscard]] bool isClickable() const;

        /**
         * Returns true if this item is a small spacer
         */
        [[nodiscard]] bool isSpacer() const;

        /**
         * Static test that returns true if an instance of ContentItem with the
         * specified type makes sense in a Row for message items.
         */
        static bool applicableToMessageItems(Type type);

        /**
         * Static test that returns true if an instance of ContentItem with the
         * specified type makes sense in a Row for group header items.
         */
        static bool applicableToGroupHeaderItems(Type type);

        /**
         * Returns a descriptive name for the specified content item type
         */
        static QString description(Type type);

        /**
         * Returns true if this item uses a custom color.
         * The return value of this function is valid only if canUseCustomColor() returns true.
         */
        bool useCustomColor() const;

        /**
         * Makes this item use the custom color that can be set by setCustomColor().
         * The custom color is meaningful only if canUseCustomColor() returns true.
         */
        void setUseCustomColor(bool useCustomColor);

        /**
         * Returns true if this item uses a bold text.
         * The return value of this function is valid only if displaysText() returns true.
         */
        bool isBold() const;

        /**
         * Makes this item use a bold font.
         */
        void setBold(bool isBold);

        /**
         * Returns true if this item uses an italic text.
         * The return value of this function is valid only if displaysText() returns true.
         */
        bool isItalic() const;

        /**
         * Makes this item use italic font.
         */
        void setItalic(bool isItalic);

        /**
         * Returns true if this item should be hidden when in disabled state.
         * Hidden content items simply aren't painted and take no space.
         * This flag has meaning only on items for that canBeDisabled() returns true.
         */
        bool hideWhenDisabled() const;

        /**
         * Sets the flag that causes this item to be hidden when disabled.
         * Hidden content items simply aren't painted and take no space.
         * This flag overrides the setSoftenByBlendingWhenDisabled() setting.
         * This flag has meaning only on items for that canBeDisabled() returns true.
         */
        void setHideWhenDisabled(bool hideWhenDisabled);

        /**
         * Returns true if this item should be painted in a "soft" fashion when
         * in disabled state. Soft icons are painted with very low opacity.
         * This flag has meaning only on items for that canBeDisabled() returns true.
         */
        bool softenByBlendingWhenDisabled() const;

        /**
         * Sets the flag that causes this item to be painted "softly" when disabled.
         * Soft icons are painted with very low opacity.
         * This flag may be overridden by the setHideWhenDisabled() setting.
         * This flag has meaning only on items for that canBeDisabled() returns true.
         */
        void setSoftenByBlendingWhenDisabled(bool softenByBlendingWhenDisabled);

        /**
         * Returns true if this item should be always painted in a "soft" fashion.
         * Meaningful only for text items.
         */
        bool softenByBlending() const;

        /**
         * Sets the flag that causes this item to be painted "softly".
         * Meaningful only for text items.
         */
        void setSoftenByBlending(bool softenByBlending);

        /**
         * Returns the custom color set for this item.
         * The return value is meaningful only if canUseCustomColor() returns true
         * returns true and setUseCustomColor( true ) has been called.
         */
        const QColor &customColor() const;

        /**
         * Sets the custom color for this item. Meaningful only if canUseCustomColor()
         * returns true and you call setUseCustomColor( true )
         */
        void setCustomColor(const QColor &clr);

        // Stuff used by ThemeDelegate. This section should be protected but some gcc
        // versions seem to get confused with nested class and friend declarations
        // so for portability we're using a public interface also here.

        /**
         * Handles content item saving (used by Theme::Row::save())
         */
        void save(QDataStream &stream) const;

        /**
         * Handles content item loading (used by Theme::Row::load())
         */
        bool load(QDataStream &stream, int themeVersion);
    };

    /**
     * The Row class defines a row of items inside a Column.
     * The Row has a list of left aligned and a list of right aligned ContentItems.
     */
    class Row
    {
    public:
        explicit Row();
        explicit Row(const Row &src);
        ~Row();

    private:
        QList<ContentItem *> mLeftItems; ///< The list of left aligned items
        QList<ContentItem *> mRightItems; ///< The list of right aligned items

        bool LoadContentItem(int val, QDataStream &stream, int themeVersion, bool leftItem);

    public:
        /**
         * Returns the list of left aligned items for this row
         */
        const QList<ContentItem *> &leftItems() const;

        /**
         * Removes all the left items from this row: the items are deleted.
         */
        void removeAllLeftItems();

        /**
         * Adds a left aligned item to this row. The row takes the ownership
         * of the ContentItem pointer.
         */
        void addLeftItem(ContentItem *item);

        /**
         * Adds a left aligned item at the specified position in this row. The row takes the ownership
         * of the ContentItem pointer.
         */
        void insertLeftItem(int idx, ContentItem *item);

        /**
         * Removes the specified left aligned content item from this row.
         * The item is NOT deleted.
         */
        void removeLeftItem(ContentItem *item);

        /**
         * Returns the list of right aligned items for this row
         */
        const QList<ContentItem *> &rightItems() const;

        /**
         * Removes all the right items from this row. The items are deleted.
         */
        void removeAllRightItems();

        /**
         * Adds a right aligned item to this row. The row takes the ownership
         * of the ContentItem pointer. Please note that the first right aligned item
         * will start at the right edge, the second right aligned item will come after it etc...
         */
        void addRightItem(ContentItem *item);

        /**
         * Adds a right aligned item at the specified position in this row. The row takes the ownership
         * of the ContentItem pointer. Remember that right item positions go from right to left.
         */
        void insertRightItem(int idx, ContentItem *item);

        /**
         * Removes the specified right aligned content item from this row.
         * The item is NOT deleted.
         */
        void removeRightItem(ContentItem *item);

        /**
         * Returns true if this row contains text items.
         * This is useful if you want to know if the column should just get
         * its minimum allowable space or it should get more.
         */
        bool containsTextItems() const;

        /**
         * Handles row saving (used by Theme::Column::save())
         */
        void save(QDataStream &stream) const;

        /**
         * Handles row loading (used by Theme::Column::load())
         */
        bool load(QDataStream &stream, int themeVersion);
    };

    /**
     * The Column class defines a view column available inside this theme.
     * Each Column has a list of Row items that define the visible rows.
     */
    class Column
    {
    public:
        /**
         * A set of shared runtime data. This is used to store a set of "override" settings
         * at runtime. For instance, the width of the visible columns of a skin are stored here.
         */
        class SharedRuntimeData
        {
        private:
            int mReferences; ///< The number of external references to this shared data object

            int mCurrentlyVisible; ///< Is this column currently visible ? always valid (eventually set from default)
            double mCurrentWidth; ///< The current width of this column, -1 if not valid (never set)
        public:
            /**
             * Create a shared runtime data object
             */
            explicit SharedRuntimeData(bool currentlyVisible, double currentWidth);

            /**
             * Destroy a shared runtime data object
             */
            ~SharedRuntimeData();

        public:
            /**
             * Increments the reference count for this shared runtime data object.
             */
            void addReference();

            /**
             * Decrements the reference count for this shared runtime data object.
             * Returns true if there are other references and false otherwise (so the data can be safely deleted)
             */
            bool deleteReference();

            /**
             * Returns the current number of reference counts, that is, the number of
             * Theme::Column objects that use this SharedRuntimeData instance.
             */
            int referenceCount() const;

            /**
             * Returns the current visibility state
             */
            bool currentlyVisible() const;

            /**
             * Sets the current visibility state
             */
            void setCurrentlyVisible(bool visible);

            /**
             * Returns the current width or -1 if the width is unspecified/invalid
             */
            double currentWidth() const;

            /**
             * Sets the current width of the column
             */
            void setCurrentWidth(double currentWidth);

            /**
             * Saves this runtime data to the specified stream
             */
            void save(QDataStream &stream) const;

            /**
             * Loads the shared runtime data from the specified stream
             * assuming that it uses the specified theme version.
             * Returns true on success and false if the data can't be loaded.
             */
            bool load(QDataStream &stream, int themeVersion);
        };

    public:
        /**
         * Create an empty column with default settings
         */
        explicit Column();
        /**
         * Create an exact copy of the column src.
         * The shared runtime data is not copied (only a reference is added).
         * If you need to create an independent clone then please use detach()
         * after the construction.
         */
        explicit Column(const Column &src);
        /**
         * Kill a column object
         */
        ~Column();

    private:
        QString mLabel; ///< The label visible in the column header
        QString mPixmapName; ///< The icon's name visible in the column header if it was set
        bool mVisibleByDefault; ///< Is this column visible by default ?
        bool mIsSenderOrReceiver; ///< If this column displays the sender/receiver field then we will update its label on the fly
        SortOrder::MessageSorting mMessageSorting; ///< The message sort order we switch to when clicking on this column
        QList<Row *> mGroupHeaderRows; ///< The list of rows we display in this column for a GroupHeaderItem
        QList<Row *> mMessageRows; ///< The list of rows we display in this column for a MessageItem

        SharedRuntimeData *mSharedRuntimeData = nullptr; ///< A pointer to the shared runtime data: shared between all instances of a theme with the same id
    public:
        /**
         * Returns the label set for this column
         */
        const QString &label() const;

        /**
         * Sets the label for this column
         */
        void setLabel(const QString &label);

        /**
         * Returns the icon's name (used in SmallIcon) set for this column
         */
        const QString &pixmapName() const;

        /**
         * Sets the icon's name (used in SmallIcon) for this column
         */
        void setPixmapName(const QString &pixmapName);

        /**
         * Returns true if this column is marked as "sender/receiver" and we should
         * update its label on-the-fly.
         */
        bool isSenderOrReceiver() const;

        /**
         * Marks this column as containing the "sender/receiver" field.
         * Such columns will have the label automatically updated.
         */
        void setIsSenderOrReceiver(bool sor);

        /**
         * Returns true if this column has to be shown by default
         */
        bool visibleByDefault() const;

        /**
         * Sets the "visible by default" tag for this column.
         */
        void setVisibleByDefault(bool vbd);

        /**
         * Detaches the shared runtime data object and makes this object
         * totally independent. The shared runtime data is initialized to default values.
         */
        void detach();

        /**
         * Returns the sort order for messages that we should switch to
         * when clicking on this column's header (if visible at all).
         */
        SortOrder::MessageSorting messageSorting() const;

        /**
         * Sets the sort order for messages that we should switch to
         * when clicking on this column's header (if visible at all).
         */
        void setMessageSorting(SortOrder::MessageSorting ms);

        /**
         * Returns the current shared visibility state for this column.
         * This state is shared between all the instances of this theme.
         */
        bool currentlyVisible() const;

        /**
         * Sets the current shared visibility state for this column.
         * This state is shared between all the instances of this theme.
         */
        void setCurrentlyVisible(bool currentlyVisible);

        /**
         * Returns the current shared width setting for this column
         * or -1 if the width is not specified and should be auto-determined.
         * This state is shared between all the instances of this theme.
         */
        double currentWidth() const;

        /**
         * Sets the current shared width setting for this column.
         * This state is shared between all the instances of this theme.
         */
        void setCurrentWidth(double currentWidth);

        /**
         * Returns the list of rows visible in this column for a MessageItem
         */
        const QList<Row *> &messageRows() const;

        /**
         * Removes all the message rows from this column.
         */
        void removeAllMessageRows();

        /**
         * Appends a message row to this theme column. The Theme takes
         * the ownership of the Row pointer.
         */
        void addMessageRow(Row *row);

        /**
         * Inserts a message row to this theme column in the specified position. The Theme takes
         * the ownership of the Row pointer.
         */
        void insertMessageRow(int idx, Row *row);

        /**
         * Removes the specified message row. The row is NOT deleted.
         */
        void removeMessageRow(Row *row);

        /**
         * Returns the list of rows visible in this column for a GroupHeaderItem
         */
        const QList<Row *> &groupHeaderRows() const;

        /**
         * Removes all the group header rows from this column.
         */
        void removeAllGroupHeaderRows();

        /**
         * Appends a group header row to this theme. The Theme takes
         * the ownership of the Row pointer.
         */
        void addGroupHeaderRow(Row *row);

        /**
         * Inserts a group header row to this theme column in the specified position. The Theme takes
         * the ownership of the Row pointer.
         */
        void insertGroupHeaderRow(int idx, Row *row);

        /**
         * Removes the specified group header row. The row is NOT deleted.
         */
        void removeGroupHeaderRow(Row *row);

        /**
         * Returns true if this column contains text items.
         * This is useful if you want to know if the column should just get
         * its minimum allowable space or it should get more.
         */
        bool containsTextItems() const;

        /**
         * Handles column saving (used by Theme::save())
         */
        void save(QDataStream &stream) const;

        /**
         * Handles column loading (used by Theme::load())
         */
        bool load(QDataStream &stream, int themeVersion);
    };

public:
    /**
     * Creates a totally uninitialized theme object.
     */
    explicit Theme();

    /**
     * Creates a theme object with the specified name and description.
     */
    explicit Theme(const QString &name, const QString &description, bool readOnly = false);

    /**
     * Creates an exact copy of the theme sharing the same runtime data.
     * If you need an exact clone please use detach() and generateUniqueId() just
     * after creation.
     */
    explicit Theme(const Theme &src);

    /**
     * Destroys this theme object.
     */
    ~Theme() override;

    static bool compareName(Theme *theme1, Theme *theme2)
    {
        return theme1->name() < theme2->name();
    }

public:
    /**
     * Which color do we use to paint group header background ?
     */
    enum GroupHeaderBackgroundMode {
        Transparent, ///< No background at all: use style default
        AutoColor, ///< Automatically determine the color (somewhere in the middle between background and text)
        CustomColor, ///< Use a custom color
    };

    /**
     * How do we paint group header background ?
     */
    enum GroupHeaderBackgroundStyle {
        PlainRect, ///< One plain rect per column
        PlainJoinedRect, ///< One big plain rect for all the columns
        RoundedRect, ///< One rounded rect per column
        RoundedJoinedRect, ///< One big rounded rect for all the columns
        GradientRect, ///< One rounded gradient filled rect per column
        GradientJoinedRect, ///< One big rounded gradient rect for all the columns
        StyledRect, ///< One styled rect per column
        StyledJoinedRect, ///< One big styled rect per column
    };

    /**
     * How do we manage the QHeaderView attached to our View ?
     */
    enum ViewHeaderPolicy {
        ShowHeaderAlways,
        NeverShowHeader,
        // ShowWhenMoreThanOneColumn,  ///< This doesn't work at the moment (since without header we don't have means for showing columns back)
    };

    enum ThemeIcon {
        IconNew,
        IconUnread,
        IconRead,
        IconDeleted,
        IconReplied,
        IconRepliedAndForwarded,
        IconQueued,
        IconActionItem,
        IconSent,
        IconForwarded,
        IconImportant,
        IconWatched,
        IconIgnored,
        IconSpam,
        IconHam,
        IconFullySigned,
        IconPartiallySigned,
        IconUndefinedSigned,
        IconNotSigned,
        IconFullyEncrypted,
        IconPartiallyEncrypted,
        IconUndefinedEncrypted,
        IconNotEncrypted,
        IconAttachment,
        IconAnnotation,
        IconInvitation,
        IconShowMore,
        IconShowLess,
        IconVerticalLine,
        IconHorizontalSpacer,

        _IconCount
    };

private:
    QList<Column *> mColumns; ///< The list of columns available in this theme

    // pixmaps cache. Mutable, so it can be lazily populated from const methods
    mutable QList<QPixmap *> mPixmaps;

    GroupHeaderBackgroundMode mGroupHeaderBackgroundMode; ///< How do we paint group header background ?
    QColor mGroupHeaderBackgroundColor; ///< The background color of the message group, used only if CustomColor
    GroupHeaderBackgroundStyle mGroupHeaderBackgroundStyle; ///< How do we paint group header background ?
    ViewHeaderPolicy mViewHeaderPolicy; ///< Do we show the header or not ?
    int mIconSize; ///< The icon size for this theme, 16 is the default
public:
    /**
     * Detaches this object from the shared runtime data for columns.
     */
    void detach();

    /**
     * Resets the column state (visibility and width) to their default values (the "visible by default" ones).
     */
    void resetColumnState();

    /**
     * Resets the column sizes to "default" (subset of resetColumnState() above).
     */
    void resetColumnSizes();

    /**
     * Returns the list of columns available in this theme
     */
    const QList<Column *> &columns() const;

    /**
     * Returns a pointer to the column at the specified index or 0 if there is no such column
     */
    Column *column(int idx) const;

    void moveColumn(int idx, int newPosition);

    /**
     * Removes all columns from this theme
     */
    void removeAllColumns();

    /**
     * Appends a column to this theme
     */
    void addColumn(Column *column);

    /**
     * Inserts a column to this theme at the specified position.
     */
    void insertColumn(int idx, Column *column);

    /**
     * Removes the specified message row. The row is NOT deleted.
     */
    void removeColumn(Column *col);

    /**
     * Returns the group header background mode for this theme.
     */
    GroupHeaderBackgroundMode groupHeaderBackgroundMode() const;

    /**
     * Sets the group header background mode for this theme.
     * If you set it to CustomColor then please also setGroupHeaderBackgroundColor()
     */
    void setGroupHeaderBackgroundMode(GroupHeaderBackgroundMode bm);

    /**
     * Returns the group header background color for this theme.
     * This color is used only if groupHeaderBackgroundMode() is set to CustomColor.
     */
    const QColor &groupHeaderBackgroundColor() const;

    /**
     * Sets the group header background color for this theme.
     * This color is used only if groupHeaderBackgroundMode() is set to CustomColor.
     */
    void setGroupHeaderBackgroundColor(const QColor &clr);

    /**
     * Returns the group header background style for this theme.
     * The group header background style makes sense only if groupHeaderBackgroundMode() is
     * set to something different than Transparent.
     */
    GroupHeaderBackgroundStyle groupHeaderBackgroundStyle() const;

    /**
     * Sets the group header background style for this theme.
     * The group header background style makes sense only if groupHeaderBackgroundMode() is
     * set to something different than Transparent.
     */
    void setGroupHeaderBackgroundStyle(GroupHeaderBackgroundStyle groupHeaderBackgroundStyle);

    /**
     * Enumerates the available group header background styles.
     * The returned descriptors are pairs in that the first item is the localized description
     * of the option value and the second item is the integer option value itself.
     */
    static QList<QPair<QString, int>> enumerateGroupHeaderBackgroundStyles();

    /**
     * Returns the currently set ViewHeaderPolicy
     */
    ViewHeaderPolicy viewHeaderPolicy() const;

    /**
     * Sets the ViewHeaderPolicy for this theme
     */
    void setViewHeaderPolicy(ViewHeaderPolicy vhp);

    /**
     * Returns the currently set icon size
     */
    int iconSize() const;

    /**
     * Sets the icon size for this theme.
     * Please note that the function will not let you set insane values.
     * The allowable range is [8,64]
     */
    void setIconSize(int iconSize);

    /**
     * Enumerates the available view header policy options.
     * The returned descriptors are pairs in that the first item is the localized description
     * of the option value and the second item is the integer option value itself.
     */
    static QList<QPair<QString, int>> enumerateViewHeaderPolicyOptions();

    inline const QPixmap *pixmap(ThemeIcon icon) const
    {
        if (Q_UNLIKELY(mPixmaps.isEmpty())) {
            populatePixmapCache();
        }
        return mPixmaps[icon];
    }

protected:
    /**
     * Pure virtual reimplemented from OptionSet.
     */
    void save(QDataStream &stream) const override;

    /**
     * Pure virtual reimplemented from OptionSet.
     */
    bool load(QDataStream &stream) override;

    void clearPixmapCache() const;
    void populatePixmapCache() const;
};
} // namespace Core
} // namespace MessageList
