#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <iostream>
#include <string.h>
#include <math.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton1,SIGNAL(clicked(bool)),this,SLOT(first()));
    connect(ui->pushButton2,SIGNAL(clicked(bool)),this,SLOT(stack()));
    connect(ui->pushButton3,SIGNAL(clicked(bool)),this,SLOT(delstack()));
    connect(ui->pushButton4,SIGNAL(clicked(bool)),this,SLOT(queue()));
    connect(ui->pushButton5,SIGNAL(clicked(bool)),this,SLOT(delqueue()));


}
void Widget::first()
{
    //Стек//
    List *temp = new List;                              //Выделяем память для нового элемента
    QString str1=ui->lineEdit1->text();
    temp->x =str1.toInt();                                        //Записываем в поле x принимаемый в функцию элемент x
    temp->Next = Head;                          //Указываем, что следующий элемент это предыдущий
    Head = temp;                                //Сдвигаем голову на позицию вперед

    //Очередь//
    List1 *temp1 = new List1;              //Выделение памяти для нового звена списка
    QString str4=ui->lineEdit1->text();
    temp1->y =str4.toInt();               //Временное запоминание принятого параметра y
    temp1->Next1 = NULL;                  //Указание, что следующее звено новосозданной структуры пока пустое
    if (Head1 != NULL)                   //Если список не пуст
    {
        Tail1->Next1 = temp1;              //Указание, что следующее звено списка это новосозданная структура
        Tail1 = temp1;
    }     else Head1 = Tail1 = temp1;      //Если список не пуст, добавление первого элемента
    ui->lineEdit1->clear();
}
void Widget::stack()
{
    List *temp = Head;                          //Объявляем указатель и Указываем ему, что его позиция в голове стека
    if(temp == NULL)                                    //проверка на наличие
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Пустой стек");
        msgBox.exec();
    }
    else
    {
        QString str2,str3;
        str3.setNum(temp->x);
        temp = temp->Next;
        //с помощью цикла проходим по всему стеку
        while (temp != NULL)                                //выходим при встрече с пустым полем
        {
            str2.setNum(temp->x);
            str3=str3+" "+str2;
            temp = temp->Next;                              //Переходим к следующему элементу
        }
        ui->lineEdit2->setText(str3);                           //Выводим на экран элемент стека
    }

}
void Widget::queue()
{
    List1 *temp1 = Head1;                  //Временный указатель на начало списка
    if(temp1 == NULL)                                    //проверка на наличие
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Пустая очередь");
        msgBox.exec();
    }
    else
    {
        QString str5,str6;
        str6.setNum(temp1->y);
        temp1 = temp1->Next1;
        while (temp1 != NULL)               //Пока в списке что-то встречается
        {
            str5.setNum(temp1->y);
            str6=str6+" "+str5;
            temp1 = temp1->Next1;             //Сдвигаем указатель на начало на адрес следующего элемента
        }
        ui->lineEdit3->setText(str6); //Выводим значения из списка на экран
    }
}
void Widget::delqueue()
{
    ui->lineEdit3->clear();
    if(Head1 == NULL)                                    //проверка на наличие
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Пустая очередь");
        msgBox.exec();
    }
    else
       {
           List1 *temp = Head1;              //Обращаемся к началу списка с помощью вспомогательного указателя
           Head1 = Head1->Next1;              //Сдвиг начала списка
           delete temp;                    //Освобождение памяти от предыдущего звена списка
       }
}
void Widget::delstack()
{
    ui->lineEdit2->clear();
    if(Head == NULL)                                    //проверка на наличие
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Пустой стек");
        msgBox.exec();
    }
    else
    {
        List *temp = Head->Next;                    //Временная переменная для хранения адреса следующего элемента
        delete Head;                                //Освобождаем адрес обозначающий начало
        Head = temp;                                //Меняем адрес на следующий

    }

}
Widget::~Widget()
{
    delete ui;
}



