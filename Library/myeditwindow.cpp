#include "myeditwindow.h"
#include "mainwindow.h"

MyEditWindow::MyEditWindow(QWidget *parent) : QDialog(parent)
{
    this->buildLayout();
    this->addActionsToButtons();
}

void MyEditWindow::addBook()
{
    QString title = titleEdit.text();
    QString author = authorEdit.text();
    int year = yearSpin.value();

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Warning window!");
    msgBox.setWindowFlag(Qt::WindowStaysOnTopHint);

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

        titleEdit.clear();
        authorEdit.clear();
        yearSpin.setValue(0);
        this->hide();
    }
}

void MyEditWindow::setMainWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

void MyEditWindow::buildLayout()
{
    QLabel *labelTitle = new QLabel("Title: ");
    QLabel *labelAuthor = new QLabel("Author: ");
    QLabel *labelYear = new QLabel("Year: ");

    clearButton.setText("CLEAR");
    cancelButton.setText("CANCEL");
    okButton.setText("OK");

    yearSpin.setRange(0, 2020);
    yearSpin.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    yearSpin.setFixedWidth(50);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addItem(new QSpacerItem(this->size().width() / 8, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    buttonLayout->addWidget(&okButton);
    buttonLayout->addWidget(&clearButton);
    buttonLayout->addWidget(&cancelButton);
    buttonLayout->addItem(new QSpacerItem(this->size().width() / 8, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));


    QFormLayout *layout = new QFormLayout();
    layout->setSpacing(15);
    layout->setMargin(10);
    layout->addRow(labelTitle, &titleEdit);
    layout->addRow(labelAuthor, &authorEdit);
    layout->addRow(labelYear, &yearSpin);
    layout->addRow(buttonLayout);

    this->setLayout(layout);
}

void MyEditWindow::addActionsToButtons()
{
    connect(&okButton, SIGNAL(clicked()), this, SLOT(addBook()));
    connect(&cancelButton, SIGNAL(clicked()), this, SLOT(hide()));
    connect(&clearButton, SIGNAL(clicked()), this, SLOT(clearEditLabels()));
}

void MyEditWindow::setTitleAuthorYear(QString title, QString author, int year)
{
    titleEdit.setText(title);
    authorEdit.setText(author);
    yearSpin.setValue(year);
}

void MyEditWindow::clearEditLabels()
{
    titleEdit.clear();
    authorEdit.clear();
    yearSpin.setValue(0);
}

void MyEditWindow::setDecision(bool value)
{
    decision = value;
}


