#ifndef VALUEFILTER_H
#define VALUEFILTER_H

#include "rolefilter.h"
#include <QVariant>
#include <QtQmlIntegration>
namespace qqsfpm {

class ValueFilter : public RoleFilter {
    Q_OBJECT
    QML_NAMED_ELEMENT(ValueFilter)
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:
    using RoleFilter::RoleFilter;

    const QVariant& value() const;
    void setValue(const QVariant& value);

protected:
    bool filterRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

Q_SIGNALS:
    void valueChanged();

private:
    QVariant m_value;
};

}

#endif // VALUEFILTER_H
