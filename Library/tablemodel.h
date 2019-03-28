#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QTextStream>
#include <QMessageBox>
#include <QFile>
#include <QList>
#include "book.h"

const QString FILE_PATH = "D:\\QT Projects\\FirstProject\\SebastianGrzelakEGUIFinal\\data.txt";

class TableModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;


    //My Methods
public:
    void loadFromFile();
    void saveToFile();
    void removeBook(int row);
    void addBook(Book *newBook);
    void changeBook(int row, QString title, QString author, int year);
    Book *getBook(int index);

private:
    QList<Book*> bookList;

signals:
    void editCompleted(const QString &);





};

#endif // TABLEMODEL_H
