#ifndef IPDIALOG_H
#define IPDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QCloseEvent>

namespace Ui {
class ipdialog;
}

class ipdialog : public QDialog
{
    Q_OBJECT

public:
    explicit ipdialog(QWidget *parent = nullptr);
    ~ipdialog();

    void setText(QString t);
    void keyPressEvent(QKeyEvent *e);

signals:
    void enteredText(QString text);

private slots:
    void sendText(void);

public slots:
    void hideWindow(void);
    void showWindow(void);

private:
    Ui::ipdialog *ui;
    QString text;
};

#endif // IPDIALOG_H
