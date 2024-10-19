#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString push_button  =
            "QPushButton { "
            "border-radius: 25px; "
            "background-color: #3b3b3b; ""} "

            "QPushButton:hover { "
            "background-color: #545454; ""} "

            "QPushButton:pressed { "
            "background-color: #6e6e6e; ""}";
    ui->setupUi(this);
    ui->button_1->setStyleSheet(push_button);
    ui->button_2->setStyleSheet(push_button);
    ui->button_3->setStyleSheet(push_button);
    ui->button_4->setStyleSheet(push_button);
    ui->button_5->setStyleSheet(push_button);
    ui->button_6->setStyleSheet(push_button);
    ui->button_7->setStyleSheet(push_button);
    ui->button_8->setStyleSheet(push_button);
    ui->button_9->setStyleSheet(push_button);
    ui->button_0->setStyleSheet(push_button);
    ui->button_plus_minus->setStyleSheet(push_button);

    QString push_button_top  =
        "QPushButton { "
        "border-radius: 25px; "
        "background-color: #717171; ""} "

        "QPushButton:hover { "
        "background-color: #8a8a8a; ""} "

        "QPushButton:pressed { "
        "background-color: #a3a3a3; ""}";

    ui->button_one_character->setStyleSheet(push_button_top);
    ui->button_erase_everything->setStyleSheet(push_button_top);
    ui->button_delete_typed_text->setStyleSheet(push_button_top);

    QString push_button_right  =
        "QPushButton { "
        "border-radius: 25px; "
        "background-color: #ffad0a; ""} "

        "QPushButton:hover { "
        "background-color: #ffbe3d; ""} "

        "QPushButton:pressed { "
        "background-color: #ffcf70; ""}";

    ui->button_plus->setStyleSheet(push_button_right);
    ui->button_minus->setStyleSheet(push_button_right);
    ui->button_equal->setStyleSheet(push_button_right);
    ui->button_devide->setStyleSheet(push_button_right);
    ui->button_multiply->setStyleSheet(push_button_right);
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
