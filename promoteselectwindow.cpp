#include "promoteselectwindow.h"
#include "ui_promoteselectwindow.h"

PromoteSelectWindow::PromoteSelectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PromoteSelectWindow)
{
    ui->setupUi(this);
}

