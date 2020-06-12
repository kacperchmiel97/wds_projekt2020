#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>

#include "../paint_test/realtimerenderer.h"
#include "../paint_test/maprenderer.h"
#include "chart.h"
#include "ipdialog.h"
#include "../socket_test/socketclient.h"
#include "../socket_test/socketserver.h"
#include "../socket_test/serverwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * \brief Okno główne programu
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void draw(void);
    void clientConnect(QString ip);
    void emulatorToggleShow(bool show);
    void connection_lost(void);

private:
    void closeEvent(QCloseEvent *event);

private:
    ServerWindow *sw; //!< Okno emulatora
    SocketServer *server; //!< Emulator
    SocketClient *client; //!< Odbiornik danych
    QTimer *timer; //!< Timer aktualizujący główne okno
    QMessageBox errorBox;
    QPainter *painter;
    Ui::MainWindow *ui;

    RealtimeRenderer *realTimeDrawPlane;
    MapRenderer *mapDrawPlane;
    Chart *tiltChart;
    Chart *pidChart;
    QString host_ip;
    ipdialog *ipDialog;
};
#endif // MAINWINDOW_H
