
#include "processenvironmentmodel.h"


ProcessEnvironmentModel::ProcessEnvironmentModel(const QProcessEnvironment &systemEnvironment,
                                                 QObject *parent)
    : QAbstractListModel(parent), m_environment(systemEnvironment),
      m_keys(systemEnvironment.keys())
{
    m_rowCount = m_keys.count();
}


QVariant ProcessEnvironmentModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_rowCount) {
        return QVariant();
    }

    if (role == KeyRole) {
        return m_keys[index.row()];
    }

    const QString defaultValue { "<NONE>" };
    if (role == ValueRole) {
        return m_environment.value(m_keys[index.row()], defaultValue);
    }

    return QVariant();
}


int ProcessEnvironmentModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_rowCount;
}


QHash<int, QByteArray> ProcessEnvironmentModel::roleNames() const
{
    return { { KeyRole, "env_key" }, { ValueRole, "env_val" } };
}
