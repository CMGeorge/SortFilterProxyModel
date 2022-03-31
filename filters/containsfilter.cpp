#include "containsfilter.h"

namespace qqsfpm {

/*!
    \qmltype ContainsFilter
    \inherits RoleFilter
    \inqmlmodule SortFilterProxyModel
    \brief Filters rows matching containing string

    A ValueFilter is a simple \l RoleFilter that accepts rows matching exactly the filter's value

    In the following example, only rows with their \c favorite role set to \c true will be accepted when the checkbox is checked :
    \code
    CheckBox {
       id: showOnlyFavoriteCheckBox
    }

    SortFilterProxyModel {
       sourceModel: contactModel
       filters: ContainsFilter {
           roleName: "favorite"
           value: "search string"
           shouldStart: true
           enabled: showOnlyFavoriteCheckBox.checked
       }
    }
    \endcode

*/

/*!
    \qmlproperty variant ValueFilter::value

    This property holds the value used to filter the contents of the source model.
*/

const QString &ContainsFilter::value() const
{
    return m_value;
}

void ContainsFilter::setValue(const QString& value)
{
//    qDebug()<<"Set new search filter "<<value<<" whit should start "<<m_shouldStartWith;

    if (m_value == value)
        return;

    m_value = value;
    Q_EMIT valueChanged();
    invalidate();
}

bool ContainsFilter::filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const
{
    if (m_value.isEmpty()) return false;
    else{
        if (m_shouldStartWith){
            return sourceData(sourceIndex, proxyModel).toString().startsWith(m_value,Qt::CaseInsensitive);
        }else{
            return sourceData(sourceIndex, proxyModel).toString().contains(m_value,Qt::CaseInsensitive);

        }
    }
//    return !m_value.isValid() || (m_shouldStartWith?m_value == sourceData(sourceIndex, proxyModel);
}

bool ContainsFilter::shouldStartWith() const
{
    return m_shouldStartWith;
}

void ContainsFilter::setShouldStartWith(bool newShouldStartWith)
{
    if (m_shouldStartWith == newShouldStartWith)
        return;
    m_shouldStartWith = newShouldStartWith;
    emit shouldStartWithChanged();
}

}
