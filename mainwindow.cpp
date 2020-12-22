#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "pawn.h"
#include "QHBoxLayout"
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget_2->setColumnCount(1);

}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::promoteToHorse()
{
    if(this->box->piece->getColor().compare("white")==0)
        this->box->piece->imagen = QPixmap("://imgs/horse1.png");
    else
        this->box->piece->imagen = QPixmap("://imgs/horse.png");
    this->box->setIcon(this->box->piece->imagen);
    pantalla->hide();
    show();
}
void MainWindow::promoteToBishop()
{
    if(this->box->piece->getColor().compare("white")==0)
        this->box->piece->imagen = QPixmap("://imgs/bishop1.png");
    else
        this->box->piece->imagen = QPixmap("://imgs/bishop.png");
    this->box->setIcon(this->box->piece->imagen);
    pantalla->hide();
    show();
}
void MainWindow::promoteToQueen()
{
    if(this->box->piece->getColor().compare("white")==0)
        this->box->piece->imagen = QPixmap("://imgs/queen1.png");
    else
        this->box->piece->imagen = QPixmap("://imgs/queen.png");
    this->box->setIcon(this->box->piece->imagen);
    pantalla->hide();
    show();
}
void MainWindow::promoteToTower()
{
    if(this->box->piece->getColor().compare("white")==0)
        this->box->piece->imagen = QPixmap("://imgs/rook1.png");
    else
        this->box->piece->imagen = QPixmap("://imgs/rook.png");
    this->box->setIcon(this->box->piece->imagen);
    pantalla->hide();
    show();
}

void MainWindow::registrarMovimiento(std::string  cadena)
{
    int indice = ui->listWidget->count()+1;
    ui->listWidget->addItem(QString::number(indice)+": "+QString::fromStdString(cadena));
}
void MainWindow::addPiezaEliminada(Piece * pieza)
{
    if(pieza->getColor().compare("white")==0)
    {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        QTableWidgetItem* item = new QTableWidgetItem(pieza->imagen , QString::fromStdString(pieza->getPiece()) ,  0);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1 , 0 , item);
    }
    else
    {
        std::cout<<"A la segunda fila"<<std::endl;
        ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
        QPixmap piezaImagen = pieza->imagen;
        QTableWidgetItem* item = new QTableWidgetItem(piezaImagen , QString::fromStdString(pieza->getPiece()) ,  0);
        ui->tableWidget_2->setItem(ui->tableWidget_2->rowCount()-1 , 0 , item);
    }
}
void MainWindow::showPiecePromoteOptions(Box * box)
{
    this->box = box;
    this->pantalla= new QWidget;
    QPushButton *btnHorse = new QPushButton;
    QPushButton *btnBishop = new QPushButton;
    QPushButton *btnTower = new QPushButton;
    QPushButton *btnQueen = new QPushButton;

    QHBoxLayout * layout = new QHBoxLayout;
    btnHorse->setText("Horse");
    connect(btnHorse, SIGNAL(clicked()), this, SLOT(promoteToHorse()));
    btnBishop->setText("Bishop");
    connect(btnBishop, SIGNAL(clicked()), this, SLOT(promoteToBishop()));
    btnTower->setText("Tower");
    connect(btnTower, SIGNAL(clicked()), this, SLOT(promoteToTower()));
    btnQueen->setText("Queen");
    connect(btnQueen, SIGNAL(clicked()), this, SLOT(promoteToQueen()));

    layout->addWidget(btnHorse);
    layout->addWidget(btnBishop);
    layout->addWidget(btnQueen);
    layout->addWidget(btnTower);

    pantalla->setLayout(layout);
    pantalla->show();
    hide();


}

