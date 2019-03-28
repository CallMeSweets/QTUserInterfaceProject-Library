#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel (parent)
{

}

int TableModel::rowCount(const QModelIndex &parent) const
{
    return bookList.size();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole)
    {

      if(index.column() == 0)
          return bookList[index.row()]->getTitle();
      if(index.column() == 1)
          return bookList[index.row()]->getAuthor();
      if(index.column() == 2)
          return bookList[index.row()]->getYear();

     }


    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            switch (section) {
            case 0:
                return QString("Title");
            case 1:
                return QString("Author");
            case 2:
                return QString("Year");
            }
        }
    return QVariant();
}





void TableModel::loadFromFile()
{
    QFile file(FILE_PATH);
        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::information(nullptr, "File can not be open", file.errorString());

        QTextStream in(&file);

        QStringList list;
        while(!in.atEnd()){

            bookList.append(new Book(QString(in.readLine()), QString(in.readLine()), in.readLine().toInt()));
        }



        file.close();



}

void TableModel::saveToFile()
{
    QFile file(FILE_PATH);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
            QMessageBox::information(nullptr, "File can not be open", file.errorString());

        QTextStream out(&file);

        for(Book *book: bookList){
            out << book->getTitle() << '\n' << book->getAuthor() << '\n' << book->getYear() << '\n';
        }



        file.close();
}

void TableModel::removeBook(int row)
{

    beginRemoveRows(QModelIndex(), row, row);
    bookList.removeAt(row);
    endRemoveRows();

}

void TableModel::addBook(Book *newBook)
{
    beginInsertRows(QModelIndex(), bookList.size(), bookList.size());
    bookList.append(newBook);
    endInsertRows();



}

void TableModel::changeBook(int row, QString title, QString author, int year)
{
       beginInsertRows(QModelIndex(), row, row);
       bookList[row]->setYear(year);
       bookList[row]->setTitle(title);
       bookList[row]->setAuthor(author);

}

Book *TableModel::getBook(int index)
{
    return bookList[index];
}


