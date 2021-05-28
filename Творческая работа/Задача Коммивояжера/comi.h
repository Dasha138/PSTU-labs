#ifndef COMI_H
#define COMI_H

#include <QMainWindow>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Comi; }
QT_END_NAMESPACE

class Comi : public QMainWindow
{
    Q_OBJECT

public:
    Comi(QWidget *parent = nullptr);
    ~Comi();



    void Close();

    void Print();

    void Search_min();

    void Search_null(int num);

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_create_clicked();

    void on_build_clicked();

    void on_create_pressed();

    void on_create_released();

    void on_build_pressed();

    void on_build_released();

    void on_run_pressed();

    void on_run_released();

    void on_run_clicked();

private:
    Ui::Comi *ui;

protected:
    void paintEvent(QPaintEvent*) override;
};
#endif // COMI_H
