#ifndef FORMCAMWINDOW_H
#define FORMCAMWINDOW_H


#include "workspace.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>
#include <QMessageBox>

#include "openvio.h"

#include "multipleViewTriangulation.h"

#include "MuItemCam.h"
#include "winusbdriver.h"
#include "FormVioWindow.h"
#include <QTimer>
#include <QLabel>
#include <QInputDialog>
#include <QFileDialog>

#include "formvisionwindow.h"
#include "form3dviewwindow.h"
#include "formlogwindow.h"

class MuItemCtrl;
#include "MuItemCtrl.h"

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
    QLabel *status_msg,*status_speed;
    int recv_count_1s;
    FirmwareUpgrade *upgrade;
    
    MultipleViewTriangulation multipleViewTriangulation;
    FormVisionWindow fVisionWindow;
    Form3DViewWindow f3DViewWindow;
    FormLogWindow fLogWindow;
    MuItemCtrl *muItemCtrl;

    explicit FormCamWindow(QWidget *parent = nullptr);
    ~FormCamWindow();

private slots:
    void on_pb_scan_camera_clicked();
    void on_pb_capture_clicked();
    void vioItemSelected(const QModelIndex &index);
    void doubleClickedSlot(const QModelIndex &index);
    void onTimeOut(); 
    void ProvideContextMenu(const QPoint &pos);
    void on_actionImg_save_path_triggered();
    void on_action_position_triggered();
    void on_action3d_view_triggered();
    void on_actionLoad_vision_param_triggered();
    void on_actionLog_view_triggered();
    void on_actionUpgrade_triggered();
private:
    Ui::FormCamWindow *ui;
    
protected: 
     void closeEvent(QCloseEvent *event);     
};

#endif
