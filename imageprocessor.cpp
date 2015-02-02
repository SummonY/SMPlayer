#include <QPalette>
#include <QMessageBox>
#include <QTextEdit>
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QFileDialog>
#include <QFileInfo>
#include <QStringList>
#include <QtGui>
#include "imageprocessor.h"

#define MAXIMAGECOUNT 10                    //define array maxnum

ImageProcessor::ImageProcessor(QWidget *parent)
    : QMainWindow(parent)
{
    //splash screen
    QTextEdit *edit = new QTextEdit;
    edit->setText("Welcom to SMPlayer!");
    setCentralWidget(edit);
    //sleep
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<2000)
    {
        QCoreApplication::processEvents();
    }

    //set the window property
    this->setWindowTitle(tr("SMPlayer"));                           //title
    this->setWindowIcon(QIcon("./image/icon.png"));                 //icon
    this->setGeometry(200,150,800,400);                              //geometry
    QPalette p;                                                      //background
    p.setColor(QPalette::Background,QColor(100,100,100));
    setPalette(p);

    //create central widget
    centralWidget = new CentralWidget(0);
    setCentralWidget(centralWidget);

    createActions();
    createTools();
    createMenus();

    connect(centralWidget->imageTable,SIGNAL(clicked(QModelIndex)),this,SLOT(imageTabelClicked()));
}

ImageProcessor::~ImageProcessor()
{

}

//create actions
void ImageProcessor::createActions()
{
    //add image action
    addImageAction = new QAction(QIcon("./image/addimages.png"),tr("Add Image"),this);
    addImageAction->setShortcut(tr("Ctrl+I"));
    addImageAction->setStatusTip(tr("add images"));
    connect(addImageAction,SIGNAL(triggered()),this,SLOT(addImage()));

    //delete image action
    deleteImageAction = new QAction(QIcon("./image/deleteimage.png"),tr("Delete Image"),this);
    deleteImageAction->setShortcut(tr("Ctrl+G"));
    deleteImageAction->setStatusTip(tr("delete image"));
    connect(deleteImageAction,SIGNAL(triggered()),this,SLOT(deleteImage()));

    //add music action
    addMusicAction = new QAction(QIcon("./image/addmusics.png"),tr("Add Music"),this);
    addMusicAction->setShortcut(tr("Ctrl+M"));
    addMusicAction->setStatusTip(tr("add musics"));
    connect(addMusicAction,SIGNAL(triggered()),this,SLOT(addMusic()));

    //delete music action
    deleteMusicAction = new QAction(QIcon("./image/deletemusic.png"),tr("Delete Music"),this);
    deleteMusicAction->setShortcut(tr("Ctrl+U"));
    deleteMusicAction->setStatusTip(tr("delete music"));
    connect(deleteMusicAction,SIGNAL(triggered()),this,SLOT(deleteMusic()));

    //exit action
    exitAction = new QAction(QIcon("./image/exit.png"),tr("Exit"),this);
    exitAction->setShortcut(tr("Ctrl+E"));
    exitAction->setStatusTip(tr("exit"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(exitWindow()));

    //resume action
    resumeAction = new QAction(QIcon("./image/resume.png"),tr("Resume"),this);
    resumeAction->setShortcut(tr("Ctrl+R"));
    resumeAction->setStatusTip(tr("resume"));
    connect(resumeAction,SIGNAL(triggered()),this,SLOT(resumeWindow()));

    //scan action
    scanAction = new QAction(QIcon("./image/ok.png"),tr("Scan"),this);
    scanAction->setShortcut(tr("Ctrl+S"));
    scanAction->setStatusTip(tr("scan"));
    connect(scanAction,SIGNAL(triggered()),this,SLOT(scanEffect()));

    //about action
    aboutAction = new QAction(QIcon("./image/About.png"),tr("About"),this);
    aboutAction->setShortcut(tr("Ctrl+A"));
    aboutAction->setStatusTip(tr("about"));
    connect(aboutAction,SIGNAL(triggered()),this,SLOT(showAbout()));

}

//create menus
void ImageProcessor::createMenus()
{
    //file menus
    fileMenus = menuBar()->addMenu(tr("File"));
    fileMenus->addAction(addImageAction);
    fileMenus->addAction(addMusicAction);
    fileMenus->addSeparator();
    fileMenus->addAction(exitAction);

    //action menus
    actionMenus = menuBar()->addMenu(tr("Action"));
    actionMenus->addAction(deleteImageAction);
    actionMenus->addAction(deleteMusicAction);
    actionMenus->addSeparator();
    actionMenus->addAction(resumeAction);
    actionMenus->addAction(scanAction);

    //about menu
    aboutMenu = menuBar()->addMenu(tr("About"));
    aboutMenu->addAction(aboutAction);
}

//create tools
void ImageProcessor::createTools()
{
    //file tools bar
    imageTools = addToolBar("Image");
    imageTools->addAction(addImageAction);
    imageTools->addAction(deleteImageAction);

    //music tools bar
    musicTools = addToolBar("Music");
    musicTools->addAction(addMusicAction);
    musicTools->addAction(deleteMusicAction);

    //action tools bar
    actionTools = addToolBar("Action");
    actionTools->addAction(resumeAction);
    actionTools->addAction(scanAction);

    //about tool bar
    otherTools = addToolBar("Other");
    otherTools->addAction(aboutAction);
    otherTools->addAction(exitAction);
}

//add image slot
void ImageProcessor::addImage()
{
    imageName = QFileDialog::getOpenFileName(this,"open image dialog","./image/","Image files(*.png *.bmp *.jpg);;All files(*.*)");
    QFileInfo fileInfo(imageName);
    centralWidget->addimageTable(fileInfo);                     //give centralWidget image fileInfo

}

//add music slot
void ImageProcessor::addMusic()
{
    musicName = QFileDialog::getOpenFileName(this,"open music dialog","./music/","Music files(*.mp3 *.lrc);;All files(*.*)");
    QFileInfo fileInfo(musicName);
    centralWidget->addmusicTable(fileInfo);                     //give centralwidget music fileInfo
}

//exit this window slot
void ImageProcessor::exitWindow()
{
    this->close();
}

//resume the window init stat slot
void ImageProcessor::resumeWindow()
{
    centralWidget->resumeTableView();
}

//delete image slot
void ImageProcessor::deleteImage()
{
    centralWidget->deleteSeletedImage();
}

//delete music slot
void ImageProcessor::deleteMusic()
{
    centralWidget->deleteSeletedMusic();
}

//scan the effect slot
void ImageProcessor::scanEffect()
{
    //get music name
    QString musicName = centralWidget->getMusicName();
    int imageNum = 1;
    QStringList imageName = centralWidget->getAllImageName(imageNum);

    //create scan widget
    scanWidget = new ScanWidget(imageNum,imageName,musicName);
    scanWidget->show();
}

//custom show about message box slot
void ImageProcessor::showAbout()
{
    QMessageBox aboutMsgBox;
    aboutMsgBox.setWindowTitle(tr("About the album"));
    aboutMsgBox.setText(tr("This is an embeded eletron album:SMPlayer!\n作者：杨召唤\n指导老师：郭猛\n院系：计算机科学与工程学院\n专业：信息管理与信息系统"));
    aboutMsgBox.setIconPixmap(QPixmap("./image/About.png"));
    aboutMsgBox.exec();
}

//clicked image table show the image in the scene
void ImageProcessor::imageTabelClicked()
{
    centralWidget->imageSelectedEvent();
}
