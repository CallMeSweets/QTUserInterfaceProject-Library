#ifndef BOOKEDITION_H
#define BOOKEDITION_H

#include <QDialog>
#include "book.h"


class MainWindow;

namespace Ui {
class BookEdition;
}

class BookEdition : public QDialog
{
    Q_OBJECT

private:
    explicit BookEdition(QWidget *parent = nullptr);
public:
    ~BookEdition();
    static BookEdition* getBookEditionWindow();
    void setMainWindow(MainWindow *mainWindow){this->mainWindow = mainWindow;}
    void setDecision(bool value);


private slots:
    void on_addBookButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::BookEdition *ui;
    MainWindow *mainWindow;
    bool decision = false;

};

#endif // BOOKEDITION_H
