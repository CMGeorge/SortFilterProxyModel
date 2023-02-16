#ifndef ALLOFFILTER_H
#define ALLOFFILTER_H

#include "filtercontainerfilter.h"
#include <QtQmlIntegration>
namespace qqsfpm {

class AllOfFilter : public FilterContainerFilter {
    Q_OBJECT
    QML_NAMED_ELEMENT(AllOf)
public:
    using FilterContainerFilter::FilterContainerFilter;

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;
};

}

#endif // ALLOFFILTER_H
