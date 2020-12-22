#ifndef PROMOTESELECTWINDOW_H
#define PROMOTESELECTWINDOW_H

#include <QMainWindow>
#include "board.h"
namespace Ui {
class PromoteSelectWindow;
}

class PromoteSelectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PromoteSelectWindow(QWidget *parent = nullptr);
    ~PromoteSelectWindow();


private:
    Ui::PromoteSelectWindow *ui;
};

#endif // PROMOTESELECTWINDOW_H
