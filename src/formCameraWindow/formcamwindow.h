#ifndef FORMCAMWINDOW_H
#define FORMCAMWINDOW_H


#include "workspace.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>

#include "openvio.h"

#include "MuItemCam.h"
#include "winusbdriver.h"
#include "FormVioWindow.h"
#include <QTimer>
#include <QLabel>

namespace Ui {
class FormCamWindow;
}

class FormCamWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTimer *timer;
public:
    QList<OPENVIO*> openvioList;
    WinUSBDriver *qwinusb;
    Log *mlog;
    QLabel *status_msg,*status_speed;
    int recv_count_1s;
    
    explicit FormCamWindow(QWidget *parent = nullptr);
    ~FormCamWindow();

private slots:
    void on_pb_scan_camera_clicked();
    void vioItemSelected(const QModelIndex &index);
    void doubleClickedSlot(const QModelIndex &index);
    void onTimeOut(); 
private:
    Ui::FormCamWindow *ui;
};

#endif
