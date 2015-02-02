#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QtGui/QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include "centralwidget.h"
#include "scanwidget.h"

class ImageProcessor : public QMainWindow
{
    Q_OBJECT

public:
    ImageProcessor(QWidget *parent = 0);
    ~ImageProcessor();

    void createMenus();                             //create menus
    void createActions();                           //create actions
    void createTools();                             //create tools bar

protected slots:
    void imageTabelClicked();

    void addImage();
    void addMusic();
    void resumeWindow();
    void exitWindow();
    void deleteImage();
    void deleteMusic();
    void scanEffect();
    void showAbout();

private:
    QMenu *fileMenus;                               //menus
    QMenu *actionMenus;
    QMenu *aboutMenu;

    CentralWidget *centralWidget;                   //central widget
    ScanWidget *scanWidget;                         //scan the slider widget

    QString imageName;
    QString musicName;

    QToolBar *imageTools;                            //tool bar
    QToolBar *musicTools;
    QToolBar *actionTools;
    QToolBar *otherTools;

    QAction *addImageAction;                        //actions
    QAction *deleteImageAction;
    QAction *addMusicAction;
    QAction *deleteMusicAction;
    QAction *exitAction;
    QAction *resumeAction;
    QAction *scanAction;
    QAction *aboutAction;
};

#endif // IMAGEPROCESSOR_H
