#ifndef RESULT_H
#define RESULT_H
#include <QDialog>
#include<QtCore>
#include<QtGui>
#include <QGraphicsScene>
#include<QGraphicsItem>
#include <QDialog>
#include <QDialog>

namespace Ui {
class result;
}

class result : public QDialog
{
    Q_OBJECT

public:
    explicit result(QWidget *parent = nullptr);
    ~result();

private slots:
    void on_push_clicked();

    void on_deallocate_clicked();

private:
    Ui::result *ui;
    QGraphicsScene * scene ;
    QGraphicsRectItem *rect;
};

#endif // RESULT_H
