#ifndef PROXYROLE_H
#define PROXYROLE_H

#include <QObject>
#include <QMutex>
#include <qqmlintegration.h>
namespace qqsfpm {

class QQmlSortFilterProxyModel;

class ProxyRole : public QObject
{
    Q_OBJECT
    QML_NAMED_ELEMENT(ProxyRole)
    QML_UNCREATABLE("ProxyRole is an abstract class")
public:
    using QObject::QObject;
    ~ProxyRole() override = default;

    QVariant roleData(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel, const QString& name);
    virtual void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel);

    virtual QStringList names() = 0;

protected:
    void invalidate();

Q_SIGNALS:
    void invalidated();
    void namesAboutToBeChanged();
    void namesChanged();

private:
    virtual QVariant data(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel, const QString& name) = 0;

    QMutex m_mutex;
};

}

#endif // PROXYROLE_H
