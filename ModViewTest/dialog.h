#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class QStringListModel;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_addButton_clicked();

    void on_insertButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::Dialog *ui;
    QStringListModel *model;
};

#endif // DIALOG_H
