#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStandardItemModel>
#include <QTableView>
#include <QGroupBox>
#include <QAction>
#include <QFrame>
#include <QPushButton>
#include <QButtonGroup>
#include <QFileInfo>
#include <QModelIndex>
#include <QMouseEvent>
#include <QPixmap>
#include <QStringList>
#include "pixitem.h"

#include "scanwidget.h"

#define MAXIMAGECOUNT 10                    //define array maxnum

class CentralWidget : public QWidget
{
    Q_OBJECT

public:
     QTableView *imageTable;

    CentralWidget(QWidget *parent = 0);
    ~CentralWidget();

    void createView();                                      //create view and scene

    void setupModel();                                      //setup  model
    void setupView();                                       //setup  view

    void deleteSeletedImage();                              //delete the seleted image
    void deleteSeletedMusic();                              //delete the seleted music

    void createToolGroup();                                 //create image process tool group box
    void createBtns();
    void resumeTableView();

    void addimageTable(QFileInfo fileInfo);                         //set up image model
    void addmusicTable(QFileInfo fileInfo);                         //set up music model

    QString getImageName();                                            //get the image table image name
    QString getMusicName();                                            //get the music table music name
    QStringList getAllImageName(int &num);                             //get all the image name

    //select the selected row
    QModelIndex imageSelectedRow();
    QModelIndex musicSelectedRow();

    void imageSelectedEvent();
protected slots:

    void translateLeftAction();                            //actions slots
    void translateRightAction();
    void translateUpAction();
    void translateDownAction();
    void zoominAction();
    void zoomoutAction();
    void rotateRightAction();
    void rotateLeftAction();
    void shearRigthAction();
    void shearLeftAction();
    //void mirrorHorizontalAction();
    //void mirrorVerticalAction();


private:


    QStandardItemModel *imageModel;                         //model
    QStandardItemModel *musicModel;

    QTableView *musicTable;

    QGraphicsView *view;
    QGraphicsScene *scene;                               //scene
    PixItem *pixItem;
    ScanWidget *scanWidget;

    QFrame *ctrlFrame;

    QHBoxLayout *buttonLayout;                         //control the image button layout
    //control the image buttons
    QPushButton *translateLeftBtn;
    QPushButton *translateRightBtn;
    QPushButton *translateUpBtn;
    QPushButton *translateDownBtn;
    QPushButton *zoominBtn;
    QPushButton *zoomoutBtn;
    QPushButton *rotateRightBtn;
    QPushButton *rotateLeftBtn;
    QPushButton *shearRightBtn;
    QPushButton *shearLeftBtn;
    //QPushButton *mirrorHorizontalBtn;
    //QPushButton *mirrorVerticalBtn;

};

#endif // CENTRALWIDGET_H
