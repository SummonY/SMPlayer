#ifndef SCANWIDGET_H
#define SCANWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Phonon/MediaObject>
#include <Phonon/BackendCapabilities>
#include <QString>
#include <QStringList>
#include <QSequentialAnimationGroup>
#include "pixitem.h"

class ScanWidget : public QWidget
{
    Q_OBJECT

public:
    ScanWidget(int imageNum,QStringList imageName,QString musicName);

    void createBtns();
    void setupScene();

    QString getMusicTime();
protected slots:
    void playButtonClicked();
    void pauseButtonCLicked();
    void stopButtonClicked();

    void showTime();
    void closeEvent(QCloseEvent *);
private:
    //set up scene and view
    QGraphicsScene *scene;
    QGraphicsView *view;
    QSequentialAnimationGroup *imageGroup ;

    PixItem *pixItem;

    //process the music
    Phonon::MediaObject *music;
    // play pause stop the music and slide
    QLabel *timeLabel;                          //get current time and total time
    QPushButton *playBtn;
    QPushButton *pauseBtn;
    QPushButton *stopBtn;

    QHBoxLayout *btnLayout ;                   //button layout
};

#endif // SCANWIDGET_H
