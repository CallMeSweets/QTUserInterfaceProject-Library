#include "bookedition.h"
#include "ui_bookedition.h"
#include "mainwindow.h"

BookEdition::BookEdition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BookEdition)
{

    ui->setupUi(this);
}

BookEdition::~BookEdition()
{
    delete ui;
}

BookEdition* BookEdition::getBookEditionWindow()
{
    static BookEdition *bookEditionWindow = new BookEdition();
    return bookEditionWindow;
}

void BookEdition::on_addBookButton_clicked()
{
    QString title = ui->titleEdit->text();
    QString author = ui->authorEdit->text();
    int year = ui->yearSpin->value();

    QMessageBox msgBox;
    if(title == ""){
        msgBox.setText("Set Title");
        msgBox.exec();
    }else if(author == ""){
        msgBox.setText("Set Author");
        msgBox.exec();
    }else if(year == 0){
        msgBox.setText("Set Year");
        msgBox.exec();
    }else{
        if(decision == false)
            mainWindow->changeBook(mainWindow->getSelectedRow(),title, author, year);
        else
            mainWindow->addNewBook(new Book(title, author, year));

        ui->titleEdit->clear();
        ui->authorEdit->clear();
        ui->yearSpin->setValue(0);
        this->close();
    }


}

void BookEdition::on_cancelButton_clicked()
{
    this->close();
}

void BookEdition::setDecision(bool value)
{
    decision = value;
}


