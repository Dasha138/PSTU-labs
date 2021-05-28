#include "comi.h"
#include "ui_comi.h"
#include <cmath>
#include <QMessageBox>

bool *prev, notall=0;
int arr[9][9], coun, increm, temp=0, str_min[9], clm_min[9],
    optimate[9][2], mid_arg, mid_func, way[9];
double grad=360;

class Node
{
public:
    int x,y;
};

Node *node;

Comi::Comi(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Comi)
{
    ui->setupUi(this);
    ui->build->hide();
    ui->run->hide();
    Close();
}

Comi::~Comi()
{
    delete ui;
}

void Comi::on_create_clicked()//данный слот отвечает за нажатие кнопки "Создать"
{
    ui->run->  hide();
    ui->build->show();
    Close();
    Print();
    node = new Node[coun];
    mid_arg=800;
    mid_func=350;
    temp=1;
    this->repaint();
}

void Comi::on_build_clicked()//слот отвечающий за нажатие кнопки "Построение"
{
    ui->run->   hide();
    QString searcher,buffer;
    for (int i=0; i<coun; i++)
    {
        for (int j=0; j<coun; j++)
        {
            if(i != j)
            {
                searcher="u"+QString::number(i+1) + QString::number(j+1);
                buffer=this->findChild<QLineEdit*>(searcher)->text();
                if (!buffer.length())
                    buffer=QString::number(INT32_MAX);
                arr[i][j]=buffer.toInt();
            }
            if(i == j)
                arr[i][j] = -1;
        }
    }
    ui->run->show();
    temp=2;
    this->repaint();
}

void Comi::on_run_clicked()//слот отвечающий за запуск программы
{
    QString dialog, mistake;
    QString searcher,buffer;

    for(int i = 0; i < coun; i++)
    {
        Search_min();
        Search_null(i);
    }

    for (int i=0; i<coun; i++)
    {
        for (int j=0; j<coun; j++)
        {
            if(i != j)
            {
                searcher="u"+QString::number(i+1) + QString::number(j+1);
                buffer=this->findChild<QLineEdit*>(searcher)->text();
                if (!buffer.length())
                    buffer=QString::number(INT32_MAX);
                arr[i][j]=buffer.toInt();
            }
            else
                arr[i][j] = -1;
        }
    }
//алгоритм отвечающий за нахождение оптимального пути
    dialog += "\nОптимальный путь: " + QString::number(optimate[0][0]+1) + " -> " + QString::number(optimate[0][1]+1);
    int point = optimate[0][1], summ = arr[optimate[0][0]][optimate[0][1]];

    way[0] = optimate[0][0];
    way[1] = optimate[0][1];

    int z = 1;

    while(z < coun)
    {
        for(int i = 1; i < coun; i++)
        {
            if(optimate[i][0]==point && optimate[i][0]!=optimate[i][1])
            {
                way[z+1] = point = optimate[i][1];
                dialog += " -> " + QString::number(optimate[i][1]+1);
                summ += arr[optimate[i][0]][optimate[i][1]];
                optimate[i][0] = -1;
                optimate[i][1] = -1;
                break;
            }
        }
        z++;
    }
    temp = 3;
    this->repaint();
    dialog += "\nПродолжительность: " +QString::number(summ);
    QMessageBox::information(this,"Результат",dialog);
}

