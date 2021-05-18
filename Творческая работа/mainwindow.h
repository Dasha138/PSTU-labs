#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_red_h_clicked();
    void on_pushButton_red_m_clicked();
    void on_pushButton_red_s_clicked();
    void on_spinBox_hour_valueChanged(int arg1);
    void on_spinBox_min_valueChanged(int arg1);
    void on_spinBox_sec_valueChanged(int arg1);
    void on_spinBox_hour_2_valueChanged(int arg1);
    void on_spinBox_min_2_valueChanged(int arg1);
    void on_spinBox_sec_2_valueChanged(int arg1);
};
#endif // MAINWINDOW_H
