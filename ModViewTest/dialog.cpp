#include "dialog.h"
#include "ui_dialog.h"
#include <QStringListModel>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    QStringList list;
    list << "thing1" << "thing2" << "thing3";

    model->setStringList(list);

    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    ui->listView->setEditTriggers(QAbstractItemView::AnyKeyPressed
                                  | QAbstractItemView ::DoubleClicked);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_addButton_clicked()
{
    int row = model->rowCount();
    model->insertRows(row,1);

    QModelIndex index = model->index(row);
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void Dialog::on_insertButton_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->insertRows(row,1);

    QModelIndex index = model->index(row);
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
}

void Dialog::on_deleteButton_clicked()
{
    model->removeRows(ui->listView->currentIndex().row(), 1);
}
