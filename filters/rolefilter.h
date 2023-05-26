#ifndef ROLEFILTER_H
#define ROLEFILTER_H

#include "filter.h"
#include <QtQmlIntegration>
namespace qqsfpm {

class RoleFilter : public Filter
{
    Q_OBJECT
//    QML_ELEMENT
    Q_PROPERTY(QString roleName READ roleName WRITE setRoleName NOTIFY roleNameChanged)

public:
    using Filter::Filter;
    const QString& roleName() const;
    void setRoleName(const QString& roleName);

Q_SIGNALS:
    void roleNameChanged();

protected:
    QVariant sourceData(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const;

private:
    QString m_roleName;
};

}

#endif // ROLEFILTER_H
