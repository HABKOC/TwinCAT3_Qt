#pragma execution_character_set("utf-8")//ʹMSVC��������UTF-8�ı����ʽ���б��룬�Է�ֹ���ɳ�����������������
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TwinCAT3_Qt.h"

#include <windows.h>
#include "D:\TwinCAT3\AdsApi\TcAdsDll\Include\TcAdsDef.h"
#include "D:\TwinCAT3\AdsApi\TcAdsDll\Include\TcAdsAPI.h"
#include "QMessageBox"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class TwinCAT3_Qt : public QMainWindow
{
    Q_OBJECT

public:
    TwinCAT3_Qt(QWidget *parent = nullptr);
    ~TwinCAT3_Qt();

private:
    Ui::TwinCAT3_QtClass ui;

    AmsAddr addr;
    PAmsAddr  pAddr=&addr;
    ushort  nAdsState;
    ushort  nDeviceState;
    ulong  nLength;
    long nErr;
    void  *pData;

private slots:
    void timer1_Tick();
    void On_pushButton_Clicked();
};
