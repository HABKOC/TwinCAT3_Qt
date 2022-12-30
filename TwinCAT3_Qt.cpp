#include "TwinCAT3_Qt.h"

TwinCAT3_Qt::TwinCAT3_Qt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    AdsPortOpen();
    nErr=AdsGetLocalAddress(pAddr);
    pAddr->port = 851;
    if (nErr)
    {
        QMessageBox::information(NULL,"´íÎó",tr("ADSÍ¨Ñ¶Á¬½Ó´íÎóÂë£º%1").arg(nErr),QMessageBox::Ok,QMessageBox::Ok||QMessageBox::Close);
    }

    QTimer *timer1 = new QTimer(this);
    timer1->start(500);
    connect(timer1,SIGNAL(timeout()),this,SLOT(timer1_Tick()));
    connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(On_pushButton_Clicked()));
}

TwinCAT3_Qt::~TwinCAT3_Qt()
{}

void TwinCAT3_Qt::timer1_Tick()
{
    nErr = AdsSyncReadStateReq(pAddr,&nAdsState,&nDeviceState);
    if (nErr)
    {
        ui.pushButton->setText("Stop");
        ui.pushButton->setStyleSheet("background-color: rgb(255, 0, 0)");//±³¾°ºìÉ«
    }
    else
    {
        if (nAdsState == 5)
        {
            ui.pushButton->setText("Run");
            ui.pushButton->setStyleSheet("background-color: rgb(85, 255, 127)");//±³¾°ÂÌÉ«
        }
        else if (nAdsState == 6)
        {
            ui.pushButton->setText("Stop");
            ui.pushButton->setStyleSheet("background-color: rgb(255, 0, 0)");//±³¾°ºìÉ«
        }
    }
}

void TwinCAT3_Qt::On_pushButton_Clicked()
{
    if (nAdsState == 5)
    {
        nAdsState = 6;
    }
    else if (nAdsState == 6)
    {
        nAdsState = 5;
    }
    AdsSyncWriteControlReq(pAddr, nAdsState, nDeviceState,0,NULL);
}