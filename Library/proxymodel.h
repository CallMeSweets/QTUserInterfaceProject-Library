#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QSortFilterProxyModel>

class ProxyModel: public QSortFilterProxyModel
{
public:
    ProxyModel();


    void setTitle(const QString &value);
    void setAuthor(const QString &value);
    void setYear(const QString &value);

    // QSortFilterProxyModel interface
protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;

private:
    QString title, author, year;

};

#endif // PROXYMODEL_H
