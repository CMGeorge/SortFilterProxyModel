#ifndef CONTAINSFILTER_H
#define CONTAINSFILTER_H

#include "rolefilter.h"
#include <QVariant>
#include <QDebug>
#include <QtQmlIntegration>
namespace qqsfpm {

class ContainsFilter : public RoleFilter {
    Q_OBJECT
    QML_NAMED_ELEMENT(ContainsFilter)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool shouldStartWith READ shouldStartWith WRITE setShouldStartWith NOTIFY shouldStartWithChanged)

public:
    using RoleFilter::RoleFilter;

    const QString& value() const;
    void setValue(const QString& value);

    bool shouldStartWith() const;
    void setShouldStartWith(bool newShouldStartWith);

protected:
    bool filterRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

Q_SIGNALS:
    void valueChanged();

    void shouldStartWithChanged();

private:
    QString m_value = "";
    bool m_shouldStartWith = false;
};

}

#endif // CONTAINSFILTER_H
