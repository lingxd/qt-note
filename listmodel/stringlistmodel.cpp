#include "stringlistmodel.h"

StringListModel::StringListModel(const QStringList &string_list, QObject *parent)
    : QAbstractListModel{parent}, string_list_{string_list}
{

}

QVariant StringListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (index.row() >= string_list_.size()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        return string_list_.at(index.row());
    } else {
        return QVariant();
    }
}

bool StringListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        string_list_.replace(index.row(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

int StringListModel::rowCount(const QModelIndex &parent) const
{
    return string_list_.count();
}

QVariant StringListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        return QString("Column %1").arg(section);
    } else {
        return QString("Row %1").arg(section);
    }
}

bool StringListModel::insertRows(int position, int rows, const QModelIndex &index)
{
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        string_list_.insert(position + row, QString::number(row));
    }
    endInsertRows();
}

bool StringListModel::removeRows(int position, int rows, const QModelIndex &index)
{
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row) {
        string_list_.removeAt(position);
    }
    endRemoveRows();
}

Qt::ItemFlags StringListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid()) {
        return Qt::ItemIsEditable;
    }

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}
