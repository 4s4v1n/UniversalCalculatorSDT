#include "history.hpp"

namespace dvt
{

History::History(QObject *parent):
    QAbstractTableModel{parent}
{
    m_column_names << tr("основание p1") << tr("p1") << tr("основание p2") << tr("p2");
}

auto History::getInstance() noexcept -> History*
{
    static History instance {};
    return &instance;
}

History::Record::Record(const int input_base, const int output_base,
                        const std::string& input, const std::string& output):
    input_base{input_base},
    output_base{output_base},
    input{input},
    output{output}
{}

auto History::add(const Record& record) noexcept -> void
{
    const int size {static_cast<int>(m_data.size())};

    beginInsertRows(QModelIndex{}, size, size + 1);
    m_data.push_back(record);
    endInsertRows();
}

auto History::rowCount(const QModelIndex& index) const -> int
{
    return static_cast<int>(m_data.size());
}

auto History::columnCount(const QModelIndex& index) const -> int
{
    return static_cast<int>(m_column_names.size());
}

auto History::data(const QModelIndex& index, int role) const -> QVariant
{
    if (!index.isValid())
    {
        return QVariant{};
    }

    const auto row {index.row()};
    const auto col {index.column()};

    if (row < 0 || row >= m_data.size())
    {
        return QVariant{};
    }
    if (col < 0 || col >= m_column_names.size())
    {
        return QVariant{};
    }


    const auto& data {m_data.value(row)};
    switch (col)
    {
        case 0:  return QVariant::fromValue(data.input_base);
        case 1:  return QVariant::fromValue(QString::fromStdString(data.input));
        case 2:  return QVariant::fromValue(data.output_base);
        case 3:  return QVariant::fromValue(QString::fromStdString(data.output));
        default: return QVariant{};
    }
}

auto History::roleNames() const -> QHash<int, QByteArray>
{
    static QHash<int, QByteArray> roles {QAbstractTableModel::roleNames()};
    return roles;
}

auto History::headerData(int section, Qt::Orientation orientation, int role) const -> QVariant
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole || section >= columnCount()) {
        return QVariant{};
    }
    return m_column_names.at(section);
}

} // dvt
