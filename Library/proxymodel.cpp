#include "proxymodel.h"

ProxyModel::ProxyModel()
{

}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex indTitle = sourceModel()->index(source_row, 0, source_parent);
    QModelIndex indAuthor = sourceModel()->index(source_row, 1, source_parent);
    QModelIndex indYear = sourceModel()->index(source_row, 2, source_parent);


    QString titleS = sourceModel()->data(indTitle).toString();
    QString authorS = sourceModel()->data(indAuthor).toString();
    QString yearS = sourceModel()->data(indYear).toString();

    return (authorS.contains(this->author) && titleS.contains(this->title) && yearS.contains(this->year));



}

void ProxyModel::setYear(const QString &value)
{
    year = value;
    invalidateFilter();
}

void ProxyModel::setAuthor(const QString &value)
{
    author = value;
    invalidateFilter();
}

void ProxyModel::setTitle(const QString &value)
{
    title = value;
    invalidateFilter();
}
