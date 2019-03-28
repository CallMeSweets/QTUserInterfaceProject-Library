#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Library[*]");

    tableModel = new TableModel(this);
    tableModel->loadFromFile();

    proxyModel = new ProxyModel();
    proxyModel->setDynamicSortFilter(true);
    settingsProxyModel();

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


//    editWindow.setMainWindow(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deleteButton_clicked()
{

    QModelIndexList selectedList = ui->tableView->selectionModel()->selectedRows();
//    for( int i=selectedList.count()-1; i > 0; --i){
//        tableModel->removeBook(selectedList.at(i).row());
//    }
    for (auto iter = selectedList.rbegin(); iter != selectedList.rend(); ++iter){
        tableModel->removeBook(iter->row());
    }
    setWindowModified(true);

}


void MainWindow::on_addBookButton_clicked()
{
    MyEditWindow editWindow;
editWindow.setMainWindow(this);
    editWindow.setWindowFlag(Qt::WindowStaysOnTopHint);
    editWindow.setWindowTitle("New Book Window");
    editWindow.setDecision(true);
    editWindow.exec();
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
MyEditWindow editWindow;
editWindow.setMainWindow(this);
    Book *tempBook = this->tableModel->getBook(index.row());
    editWindow.setTitleAuthorYear(tempBook->getTitle(), tempBook->getAuthor(), tempBook->getYear());

    editWindow.setWindowFlag(Qt::WindowStaysOnTopHint);
    editWindow.setWindowTitle("Edit Book Window");
    editWindow.setDecision(false);
    editWindow.exec();

}

void MainWindow::changeBook(int row, QString title, QString author, int year)
{
    tableModel->changeBook(row, title, author, year);
}

int MainWindow::getSelectedRow()
{
    QModelIndexList selectedList = ui->tableView->selectionModel()->selectedRows();
    return selectedList.at(selectedList.size()-1).row();
}

void MainWindow::saveToFile()
{
    tableModel->saveToFile();
}

void MainWindow::settingsProxyModel()
{
    proxyModel->setSourceModel(tableModel);

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (!isWindowModified()) return;
    QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Decision", "Wanna save changes?",
                                   QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
     if (reply == QMessageBox::Cancel) {
         event->ignore();
         return;
     }
     if (reply == QMessageBox::Yes) {
       saveToFile();
     }
//     QApplication::quit();
}

void MainWindow::on_clearButton_clicked()
{
    ui->titleLine->clear();
    ui->authorLine->clear();
    ui->yearSpin->setValue(0);
    proxyModel->setAuthor("");
}

void MainWindow::on_titleLine_textChanged(const QString &arg1)
{
    proxyModel->setTitle(arg1);
}

void MainWindow::on_authorLine_textChanged(const QString &arg1)
{
    proxyModel->setAuthor(arg1);
}

void MainWindow::on_yearSpin_valueChanged(int arg1)
{
    proxyModel->setYear(QString::number(arg1));
}


