#ifndef ANYOFFILTER_H
#define ANYOFFILTER_H

#include "filtercontainerfilter.h"
#include <QtQmlIntegration>
#include <QObject>

namespace qqsfpm {

class AnyOfFilter : public FilterContainerFilter {
    Q_OBJECT
    QML_NAMED_ELEMENT(AnyOf)
public:
    using FilterContainerFilter::FilterContainerFilter;
    inline explicit AnyOfFilter(QObject *parent=Q_NULLPTR):FilterContainerFilter(parent){};
protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;
};

}

#endif // ANYOFFILTER_H
