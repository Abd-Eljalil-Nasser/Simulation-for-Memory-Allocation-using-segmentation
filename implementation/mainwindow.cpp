#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<fillholes.h>
#include<hole.h>
#include<result.h>
#include"QPixmap"
#include<QButtonGroup>
extern int MemorySize;
extern int NumberOfHoles;
extern hole * holes;
extern int flag;
extern std::list <hole> memory;
extern QString method;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    QFont Times ("Times",20,QFont::Bold);
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    ui->memorysize->setFont(Times);
    ui->numberofholes->setFont(Times);
    ui->label_2->setFont(Times);
    ui->memorysize->setStyleSheet(("color:rgb(255, 255, 255)"));
    ui->numberofholes->setStyleSheet(("color:rgb(255, 255, 255)"));
    ui->label_2->setStyleSheet(("color:rgb(255, 255, 255)"));
   QPixmap pix(":/resource/image/memory.jpg");
   ui->label->setScaledContents(true);
   ui->label->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submit_clicked()
{
   QString temp = ui->inputsize->text();
   MemorySize = temp.toInt();
   if (MemorySize <= 0)
           {
           QMessageBox  message;
           message.setMinimumSize(1000,1000);
           message.setWindowTitle("Error");
           message.setText("something happened");
           message.setInformativeText("enter vaild memory size");
           message.setIcon(QMessageBox::Critical);
           message.setStandardButtons(QMessageBox::Ok);
           message.setDefaultButton(QMessageBox::Ok);
           ui->inputsize->clear();
           int a=message.exec();
           }
   else {
       temp = ui->number->text();
       NumberOfHoles = temp.toInt();
       if (NumberOfHoles <= 0)
               {
               QMessageBox  message;
               message.setMinimumSize(1000,1000);
               message.setWindowTitle("Error");
               message.setText("something happened");
               message.setInformativeText("enter vaild number of holes");
               message.setIcon(QMessageBox::Critical);
               message.setStandardButtons(QMessageBox::Ok);
               message.setDefaultButton(QMessageBox::Ok);
               ui->number->clear();
               int a=message.exec();
               }
       else {

           flag =0;
           FillHoles x;
           int a=x.exec();
           if (flag==1)
           {
              /* if (ui->firstfit->isChecked())
               {
                   method = "firstfit";
               }
               else if (ui->bestfit->isChecked())
               {
                   method = "bestfit";
               }
               else {
                   method = "WorestFit";
               }
               */
               result y(this);
               y.exec();
           }
           }
        }

}
