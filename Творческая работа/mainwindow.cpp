#include "mainwindow.h"
#include "ui_mainwindow.h"

int choose_box = 0;
int h, m, s, h1, m1, s1, h_out, m_out, s_out;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_plus_clicked()
{
    ui->sign_label->setText("+");
    choose_box = 1;
    s_out = s1;
    m_out = m1;
    h_out = h1;
}

void MainWindow::on_pushButton_minus_clicked()
{
    ui->sign_label->setText("-");
    choose_box = 2;
    s_out = s1;
    m_out = m1;
    h_out = h1;
}

void MainWindow::on_pushButton_equal_clicked()
{
    if(choose_box == 1)
    {
        s_out=(s+s_out)%60;
        m_out=(m_out+m+(s_out+s)/60)%60;
        h_out=h_out+h+(m_out+m+(s_out+s)/60)/60;
        ui->out_hour->setText(QString::number(h_out,'i',0));
        ui->out_min->setText(QString::number(m_out,'i',0));
        ui->out_sec->setText(QString::number(s_out,'i',0));
    }
    if(choose_box == 2)
    {
        if(s_out<=0)
        {
            s_out+=59;
            m_out--;
        }
        else
            s_out=(s_out-s)%60;
        if(m_out<=0)
        {
            m_out+=59;
            h_out--;
        }
        else
            m_out=(m_out-m+(s_out-s)/60)%60;
        if(h_out<=0)
        {
            ui->out_hour->setText("Ошибка!");
        }
        else{
            h_out=h_out-h+(m_out-m+(s_out-s)/60)/60;
            ui->out_hour->setText(QString::number(h_out,'i',0));
            ui->out_min->setText(QString::number(m_out,'i',0));
            ui->out_sec->setText(QString::number(s_out,'i',0));
        }
    }
}

double abs_time;

void MainWindow::on_pushButton_red_h_clicked()
{
    abs_time = (double)h1 + (double)m1/60.0f + (double)s1/1440.0f;
    ui->show_result->setText(QString::number(abs_time));
    ui->result_sign->setText("ч");
}

void MainWindow::on_pushButton_red_m_clicked()
{
    abs_time = (double)h1 * 60.0f + (double)m1 + (double)s1/60.0f;
    ui->show_result->setText(QString::number(abs_time));
    ui->result_sign->setText("мин");
}

void MainWindow::on_pushButton_red_s_clicked()
{
    abs_time = (double)h1*1440.0f + (double)m1*60.0f + (double)s1;
    ui->show_result->setText(QString::number(abs_time));
    ui->result_sign->setText("сек");
}

void MainWindow::on_spinBox_hour_valueChanged(int arg1)
{
    h = arg1;
}

void MainWindow::on_spinBox_min_valueChanged(int arg1)
{
    m = arg1;
}

void MainWindow::on_spinBox_sec_valueChanged(int arg1)
{
    s = arg1;
}

void MainWindow::on_spinBox_hour_2_valueChanged(int arg1)
{
    h1 = arg1;
}

void MainWindow::on_spinBox_min_2_valueChanged(int arg1)
{
    m1 = arg1;
}

void MainWindow::on_spinBox_sec_2_valueChanged(int arg1)
{
    s1 = arg1;
}
