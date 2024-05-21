#ifndef HISTORY_HPP
#define HISTORY_HPP

#include <string>

#include <QAbstractListModel>
#include <QList>

namespace dvt {

class History : public QAbstractTableModel
{
    Q_OBJECT

public:
    struct Record
    {
        Record()  = default;
        ~Record() = default;

        Record(int input_base, int output_base,
               const std::string& input, const std::string& output);

        int         input_base  {};
        int         output_base {};
        std::string input       {};
        std::string output      {};
    };

    enum RoleNames
    {
        InputBaseRole = Qt::UserRole + 1,
        InputRole,
        OutputBaseRole,
        OutputRole
    };

public:
    static auto getInstance() noexcept -> History*;

public:
    auto rowCount(const QModelIndex& index = QModelIndex{}) const -> int override;
    auto columnCount(const QModelIndex& index = QModelIndex{}) const -> int override;
    auto data(const QModelIndex& index, int role = Qt::DisplayRole) const -> QVariant override;
    auto headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const -> QVariant override;
    auto roleNames() const -> QHash<int, QByteArray> override;

public:
    auto add(const Record& record) noexcept -> void;

private:
    explicit History(QObject* parent = nullptr);

private:
    QStringList   m_column_names {};
    QList<Record> m_data         {};
};

} // dvt

#endif // HISTORY_HPP
