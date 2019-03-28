#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book();
    Book(QString title, QString author, int year);

private:
    QString title;
    QString author;
    int year;

public:



    QString getTitle() const;
    void setTitle(const QString &value);
    QString getAuthor() const;
    void setAuthor(const QString &value);
    int getYear() const;
    void setYear(int value);
};

#endif // BOOK_H
