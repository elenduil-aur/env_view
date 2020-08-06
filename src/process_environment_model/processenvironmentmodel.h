
#ifndef RAMP_START_PROCESS_ENVIRONMENT_MODEL_H_
#define RAMP_START_PROCESS_ENVIRONMENT_MODEL_H_


#include <QAbstractListModel>
#include <QProcessEnvironment>


class ProcessEnvironmentModel : public QAbstractListModel
{

    Q_OBJECT

public:
    enum ProcessEnvironmentRoles {
        KeyRole = Qt::UserRole + 1,
        ValueRole
    };
    ProcessEnvironmentModel(const QProcessEnvironment &systemEnvironment,
                            QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;


protected:
    QHash<int, QByteArray> roleNames() const override;


private:
    const QProcessEnvironment &m_environment;
    const QStringList m_keys;
    int m_rowCount;


};


#endif // RAMP_START_PROCESS_ENVIRONMENT_MODEL_H_
