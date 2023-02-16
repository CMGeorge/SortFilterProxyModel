#include "sorter.h"
#include "rolesorter.h"
#include "stringsorter.h"
#include "filtersorter.h"
#include "expressionsorter.h"
#include "sortercontainer.h"
#include <QQmlEngine>
#include <QCoreApplication>

namespace qqsfpm {

void registerSorterTypes() {
    qmlRegisterUncreatableType<Sorter>("SortFilterProxyModel", 0, 3, "Sorter", "Sorter is an abstract class");
    qmlRegisterType<RoleSorter>("SortFilterProxyModel", 0, 3, "RoleSorter");
    qmlRegisterType<StringSorter>("SortFilterProxyModel", 0, 3, "StringSorter");
    qmlRegisterType<FilterSorter>("SortFilterProxyModel", 0, 3, "FilterSorter");
    qmlRegisterType<ExpressionSorter>("SortFilterProxyModel", 0, 3, "ExpressionSorter");
    qmlRegisterUncreatableType<SorterContainerAttached>("SortFilterProxyModel", 0, 3, "SorterContainer", "SorterContainer can only be used as an attaching type");
}

Q_COREAPP_STARTUP_FUNCTION(registerSorterTypes)

}
