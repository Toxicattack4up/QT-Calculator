#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_button_plus_minus_clicked()
{
    operand *= -1;
    update_Lcd_Operand();
}


void MainWindow::on_button_0_clicked()
{

    operand = operand * 10;
    update_Lcd_Operand();
}


void MainWindow::on_button_equal_clicked()
{
    if (pending_operation == "*") {
        result = second_operand * operand;
    } else if (pending_operation == "+") {
        result = second_operand + operand;
    } else if (pending_operation == "-") {
        result = second_operand - operand;
    } else if (pending_operation == "/") {
        if  (operand != 0) {
            result = second_operand / operand;
        } else {
            ui->lcdOperand->display("Err");
            return;
        }
    }

    pending_operation.clear();
    ui->lineResult->setText(QString::number(result));
    operand = result;
    second_operand = 0;

    operation_complited = true;
    update_Lcd_Operand();
}


void MainWindow::on_button_devide_clicked()
{
    if (operation_complited) {
        second_operand = result;
    } else {
        second_operand = operand;
    }

    operand = 0;
    pending_operation = "/";

    if (!ui->lineResult->text().isEmpty()) {
        ui->lineResult->setText(ui->lineResult->text() + " /");
    } else {
        ui->lineResult->setText(QString::number(second_operand) + " /");
    }

    operation_complited = false;
    update_Lcd_Operand();
}


void MainWindow::on_button_1_clicked()
{
    operand = operand * 10 + 1;
    update_Lcd_Operand();
}


void MainWindow::on_button_2_clicked()
{
    operand = operand * 10 + 2;
    update_Lcd_Operand();
}


void MainWindow::on_button_3_clicked()
{
    operand = operand * 10 + 3;
    update_Lcd_Operand();
}


void MainWindow::on_button_plus_clicked()
{
    if (operation_complited) {
        second_operand = result;
    } else {
        second_operand = operand;
    }

    operand = 0;
    pending_operation = "+";

    if (!ui->lineResult->text().isEmpty()) {
        ui->lineResult->setText(ui->lineResult->text() + " +");
    } else {
        ui->lineResult->setText(QString::number(second_operand) + " +");
    }

    operation_complited = false;

    update_Lcd_Operand();
}


void MainWindow::on_button_4_clicked()
{
    operand = operand * 10 + 4;
    update_Lcd_Operand();
}


void MainWindow::on_button_5_clicked()
{
    operand = operand * 10 + 5;
    update_Lcd_Operand();
}


void MainWindow::on_button_6_clicked()
{
    operand = operand * 10 + 6;
    update_Lcd_Operand();
}


void MainWindow::on_button_minus_clicked()
{
    if (operation_complited) {
        second_operand = result;
    } else {
        second_operand = operand;
    }

    operand = 0;
    pending_operation = "-";

    if (!ui->lineResult->text().isEmpty()) {
        ui->lineResult->setText(ui->lineResult->text() + " -");
    } else {
        ui->lineResult->setText(QString::number(second_operand) + " -");
    }

    operation_complited = false;

    update_Lcd_Operand();
}


void MainWindow::on_button_7_clicked()
{
    operand = operand * 10 + 7;
    update_Lcd_Operand();
}


void MainWindow::on_button_8_clicked()
{
    operand = operand * 10 + 8;
    update_Lcd_Operand();
}


void MainWindow::on_button_9_clicked()
{
    operand = operand * 10 + 9;
    update_Lcd_Operand();
}


void MainWindow::on_button_multiply_clicked()
{
    if(!operation_complited) {
        second_operand = operand;
        operand = 0;
        pending_operation = "*";

        if (!ui->lineResult->text().isEmpty()) {
            ui->lineResult->setText(ui->lineResult->text() + " *");
        } else {
            ui->lineResult->setText(QString::number(second_operand) + " *");
        }

    } else {
        second_operand = operand;
        operand = 0;
        pending_operation = "*";
        ui->lineResult->setText(QString::number(second_operand) + " *");
        operation_complited = false;
    }
    update_Lcd_Operand();
}


void MainWindow::on_button_delete_typed_text_clicked()
{
    operand = 0;
    update_Lcd_Operand();
}


void MainWindow::on_button_erase_everything_clicked()
{
    operand = 0;
    second_operand = 0;
    result = 0;
    operation_complited = false;
    pending_operation.clear();

    ui->lineResult->clear();
    ui->lcdOperand->display(0);

    update_Lcd_Operand();
}


void MainWindow::on_button_one_character_clicked()
{
    operand = (int)operand / 10;
    update_Lcd_Operand();
}

void MainWindow::update_Lcd_Operand()
{
    ui->lcdOperand->display(operand);
}


