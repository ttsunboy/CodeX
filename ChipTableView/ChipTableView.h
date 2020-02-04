#pragma once

#include "chiptableview_global.h"
#include <QAbstractItemModel>
#include <QItemDelegate>
#include "Chip/Chip.h"

class CHIPTABLEVIEW_EXPORT ChipTableModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	explicit ChipTableModel(QObject* parent = nullptr);

    QModelIndex index(int row, int column,
        const QModelIndex& parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex& child) const override;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    bool hasChildren(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const;

    QVariant headerData(int section, Qt::Orientation orientation,
        int role = Qt::DisplayRole) const override;
	
    void setChips(const QList<GFChip>& chips);
    const QList<GFChip>& chips() const;
	// true��ʾ���� false��ʾ��ֵ��Ĭ��)
    void setShowBlocks(bool b = false);
	// true��ʾ������װ��״̬��Ĭ�ϣ���false����ʾ
    void setShowStatus(bool b = true);
    void refresh()
    {
        beginResetModel();
        endResetModel();
    }

private:
    QList<GFChip> chips_;
    bool showBlocks_;
    bool showStatus_;
};

class CHIPTABLEVIEW_EXPORT ChipTableDelegate : public QItemDelegate
{
    Q_OBJECT;
public:
    explicit ChipTableDelegate(QObject* parent = nullptr);
    ~ChipTableDelegate() = default;

    void paint(QPainter* painter,
        const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
};