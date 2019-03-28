#ifndef MYEDITWINDOW_H
#define MYEDITWINDOW_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QFont>

class MainWindow;

class MyEditWindow : public QDialog
{
    Q_OBJECT
public:
    explicit MyEditWindow(QWidget *parent = nullptr);
    void setMainWindow(MainWindow *mainWindow);
    void setDecision(bool value);
    void setTitleAuthorYear(QString title, QString author, int year);

signals:

private slots:
    void addBook();
    void clearEditLabels();

private:
    QLineEdit titleEdit;
    QLineEdit authorEdit;
    QSpinBox yearSpin;
    QPushButton okButton;
    QPushButton cancelButton;
    QPushButton clearButton;

    MainWindow *mainWindow;
    bool decision = false;

    // methods
private:
    void buildLayout();
    void addActionsToButtons();


};

#endif // MYEDITWINDOW_H
