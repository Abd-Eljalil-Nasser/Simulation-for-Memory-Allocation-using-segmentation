#include "result.h"
#include "ui_result.h"
#include<QMessageBox>
#include<hole.h>
#include<QMessageBox>
#include<addprocess.h>
#include<QButtonGroup>
extern int MemorySize;
extern int NumberOfHoles;
extern int flag;
extern std::list <hole> memory;
extern int NumberOfSegments;
extern std::list<QString> combox;
extern QString method;
extern int processNumber;
extern int flag2;
result::result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->draw->setScene(scene);
    ui->comboBox->addItem("None");
    QButtonGroup * buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->firstfit);
    buttonGroup->addButton(ui->bestfit);
    buttonGroup->addButton(ui->WorestFit);
    buttonGroup->setExclusive(true);
    ui->firstfit->setChecked(true);
    QFont Times1 ("Times",15,QFont::Bold);
    ui->firstfit->setFont(Times1);
    ui->bestfit->setFont(Times1);
    ui->WorestFit->setFont(Times1);
    if (combox.size()!=0)
    {
        for (std::list<QString>::iterator it=combox.begin();it != combox.end() ;it++)
        {
            ui->comboBox->addItem(*it);
        }
    }
    combox.clear();
    QBrush greenBrush (Qt::green);
    QBrush yellowBrush (Qt::yellow);
    QColor orange(255,165,0);
    QBrush orangeBursh(orange);
    QPen blackpen (Qt::black);
    blackpen.setWidth(2);
    int start_point =0;
    int count =1;
    int temp = MemorySize;
    while (temp/10){
            temp = temp/10;
            count++;
        }
        int size = memory.size();
        for (std::list<hole > ::iterator it = memory.begin();it != memory.end();it++)
                   {
                  if ((*it).get_flag()==-1)
                  {
                   rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,greenBrush);
                   QString temp_str= (*it).get_name();
                   QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
                   txtitem1->setPos(QPointF(80,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
                   QFont Times ("Times",10,QFont::Bold);
                   txtitem1->setFont(Times);
                   scene->addItem(txtitem1);
                   temp_str=QString::number((*it).get_StartingAddress());
                   QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
                   txtitem2->setPos(QPointF(20-17*count,start_point-20));
                   txtitem2->setFont(Times);
                   scene->addItem(txtitem2);
                   start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
                  }
                  else if ((*it).get_flag() == 0)
                  {
                      rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,yellowBrush);
                      QString temp_str=(*it).get_name();
                      QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
                      txtitem1->setPos(QPointF(110,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
                      QFont Times ("Times",10,QFont::Bold);
                      txtitem1->setFont(Times);
                      scene->addItem(txtitem1);
                      temp_str=QString::number((*it).get_StartingAddress());
                      QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
                      txtitem2->setPos(QPointF(20-17*count,start_point-20));
                      txtitem2->setFont(Times);
                      scene->addItem(txtitem2);
                      start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
                  }
                  else
                  {
                      rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,orangeBursh);
                      QString temp_str = (*it).get_name();
                      QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
                      txtitem1->setPos(QPointF(110,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
                      QFont Times ("Times",10,QFont::Bold);
                      txtitem1->setFont(Times);
                      scene->addItem(txtitem1);
                      temp_str=QString::number((*it).get_StartingAddress());
                      QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
                      txtitem2->setPos(QPointF(20-17*count,start_point-20));
                      txtitem2->setFont(Times);
                      scene->addItem(txtitem2);
                      start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
                  }
                  if (size == 1)
                  {

                      QString temp_str = QString::number((*it).get_endAdress());
                      QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
                      txtitem1->setPos(QPointF(20-17*count,(*it).get_endAdress()-20));
                      QFont Times ("Times",10,QFont::Bold);
                      txtitem1->setFont(Times);
                      scene->addItem(txtitem1);
                  }
                  size --;
       }
       }


result::~result()
{
    scene->clear();
    memory.clear();
    delete ui;

}



void result::on_push_clicked()
{
    QString temp = ui->number->text();
    NumberOfSegments = temp.toInt();
    if (NumberOfSegments <= 0)
                {
                QMessageBox  message;
                message.setMinimumSize(1000,1000);
                message.setWindowTitle("Error");
                message.setText("something happened");
                message.setInformativeText("enter vaild number of segmants");
                message.setIcon(QMessageBox::Critical);
                message.setStandardButtons(QMessageBox::Ok);
                message.setDefaultButton(QMessageBox::Ok);
                ui->number->clear();
                message.exec();
                }
    else
    {
        if (ui->firstfit->isChecked())
           {
             method = "firstfit";
           }
         else if (ui->bestfit->isChecked())
           {
             method = "bestfit";
           }
         else
           {
          method = "WorestFit";
           }
     flag2=0;
    addprocess y (this);
    y.exec();
    if (flag2==1){
    ui->comboBox->addItem("P("+QString::number(processNumber)+")");
    scene->clear();
    QBrush greenBrush (Qt::green);
    QBrush yellowBrush (Qt::yellow);
    QColor orange(255,165,0);
    QBrush orangeBursh(orange);
    QPen blackpen (Qt::black);
    blackpen.setWidth(2);
    int start_point =0;
    int count =1;
    int temp = MemorySize;
    while (temp/10){
            temp = temp/10;
            count++;
        }
    int size = memory.size();
    for (std::list<hole > ::iterator it = memory.begin();it != memory.end();it++)
               {
              if ((*it).get_flag()==-1)
              {
               rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,greenBrush);
               QString temp_str= (*it).get_name();
               QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
               txtitem1->setPos(QPointF(80,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
               QFont Times ("Times",10,QFont::Bold);
               txtitem1->setFont(Times);
               scene->addItem(txtitem1);
               temp_str=QString::number((*it).get_StartingAddress());
               QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
               txtitem2->setPos(QPointF(20-17*count,start_point-20));
               txtitem2->setFont(Times);
               scene->addItem(txtitem2);
               start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
              }
              else if ((*it).get_flag() == 0)
              {
                  rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,yellowBrush);
                  QString temp_str=(*it).get_name();
                  QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
                  txtitem1->setPos(QPointF(110,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
                  QFont Times ("Times",10,QFont::Bold);
                  txtitem1->setFont(Times);
                  scene->addItem(txtitem1);
                  temp_str=QString::number((*it).get_StartingAddress());
                  QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
                  txtitem2->setPos(QPointF(20-17*count,start_point-20));
                  txtitem2->setFont(Times);
                  scene->addItem(txtitem2);
                  start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
              }
              else
              {
                  rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,orangeBursh);
                  QString temp_str =(*it).get_name();
                  QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
                  txtitem1->setPos(QPointF(110,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
                  QFont Times ("Times",10,QFont::Bold);
                  txtitem1->setFont(Times);
                  scene->addItem(txtitem1);
                  temp_str=QString::number((*it).get_StartingAddress());
                  QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
                  txtitem2->setPos(QPointF(20-17*count,start_point-20));
                  txtitem2->setFont(Times);
                  scene->addItem(txtitem2);
                  start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
              }
              if (size == 1)
              {

                  QString temp_str = QString::number((*it).get_endAdress());
                  QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
                  txtitem1->setPos(QPointF(20-17*count,(*it).get_endAdress()-20));
                  QFont Times ("Times",10,QFont::Bold);
                  txtitem1->setFont(Times);
                  scene->addItem(txtitem1);
              }
              size --;

   }
    }

}
}

void result::on_deallocate_clicked()
{
ui->push->hide();
if (ui->comboBox->currentText()== "None")
{
    QMessageBox  message;
    message.setMinimumSize(1000,1000);
    message.setWindowTitle("Error");
    message.setText("something happened");
    message.setInformativeText("enter vaild process to be deallocated");
    message.setIcon(QMessageBox::Critical);
    message.setStandardButtons(QMessageBox::Ok);
    message.setDefaultButton(QMessageBox::Ok);
    message.exec();
    ui->push->show();
}
else {

 QString temp =  ui->comboBox->currentText();
 ui->comboBox->removeItem(ui->comboBox->currentIndex());
  QStringRef sub(&temp,0,2);
 int num=0;
 if (sub !="P(")
 {
  QStringRef subString(&temp,13,temp.size()-14);
     num = subString.toInt();
     for (std::list<hole > ::iterator it = memory.begin();it != memory.end();it++)
     {

         if (it->get_flag()==-1)
         {
             QString temp = it->get_name();
             QStringRef subtemp(&temp,13,temp.size()-14);
             int tempcomparison = subtemp.toInt();
             if (tempcomparison == num)
             {
                 it->set_flag(0);
                 it->set_name("empty");
                 break;
             }
         }
     }
  }
  else
  {
   QStringRef subtemp(&temp,2,temp.size()-3);
   int temptemp = subtemp.toInt();
   for (std::list<hole>::iterator it = memory.begin();it != memory.end();it++)
   {
       if(it->get_flag()==temptemp)
       {
           it->set_flag(0);
           it->set_name("empty");
       }
   }
   //int siztemptemp = memory.size();
   for (std::list<hole> ::iterator it = memory.begin();it != memory.end();it++)
   {
       std::list<hole > ::iterator it1 = it;
       int flagtemp = -1;
       int tempid = it->get_ID();
       //int startadd = it->get_endAdress();
       int endadd = it->get_endAdress();
       if(it->get_flag()==0)
       {
           if (it ==  memory.end())
           {
               break;
           }

           it++;
           flagtemp=0;
          while ((it)->get_ID()==tempid && it->get_flag()==0 && it != memory.end()&& it->get_StartingAddress()==endadd)
          {
              std::list<hole > ::iterator temp = it;
              endadd = temp->get_endAdress();
              it++;
              memory.erase(temp);

          }
       }
       if (flagtemp == 0)
       {
           it1->set_endAdress(endadd);
       }
       if (flagtemp==0)
       {
           it--;
       }

   }

  }

 }
scene->clear();
QBrush greenBrush (Qt::green);
QBrush yellowBrush (Qt::yellow);
QColor orange(255,165,0);
QBrush orangeBursh(orange);
QPen blackpen (Qt::black);
blackpen.setWidth(2);
int start_point =0;
int count =1;
int temp = MemorySize;
while (temp/10){
        temp = temp/10;
        count++;
    }
int size = memory.size();
for (std::list<hole > ::iterator it = memory.begin();it != memory.end();it++)
           {
          if ((*it).get_flag()==-1)
          {
           rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,greenBrush);
           QString temp_str= (*it).get_name();
           QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
           txtitem1->setPos(QPointF(80,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
           QFont Times ("Times",10,QFont::Bold);
           txtitem1->setFont(Times);
           scene->addItem(txtitem1);
           temp_str=QString::number((*it).get_StartingAddress());
           QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
           txtitem2->setPos(QPointF(20-17*count,start_point-20));
           txtitem2->setFont(Times);
           scene->addItem(txtitem2);
           start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
          }
          else if ((*it).get_flag() == 0)
          {
              rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,yellowBrush);
              QString temp_str=(*it).get_name();
              QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
              txtitem1->setPos(QPointF(110,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
              QFont Times ("Times",10,QFont::Bold);
              txtitem1->setFont(Times);
              scene->addItem(txtitem1);
              temp_str=QString::number((*it).get_StartingAddress());
              QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
              txtitem2->setPos(QPointF(20-17*count,start_point-20));
              txtitem2->setFont(Times);
              scene->addItem(txtitem2);
              start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
          }
          else
          {
              rect=scene->addRect(20,start_point,250,((*it).get_endAdress()-(*it).get_StartingAddress()),blackpen,orangeBursh);
              QString temp_str =(*it).get_name();
              QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
              txtitem1->setPos(QPointF(110,(start_point+((*it).get_endAdress()-(*it).get_StartingAddress())/2)-15));
              QFont Times ("Times",10,QFont::Bold);
              txtitem1->setFont(Times);
              scene->addItem(txtitem1);
              temp_str=QString::number((*it).get_StartingAddress());
              QGraphicsTextItem *txtitem2= new QGraphicsTextItem(temp_str);
              txtitem2->setPos(QPointF(20-17*count,start_point-20));
              txtitem2->setFont(Times);
              scene->addItem(txtitem2);
              start_point = start_point+((*it).get_endAdress()-(*it).get_StartingAddress());
          }
          if (size == 1)
          {

              QString temp_str = QString::number((*it).get_endAdress());
              QGraphicsTextItem *txtitem1 = new QGraphicsTextItem(temp_str);
              txtitem1->setPos(QPointF(20-17*count,(*it).get_endAdress()-20));
              QFont Times ("Times",10,QFont::Bold);
              txtitem1->setFont(Times);
              scene->addItem(txtitem1);
          }
          size --;

}
ui->push->show();
}
