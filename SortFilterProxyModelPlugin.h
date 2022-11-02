
#include <QQmlExtensionPlugin>
#include <QQmlEngine>
#include <QQmlContext>

#include "staticrole.h"
#include "expressionrole.h"
#include "filterrole.h"
#include "joinrole.h"
#include "proxyrole.h"
#include "regexprole.h"
#include "switchrole.h"
#include "proxyrole.h"

#include "qqmlsortfilterproxymodel.h"

#include "alloffilter.h"
#include "anyoffilter.h"
#include "expressionfilter.h"
#include "indexfilter.h"
#include "rangefilter.h"
#include "regexpfilter.h"
#include "valuefilter.h"
#include "containsfilter.h"

 //sorters
#include "sorter.h"
#include "rolesorter.h"
#include "stringsorter.h"
#include "filtersorter.h"
#include "expressionsorter.h"
#include <QDebug>

namespace qqsfpm {
class SortFilterProxyModelPlugin:public QQmlExtensionPlugin{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    SortFilterProxyModelPlugin(QObject *parent=nullptr):QQmlExtensionPlugin(parent){

    }
    void registerTypes(const char *uri) override{
        Q_ASSERT(uri == QLatin1String("SortFilterProxyModel"));
        qmlRegisterModule(uri, 0, 2);
        qmlRegisterType<qqsfpm::QQmlSortFilterProxyModel>(
            "SortFilterProxyModel", 0, 2, "SortFilterProxyModel");
        qmlRegisterUncreatableType<qqsfpm::ProxyRole>(
            "SortFilterProxyModel", 0, 2, "ProxyRole",
            "ProxyRole is an abstract class");
        qmlRegisterType<qqsfpm::JoinRole>("SortFilterProxyModel", 0, 2,
                                          "JoinRole");
        qmlRegisterType<qqsfpm::SwitchRole>("SortFilterProxyModel", 0, 2,
                                            "SwitchRole");
        qmlRegisterType<qqsfpm::ExpressionRole>("SortFilterProxyModel", 0, 2,
                                                "ExpressionRole");
        qmlRegisterType<qqsfpm::RegExpRole>("SortFilterProxyModel", 0, 2,
                                            "RegExpRole");
        qmlRegisterType<qqsfpm::FilterRole>("SortFilterProxyModel", 0, 2,
                                            "FilterRole");
        qmlRegisterType<StaticRole>("SortFilterProxyModel", 0, 2, "StaticRole");

        // FILTERS
        qmlRegisterUncreatableType<Filter>("SortFilterProxyModel", 0, 2,
                                           "Filter",
                                           "Filter is an abstract class");
        qmlRegisterType<ValueFilter>("SortFilterProxyModel", 0, 2,
                                     "ValueFilter");
        qmlRegisterType<ContainsFilter>("SortFilterProxyModel", 0, 2,
                                     "ContainsFilter");
        qmlRegisterType<IndexFilter>("SortFilterProxyModel", 0, 2,
                                     "IndexFilter");
        qmlRegisterType<RegExpFilter>("SortFilterProxyModel", 0, 2,
                                      "RegExpFilter");
        qmlRegisterType<RangeFilter>("SortFilterProxyModel", 0, 2,
                                     "RangeFilter");
        qmlRegisterType<ExpressionFilter>("SortFilterProxyModel", 0, 2,
                                          "ExpressionFilter");
        qmlRegisterType<AnyOfFilter>("SortFilterProxyModel", 0, 2, "AnyOf");
        qmlRegisterType<AllOfFilter>("SortFilterProxyModel", 0, 2, "AllOf");

        //sorters
        qmlRegisterUncreatableType<Sorter>("SortFilterProxyModel", 0, 2, "Sorter", "Sorter is an abstract class");
        qmlRegisterType<RoleSorter>("SortFilterProxyModel", 0, 2, "RoleSorter");
        qmlRegisterType<StringSorter>("SortFilterProxyModel", 0, 2, "StringSorter");
        qmlRegisterType<FilterSorter>("SortFilterProxyModel", 0, 2, "FilterSorter");
        qmlRegisterType<ExpressionSorter>("SortFilterProxyModel", 0, 2, "ExpressionSorter");
    }
};
} // namespace qqsfpm
