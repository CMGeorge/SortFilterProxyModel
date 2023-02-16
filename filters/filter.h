#ifndef FILTER_H
#define FILTER_H

#include <QObject>
#include <QtQmlIntegration>
namespace qqsfpm {

class QQmlSortFilterProxyModel;

class Filter : public QObject
{
    Q_OBJECT
    QML_NAMED_ELEMENT(Filter)
    QML_UNCREATABLE("Filter is an abstract class")
    Q_PROPERTY(bool enabled READ enabled WRITE setEnabled NOTIFY enabledChanged)
    Q_PROPERTY(bool inverted READ inverted WRITE setInverted NOTIFY invertedChanged)

public:
    explicit Filter(QObject *parent = nullptr);
    virtual ~Filter() = default;

    bool enabled() const;
    void setEnabled(bool enabled);

    bool inverted() const;
    void setInverted(bool inverted);

    bool filterAcceptsRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const;

    virtual void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel);

Q_SIGNALS:
    void enabledChanged();
    void invertedChanged();
    void invalidated();

protected:
    virtual bool filterRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const = 0;
    void invalidate();

private:
    bool m_enabled = true;
    bool m_inverted = false;
};

}

#endif // FILTER_H
