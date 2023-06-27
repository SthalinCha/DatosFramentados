#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->bttnGuardar, SIGNAL(clicked()), this, SLOT(on_actionGuardar_triggered()));


    connect(ui->bttnClientes, SIGNAL(clicked()), this, SLOT(on_bttnclientes_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    QString campoTexto = ui->textCampoDatos->toPlainText();

    Cliente cliente(campoTexto.toStdString());



    ui->lineNombre->setText(QString::fromStdString(cliente.getNombre()));
    ui->lineApellido->setText(QString::fromStdString(cliente.getApellido()));
    ui->lineCedula->setText(QString::fromStdString(cliente.getCedula()));
    ui->lineDireccion->setText(QString::fromStdString(cliente.getDireccion()));
    ui->lineTelefono->setText(QString::fromStdString(cliente.getTelefono()));
    ui->lineEmail->setText(QString::fromStdString(cliente.getEmail()));
}


void MainWindow::on_bttnClientes_clicked()
{

    ListaClientes dialog;
    dialog.mostrarClientes();
    dialog.exec();
}


void MainWindow::on_bttnGuardar_clicked()
{

    QString fileName;
    if (!currentFilePath.isEmpty())
    {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Guardar"), tr("¿Desea guardar en el mismo archivo?"),
                                      QMessageBox::Yes|QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
            fileName = currentFilePath;
        }
        else
        {
            fileName = QFileDialog::getSaveFileName(nullptr, tr("Guardar Archivo"), QDir::homePath(), "DAT files (*.dat)");
            fileName += ".dat";
            currentFilePath = fileName;
        }
    }
    else
    {
        fileName = QFileDialog::getSaveFileName(nullptr, tr("Guardar Archivo"), QDir::homePath(), "DAT files (*.dat)");
        fileName += ".dat";
        currentFilePath = fileName;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Error"), tr("No se pudo abrir el archivo"));
        return;
    }

    QDataStream out(&file);


    QString nombre = ui->lineNombre->text();
    QString apellido = ui->lineApellido->text();
    QString cedula =ui->lineCedula->text();
    QString direccion = ui->lineDireccion->text();
    QString telefono = ui->lineTelefono->text();
    QString email =ui->lineEmail->text();

    out <<cedula << nombre << apellido << direccion << telefono <<email;
    file.close();

    QMessageBox::information(this, tr("Mensaje"), tr("Guardado con exito"));
}


void MainWindow::on_actionAcerca_de_triggered()
{
    Acerca ventana;
    ventana.exec();
}


