#include "ipdialog.h"
#include "ui_ipdialog.h"

ipdialog::ipdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ipdialog)
{
    ui->setupUi(this);

    connect(ui->connectButton, SIGNAL(released()), this, SLOT(sendText()));
    connect(ui->cancelButton, SIGNAL(released()), this, SLOT(hideWindow()));

    setWindowFlags(Qt::Dialog | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
    setWindowTitle("Enter host IP");
    setFixedSize(size());
    setModal(true);

    show();
}

void ipdialog::keyPressEvent(QKeyEvent *e)
{
    switch (e->key ()) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        sendText();
        break;

    default:
        QDialog::keyPressEvent (e);
    }
}

ipdialog::~ipdialog()
{
    delete ui;
}

void ipdialog::setText(QString t){
    text= t;
}

void ipdialog::hideWindow(void){
    hide();
}

void ipdialog::showWindow(void){
    show();
}

void ipdialog::sendText(void){
    text= ui->lineEdit->text();
    emit enteredText(text);
}
