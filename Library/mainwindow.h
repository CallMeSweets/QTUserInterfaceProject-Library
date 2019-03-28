#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablemodel.h"
#include <QSortFilterProxyModel>
#include "proxymodel.h"
#include "myeditwindow.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_deleteButton_clicked();
    void on_addBookButton_clicked();

    // my public methods
    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_clearButton_clicked();

    void on_titleLine_textChanged(const QString &arg1);

    void on_authorLine_textChanged(const QString &arg1);

    void on_yearSpin_valueChanged(int arg1);





public:
    void addNewBook(Book *newBook){tableModel->addBook(newBook);}
    void changeBook(int row, QString title, QString author, int year);
    int getSelectedRow();
    void saveToFile();
    void settingsProxyModel();

private:
    Ui::MainWindow *ui;
    TableModel *tableModel;
    ProxyModel *proxyModel;
//    MyEditWindow editWindow;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
