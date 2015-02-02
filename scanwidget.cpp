#include <QFrame>
#include <QTime>
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPropertyAnimation>

#include "scanwidget.h"

#define MAXIMAGECOUNT 10

ScanWidget::ScanWidget(int imageNum,QStringList imageName,QString musicName)
{
    //set the widget property
    this->setGeometry(300,180,350,350);

    //create view and scene
    setupScene();

    QPropertyAnimation* anim[MAXIMAGECOUNT];
    QLabel *imageLabel[MAXIMAGECOUNT];

    imageGroup = new QSequentialAnimationGroup;
    //create image flash
    for(int i=0;i<imageNum;i++)
    {
        //add image
        QString imagename = imageName.at(i);
        QPixmap *pixmap = new QPixmap(imagename);
        imageLabel[i] = new QLabel;
        imageLabel[i]->setPixmap(*pixmap);
        imageLabel[i]->setGeometry(QRect(-400,-400,220,190));

        scene->addWidget(imageLabel[i]);

        anim[i] = new QPropertyAnimation(imageLabel[i],"pos");
        anim[i]->setDuration(10000);

        switch(i)
        {
        case 0:
            anim[i]->setStartValue(QPoint(-400,-400));
            anim[i]->setEndValue(QPoint(100,100));
            anim[i]->setEasingCurve(QEasingCurve::SineCurve);
            break;
        case 1:
            anim[i]->setStartValue(QPoint(-400,-100));
            anim[i]->setEndValue(QPoint(200,-100));
            anim[i]->setEasingCurve(QEasingCurve::Linear);
            break;
        case 2:
            anim[i]->setStartValue(QPoint(150,-100));
            anim[i]->setEndValue(QPoint(-400,-100));
            anim[i]->setEasingCurve(QEasingCurve::Linear);
            break;
        case 3:
            anim[i]->setStartValue(QPoint(150,-400));
            anim[i]->setEndValue(QPoint(-300,100));
            anim[i]->setEasingCurve(QEasingCurve::SineCurve);
            break;
        case 4:
            anim[i]->setStartValue(QPoint(-100,-330));
            anim[i]->setEndValue(QPoint(-100,300));
            anim[i]->setEasingCurve(QEasingCurve::InCirc);
            break;
        case 5:
            anim[i]->setStartValue(QPoint(-100,300));
            anim[i]->setEndValue(QPoint(-100,-330));
            anim[i]->setEasingCurve(QEasingCurve::OutCirc);
            break;
        default :
                anim[i]->setStartValue(QPoint(-400,-400));
                anim[i]->setEndValue(QPoint(100,100));
                anim[i]->setEasingCurve(QEasingCurve::SineCurve);
                break;
        }
        imageGroup->addAnimation(anim[i]);
    }
    imageGroup->setLoopCount(10);

    //create music
    music = Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(musicName));

    timeLabel = new QLabel;
    //create buttons
    createBtns();

    //change current time
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);

    //set scan layout
    QVBoxLayout *scanLayout = new QVBoxLayout(this);
    scanLayout->addWidget(view);
    scanLayout->addLayout(btnLayout);
}

//create buttons
void ScanWidget::createBtns()
{
    QFrame * frame = new QFrame;
    //create play button
    playBtn = new QPushButton(frame);
    playBtn->setMaximumSize(40,40);
    playBtn->setIconSize(QSize(playBtn->width(),playBtn->height()));
    playBtn->setIcon(QIcon("./image/play.png"));
    playBtn->setToolTip(tr("play"));
    connect(playBtn,SIGNAL(clicked()),this,SLOT(playButtonClicked()));

    //create pause button
    pauseBtn = new QPushButton(frame);
    pauseBtn->setMaximumSize(40,40);
    pauseBtn->setIconSize(QSize(pauseBtn->width(),pauseBtn->height()));
    pauseBtn->setIcon(QIcon("./image/pause.png"));
    pauseBtn->setToolTip(tr("Pause"));
    connect(pauseBtn,SIGNAL(clicked()),this,SLOT(pauseButtonCLicked()));

    //create stop button
    stopBtn = new QPushButton(frame);
    stopBtn->setMaximumSize(40,40);
    stopBtn->setIconSize(QSize(stopBtn->width(),stopBtn->height()));
    stopBtn->setIcon(QIcon("./image/stop.png"));
    stopBtn->setToolTip(tr("Stop"));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(stopButtonClicked()));

    //button layout
    btnLayout = new QHBoxLayout;
    btnLayout->addWidget(timeLabel);
    btnLayout->addWidget(playBtn);
    btnLayout->addWidget(pauseBtn);
    btnLayout->addWidget(stopBtn);
}

//set up scene
void ScanWidget::setupScene()
{
    //create scene
    scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-40,-40,80,80));
    scene->setBackgroundBrush(QBrush());
    //create view
    view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(80,80);

    //initial scene
    QString imageName="./image/search.png";
    QPixmap *pixmap = new QPixmap(imageName);
    pixItem = new PixItem(pixmap);
    scene->addItem(pixItem);
    pixItem->setPos(0,0);

}

//when clicked the play button
void ScanWidget::playButtonClicked()
{
    music->play();
    imageGroup->start();
}

//when clicked the pause button
void ScanWidget::pauseButtonCLicked()
{
    music->pause();
    imageGroup->pause();
}

//when clicked the stop button
void ScanWidget::stopButtonClicked()
{
    music->stop();
    imageGroup->stop();
}

//show music time
void ScanWidget::showTime()
{
    QString time;
    time="Time:"+getMusicTime();
    timeLabel->setText(time);
}

//get music total time
QString ScanWidget::getMusicTime()
{
    qint64 totalTimeValue = music->totalTime();
    qint64 currentTimeValue = music->currentTime();
    QTime currentTime(0,(currentTimeValue/60000)%60,(currentTimeValue/1000)%60);
    QTime totalTime(0,(totalTimeValue/60000)%60,(totalTimeValue/1000)%60);
    QString timeStr =currentTime.toString("mm:ss")+"|"+totalTime.toString("mm:ss");
    return timeStr;
}

//close widget
void ScanWidget::closeEvent(QCloseEvent *)
{
    music->stop();
    imageGroup->stop();
}
