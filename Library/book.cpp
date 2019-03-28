#include "book.h"

Book::Book()
{

}

Book::Book(QString title, QString author, int year)
{
    this->title = title;
    this->author = author;
    this->year = year;
}

int Book::getYear() const
{
    return year;
}

void Book::setYear(int value)
{
    year = value;
}

QString Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(const QString &value)
{
    author = value;
}

QString Book::getTitle() const
{
    return title;
}

void Book::setTitle(const QString &value)
{
    title = value;
}