void Comi::Search_null(int num)//слот отвечающий за поиск нулевых элементов
{
    int min_in_str = INT32_MAX;
    int min_in_clm = INT32_MAX;
    int max_rank_null = 0;
    int max_i=100, max_j=100;

    for (int i=0;i<coun;i++)
    {
        for(int j=0;j<coun;j++)
        {
            if(arr[i][j] == 0 && i!=j)
            {
                for (int k=0;k<coun;k++)
                {
                    if(arr[k][j]>-1 && arr[k][j] < min_in_clm && k != j && k!=i)
                        min_in_clm = arr[k][j];
                    if(arr[i][k]>-1 && arr[i][k] < min_in_str && i != k && k!=j)
                        min_in_str = arr[i][k];
                }
                if(min_in_str > 1000)
                    min_in_str = 0;
                if(min_in_clm > 1000)
                    min_in_clm = 0;
                if(min_in_str>-1 && min_in_clm>-1 && i!=j && max_rank_null <= (min_in_str + min_in_clm))
                {
                    max_rank_null = min_in_str + min_in_clm;
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }

    optimate[num][0] = max_i;
    optimate[num][1] = max_j;

    for(int z=0;z<coun;z++)
    {
        arr[max_i][z] = -1;
        arr[z][max_j] = -1;
    }
    arr[max_j][max_i] = -1;
};

void Comi::Search_min()
{
    for(int i=0; i<coun; i++)
    {
        str_min[i] = INT32_MAX;
        clm_min[i] = INT32_MAX;
    }

    for (int i=0; i<coun; i++)
    {
        for (int j=0; j<coun; j++)
            if(i != j && arr[i][j]>-1 && arr[i][j] < str_min[i])
                str_min[i] = arr[i][j];
        for (int j=0; j<coun; j++)
            if(i != j && str_min[i] > 0 && str_min[i]<1000)
                arr[i][j] -= str_min[i];
    }
    for (int j=0; j<coun;j++)
    {
        for (int i=0;i<coun;i++)
            if(i != j && arr[i][j]>-1 && arr[i][j] < clm_min[j])
                clm_min[j] = arr[i][j];
        for (int i=0; i<coun; i++)
            if(i != j && clm_min[j] > 0 && clm_min[j]<1000)
                arr[i][j] -= clm_min[j];
    }
}

void Comi::Close()
{
    QString str;
    for (int i=1;i<10;i++)
    {
        str="clm" + QString::number(i);
        this->findChild<QWidget*>(str)->hide();
    }
    for (int i=1;i<10;i++)
    {
        str="stg" + QString::number(i);
        this->findChild<QWidget*>(str)->hide();

        str="z" + QString::number(i);
        this->findChild<QWidget*>(str)->hide();

        for (int j=i+1;j<10;j++)
        {
            str="u" + QString::number(i) + QString::number(j);
            this->findChild<QWidget*>(str)->hide();
        }
        for (int j=1;j<i;j++)
        {
            str="u" + QString::number(i) + QString::number(j);
            this->findChild<QWidget*>(str)->hide();
        }
    }
}

void Comi::Print()
{
    QString str;

    for (int i=1;i<coun+1;i++)
    {
        str="clm" + QString::number(i);
        this->findChild<QWidget*>(str)->show();
    }

    for (int i=1;i<coun+1;i++)
    {
        str="stg" + QString::number(i);
        this->findChild<QWidget*>(str)->show();
        str="z" + QString::number(i);
        this->findChild<QWidget*>(str)->show();
        for (int j=i+1; j<coun+1; j++)
        {
            str="u" + QString::number(i) + QString::number(j);
            this->findChild<QWidget*>(str)->show();
        }
        for (int j=1;j<i;j++)
        {
            str="u" + QString::number(i) + QString::number(j);
            this->findChild<QWidget*>(str)->show();
        }
    }
}

void Comi::paintEvent(QPaintEvent *)
{
    if (temp){
        int otstup;
        grad /= coun;
        increm=grad;
        grad=0;
        QPainter paint(this);
        QPen pen;
        QBrush brush;
        QString str;
        QFont font;

        paint.begin(this);
        paint.setPen(pen);
        paint.setFont(font);
        paint.setBrush(brush);

        pen.setColor(Qt::magenta);
        pen.setWidth(7);
        pen.setStyle(Qt::SolidLine);

        font.setPointSize(20);

        brush.setStyle(Qt::Dense3Pattern);
        brush.setColor(Qt::white);


        for (int i=0;i<coun;i++)
        {
            otstup=-10;
            if (grad>180) otstup=130;
            str=QString::number(i+1);
            node[i].x=mid_arg+(200*cos(grad/57));
            node[i].y=mid_func+(200*-sin(grad/57));
            paint.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap));
            paint.setBrush(QBrush(Qt::black, Qt::SolidPattern));
            paint.drawEllipse(node[i].x,node[i].y,100,100);
            paint.drawText(node[i].x+48,node[i].y+otstup,str);
            grad+=increm;
        }

        if (temp>1){
            for (int i=0; i<coun; i++)
            {
                for (int j=0; j<coun; j++)
                {
                    if (arr[i][j]<1000&&arr[i][j]>0)
                    {
                        pen.setStyle(Qt::DashLine);
                        pen.setWidth(3);
                        paint.setPen(pen);
                        paint.drawLine(node[i].x+50,node[i].y+50,node[j].x+50,node[j].y+50);
                    }
                }
            }
        }


        if (temp==3)
        {
            pen.setStyle(Qt::SolidLine);
            pen.setWidth(5);
            pen.setColor(Qt::black);
            paint.setPen(pen);
            for (int i=1; i<coun+1; i++)
                 paint.drawLine(node[way[i-1]].x+50,node[way[i-1]].y+50,node[way[i]].x+50,node[way[i]].y+50);
        }
        paint.end();
    }
}

void Comi::on_spinBox_valueChanged(int arg1)
{
    coun = arg1;
}

void Comi::on_create_pressed()
{
    ui->create->setStyleSheet("color: rgb(255, 85, 255) font-size: 24px;border: 2px solid rgb(205, 205, 255)");

}

void Comi::on_create_released()
{
    ui->create->setStyleSheet("background-color: rgb(45, 40, 40); color: rgb(255, 85, 255);");
}

void Comi::on_build_pressed()
{
    ui->build->setStyleSheet("color: rgb(255, 85, 255);font-size: 24px;border: 2px solid rgb(205, 205, 255);");
}

void Comi::on_build_released()
{
    ui->build->setStyleSheet("background-color: rgb(40, 40, 40); color: rgb(255, 85, 255);");
}

void Comi::on_run_pressed()
{
    ui->run->setStyleSheet("color: rgb(255, 85, 255);font-size: 24px;border: 2px solid rgb(205, 205, 255);");
}

void Comi::on_run_released()
{
    ui->run->setStyleSheet("background-color: rgb(40, 40, 40); color: rgb(255, 85, 255);");
}

