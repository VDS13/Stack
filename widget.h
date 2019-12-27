#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTextCodec>
#include <QGroupBox>

namespace Ui {
class Widget;
}
struct List                                             //структура стек
{
    int x;                                              //информационный элемент
    List *Next;                                   // указатель на следующий элемент
};
struct List1                                            //структура очередь(ее сделаю с использованием массива)
{
    int y;                           //инфо данные структуры
    List1 *Next1;                      //Указатель не следующее звено
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    List *Head;
    List1 *Head1, *Tail1;
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    Ui::Widget *ui;
public slots:
    void first();
    void stack();
    void queue();
    void delstack();
    void delqueue();
};

#endif // WIDGET_H
