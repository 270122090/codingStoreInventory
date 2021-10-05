#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additemdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionAddItem, &QAction::triggered, this, &MainWindow:: handlemenuitemnew);
    connect(ui->RemoveBTN, &QPushButton::clicked, this, &MainWindow:: removeselected);
}

MainWindow::~MainWindow()
{
    delete ui;


}

//MlistWidget // this has no clicking involve

//actionAddItem // this is the menu bar on top left corner

 void MainWindow::handlemenuitemnew()
 {
    Item* newItem = nullptr;
    AddItemDialog addItemDialog(newItem, nullptr);
    addItemDialog.setModal(true);
    addItemDialog.exec();

    if(newItem != nullptr)
    {
        productlist.push_back(newItem);
        ui->MlistWidget->addItem(newItem->getitem());

    }
 }

    void MainWindow::removeselected()
    {
        int index = ui->MlistWidget->currentRow();
        if (index >=0)
        {
            // remove from vector
            Item* theItem = productlist.at(index);
            delete theItem;
            productlist.removeAt(index);

            //remove from listwidget

            delete ui->MlistWidget->currentItem();

        }
    }




 //RemoveBTN
