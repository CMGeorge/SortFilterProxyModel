#ifndef STATICROLE_H
#define STATICROLE_H

#include "proxyroles/singlerole.h"
#include <QVariant>
#include <QtQmlIntegration>
class StaticRole : public qqsfpm::SingleRole {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(bool shouldDecrypt READ shouldDecrypt WRITE setShouldDecrypt
                   NOTIFY shouldDecryptChanged)
public:
    using qqsfpm::SingleRole::SingleRole;

    QVariant value() const;
    void setValue(const QVariant &value);

    bool shouldDecrypt() const { return m_shouldDecrypt; }

public slots:
    void setShouldDecrypt(bool shouldDecrypt) {
        if (m_shouldDecrypt == shouldDecrypt)
            return;

        m_shouldDecrypt = shouldDecrypt;
        emit shouldDecryptChanged(m_shouldDecrypt);
    }

Q_SIGNALS:
    void valueChanged();

    void shouldDecryptChanged(bool shouldDecrypt);

protected:
private:
    QVariant data(const QModelIndex &sourceIndex,
                  const qqsfpm::QQmlSortFilterProxyModel &proxyModel) override;
    QVariant m_value;
    bool m_shouldDecrypt = false;
};

#endif // STATICROLE_H
