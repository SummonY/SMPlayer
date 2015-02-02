#include <QRegion>
#include <math.h>

#include "centralwidget.h"

CentralWidget::CentralWidget(QWidget *parent)
    :QWidget(parent)
{
    //set up model and view
    setupModel();
    setupView();

    //set up image scene
    createView();
    createBtns();

    //model layout
    QVBoxLayout *modelViewLayout = new QVBoxLayout;
    modelViewLayout->addWidget(imageTable);
    modelViewLayout->addWidget(musicTable);

    //image process layout
    QVBoxLayout *imageViewLayout = new QVBoxLayout;
    imageViewLayout->addWidget(view);
    imageViewLayout->addWidget(ctrlFrame);

    //central layout
    QHBoxLayout *centralLayout = new QHBoxLayout(this);
    centralLayout->addLayout(modelViewLayout);
    centralLayout->addLayout(imageViewLayout);
}

CentralWidget::~CentralWidget()
{

}

//set up model
void CentralWidget::setupModel()
{
    //image model
    imageModel = new QStandardItemModel();
    imageModel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Image name")));
    imageModel->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Format")));
    imageModel->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Size")));

    //music model
    musicModel = new QStandardItemModel();
    musicModel->setHorizontalHeaderItem(0,new QStandardItem(QObject::tr("Music name")));
    musicModel->setHorizontalHeaderItem(1,new QStandardItem(QObject::tr("Format")));
    musicModel->setHorizontalHeaderItem(2,new QStandardItem(QObject::tr("Size")));
}

//set view
void CentralWidget::setupView()
{
    //image table
    imageTable = new QTableView;
    imageTable->setModel(imageModel);
    imageTable->setSelectionBehavior(QAbstractItemView::SelectRows);            //set select a row

    //music table
    musicTable = new QTableView;
    musicTable->setModel(musicModel);
    musicTable->verticalHeader();
    musicTable->setSelectionBehavior(QAbstractItemView::SelectRows);             //set select a row
}

//create image process buttons
void CentralWidget::createBtns()
{
    QFrame *frame = new QFrame;

    //translate left
    translateLeftBtn = new QPushButton(frame);
    translateLeftBtn->setMaximumSize(37,37);
    translateLeftBtn->setIconSize(QSize(translateLeftBtn->width(),translateLeftBtn->height()));
    translateLeftBtn->setIcon(QIcon("./image/left.png"));
    translateLeftBtn->setToolTip(tr("left translate"));
    connect(translateLeftBtn,SIGNAL(clicked()),this,SLOT(translateLeftAction()));

    //translate right
    translateRightBtn = new QPushButton(frame);
    translateRightBtn->setMaximumSize(37,37);
    translateRightBtn->setIconSize(QSize(translateRightBtn->width(),translateRightBtn->height()));
    translateRightBtn->setIcon(QIcon("./image/right.png"));
    translateRightBtn->setToolTip(tr("right translate"));
    connect(translateRightBtn,SIGNAL(clicked()),this,SLOT(translateRightAction()));

    //translate up
    translateUpBtn = new QPushButton(frame);
    translateUpBtn->setMaximumSize(37,37);
    translateUpBtn->setIconSize(QSize(translateUpBtn->width(),translateUpBtn->height()));
    translateUpBtn->setIcon(QIcon("./image/up.png"));
    translateUpBtn->setToolTip(tr("up translate"));
    connect(translateUpBtn,SIGNAL(clicked()),this,SLOT(translateUpAction()));

    //translate down
    translateDownBtn = new QPushButton(frame);
    translateDownBtn->setMaximumSize(37,37);
    translateDownBtn->setIconSize(QSize(translateDownBtn->width(),translateDownBtn->height()));
    translateDownBtn->setIcon(QIcon("./image/down.png"));
    translateDownBtn->setToolTip(tr("down translate"));
    connect(translateDownBtn,SIGNAL(clicked()),this,SLOT(translateDownAction()));

    //zoom in pushbutton
    zoominBtn = new QPushButton(frame);
    zoominBtn->setMaximumSize(37,37);
    zoominBtn->setIconSize(QSize(zoominBtn->width(),zoominBtn->height()));
    zoominBtn->setIcon(QIcon("./image/zoom_in.png"));
    zoominBtn->setToolTip(tr("zoom in"));
    connect(zoominBtn,SIGNAL(clicked()),this,SLOT(zoominAction()));

    //zoom out pushbutton
    zoomoutBtn = new QPushButton(frame);
    zoomoutBtn->setMaximumSize(37,37);
    zoomoutBtn->setIconSize(QSize(zoomoutBtn->width(),zoomoutBtn->height()));
    zoomoutBtn->setIcon(QIcon("./image/zoom_out.png"));
    zoomoutBtn->setToolTip(tr("zoom out"));
    connect(zoomoutBtn,SIGNAL(clicked()),this,SLOT(zoomoutAction()));

    //left rotate 90
    rotateLeftBtn = new QPushButton(frame);
    rotateLeftBtn->setMaximumSize(37,37);
    rotateLeftBtn->setIconSize(QSize(rotateLeftBtn->width(),rotateLeftBtn->height()));
    rotateLeftBtn->setIcon(QIcon("./image/leftrotate.png"));
    rotateLeftBtn->setToolTip(tr("left rotate 90"));
    connect(rotateLeftBtn,SIGNAL(clicked()),this,SLOT(rotateLeftAction()));

    //right rotate 90
    rotateRightBtn = new QPushButton(frame);
    rotateRightBtn->setMaximumSize(37,37);
    rotateRightBtn->setIconSize(QSize(rotateRightBtn->width(),rotateRightBtn->height()));
    rotateRightBtn->setIcon(QIcon("./image/rightrotate.png"));
    rotateRightBtn->setToolTip(tr("right rotate 90"));
    connect(rotateRightBtn,SIGNAL(clicked()),this,SLOT(rotateRightAction()));

    //shear right
    shearRightBtn = new QPushButton(frame);
    shearRightBtn->setMaximumSize(37,37);
    shearRightBtn->setIconSize(QSize(shearRightBtn->width(),shearRightBtn->height()));
    shearRightBtn->setIcon(QIcon("./image/shearright.png"));
    shearRightBtn->setToolTip(tr("shear upright"));
    connect(shearRightBtn,SIGNAL(clicked()),this,SLOT(shearRigthAction()));

    shearLeftBtn = new QPushButton(frame);
    shearLeftBtn->setMaximumSize(37,37);
    shearLeftBtn->setIconSize(QSize(shearLeftBtn->width(),shearLeftBtn->height()));
    shearLeftBtn->setIcon(QIcon("./image/shearleft.png"));
    shearLeftBtn->setToolTip(tr("shear upleft"));
    connect(shearLeftBtn,SIGNAL(clicked()),this,SLOT(shearLeftAction()));

/*
    //mirror horizontal
    mirrorHorizontalBtn = new QPushButton(frame);
    mirrorHorizontalBtn->setMaximumSize(40,40);
    mirrorHorizontalBtn->setIconSize(QSize(mirrorHorizontalBtn->width(),mirrorHorizontalBtn->height()));
    mirrorHorizontalBtn->setIcon(QIcon("./image/resize-hor.png"));
    mirrorHorizontalBtn->setToolTip(tr("mirror horizontal"));
    connect(mirrorHorizontalBtn,SIGNAL(clicked()),this,SLOT(mirrorHorizontalAction()));

    //mirror vertical
    mirrorVerticalBtn = new QPushButton(frame);
    mirrorVerticalBtn->setMaximumSize(40,40);
    mirrorVerticalBtn->setIconSize(QSize(mirrorVerticalBtn->width(),mirrorVerticalBtn->height()));
    mirrorVerticalBtn->setIcon(QIcon("./image/resize-ver.png"));
    mirrorVerticalBtn->setToolTip(tr("mirror vertical"));
    connect(mirrorVerticalBtn,SIGNAL(clicked()),this,SLOT(mirrorVerticalAction()));
*/
    //button layout
    buttonLayout =new QHBoxLayout(this);
    buttonLayout->addWidget(translateLeftBtn);
    buttonLayout->addWidget(translateRightBtn);
    buttonLayout->addWidget(translateUpBtn);
    buttonLayout->addWidget(translateDownBtn);
    buttonLayout->addWidget(zoominBtn);
    buttonLayout->addWidget(zoomoutBtn);
    buttonLayout->addWidget(rotateLeftBtn);
    buttonLayout->addWidget(rotateRightBtn);
    buttonLayout->addWidget(shearRightBtn);
    buttonLayout->addWidget(shearLeftBtn);
    //buttonLayout->addWidget(mirrorHorizontalBtn);
    //buttonLayout->addWidget(mirrorVerticalBtn);

    ctrlFrame = new QFrame;
    ctrlFrame->setLayout(buttonLayout);
}

//create a QGraphicsView
void CentralWidget::createView()
{
    //set the view and scene
    scene = new QGraphicsScene;
    scene->setSceneRect(QRectF(-30,-30,60,60));
    view = new QGraphicsView;
    view->setScene(scene);

    //show the default image
    QString imageName="./image/search.png";
    QPixmap *pixmap = new QPixmap(imageName);
    pixItem = new PixItem(pixmap);
    scene->addItem(pixItem);
    pixItem->setPos(0,0);
}

//resume the table views
void CentralWidget::resumeTableView()
{
    int imageRows = imageModel->rowCount();
    for(int i=imageRows-1;i>=0;i--)
    {
        imageModel->removeRow(0);
    }
    int musicRows = musicModel->rowCount();
    for(int i=musicRows-1;i>=0;i--)
    {
        musicModel->removeRow(0);
    }
    //have the same function
    //imageModel->removeRows(0,imageModel->rowCount());
    //musicModel->removeRows(0,musicModel->rowCount());
}

//add image table in image model
void CentralWidget::addimageTable(QFileInfo fileInfo)
{
    //get the detail infomation
    QString fileName=fileInfo.fileName();
    QString format = fileInfo.completeSuffix();
    qint64 size = fileInfo.size();

    int row = imageModel->rowCount();
    imageModel->setItem(row,0,new QStandardItem(fileName));
    imageModel->setItem(row,1,new QStandardItem(format));
    imageModel->setItem(row,2,new QStandardItem(QString::number(size)+"  B"));
    imageModel->sort(0,Qt::AscendingOrder);                 //sort image file ascending order

}

//add music table in music model
void CentralWidget::addmusicTable(QFileInfo fileInfo)
{
    //get the music detail infomation
    QString fileName = fileInfo.fileName();
    QString format = fileInfo.suffix();
    qint64 size = fileInfo.size();

    int row = musicModel->rowCount();
    musicModel->setItem(row,0,new QStandardItem(fileName));
    musicModel->setItem(row,1,new QStandardItem(format));
    musicModel->setItem(row,2,new QStandardItem(QString::number(size)+"  B"));

}

//delete the selected row image
void CentralWidget::deleteSeletedImage()
{
    QModelIndex selectedIndex = imageSelectedRow();
    int row;
    if(!selectedIndex.isValid())
        row =-1;
    else
        row = selectedIndex.row();
    imageModel->removeRow(row);
}

//delete the selected row music
void CentralWidget::deleteSeletedMusic()
{
    QModelIndex selectedIndex = musicSelectedRow();
    int row = selectedIndex.row();
    musicModel->removeRow(row);
}

//get the seleted image table row index
QModelIndex CentralWidget::imageSelectedRow()
{
    QItemSelectionModel *selectionModel = imageTable->selectionModel();
    QModelIndex selectedIndex = selectionModel->currentIndex();
    return selectedIndex;
}

//get the selected music table row index
QModelIndex CentralWidget::musicSelectedRow()
{
    QItemSelectionModel *selectionModel = musicTable->selectionModel();
    QModelIndex selectedIndex = selectionModel->currentIndex();
    return selectedIndex;
}

//translate left
void CentralWidget::translateLeftAction()
{
    pixItem->translate(-5,0);
}

//translate right
void CentralWidget::translateRightAction()
{
    pixItem->translate(5,0);
}

//translate up
void CentralWidget::translateUpAction()
{
    pixItem->translate(0,-5);
}

//translate down
void CentralWidget::translateDownAction()
{
    pixItem->translate(0,5);
}

//zoom in the image
void CentralWidget::zoominAction()
{
    qreal s;
    s=pow(1.1,5);
    pixItem->scale(s,s);
}

//zoom out the image
void CentralWidget::zoomoutAction()
{
    qreal s;
    s=pow(1/1.1,5);
    pixItem->scale(s,s);
}

//left rotate 90
void CentralWidget::rotateLeftAction()
{
    pixItem->rotate(-90);
}

//right rotate 90
void CentralWidget::rotateRightAction()
{
    pixItem->rotate(90);
}

//shear upright
void CentralWidget::shearRigthAction()
{
    pixItem->shear(-5/10.0,-5/10.0);
}

//shear upleft
void CentralWidget::shearLeftAction()
{
    pixItem->shear(5/10.0,5/10.0);
}

/*
//mirror horizontal
void CentralWidget::mirrorHorizontalAction()
{
}

//mirror vertica
void CentralWidget::mirrorVerticalAction()
{

}
*/
//image selected event
void CentralWidget::imageSelectedEvent()
{
    int count = imageModel->rowCount();
    if(count>=0)
    {
        //get the current row filename
        QString imageName = getImageName();

        //show the image
        QPixmap *pixmap = new QPixmap(imageName);
        pixItem = new PixItem(pixmap);
        scene->clear();
        scene->addItem(pixItem);
        pixItem->setPos(0,0);
    }
}

//get the current selected row image name
QString CentralWidget::getImageName()
{
    QModelIndex selectedIndex = imageSelectedRow();
    int curRow = selectedIndex.row();
    QModelIndex curIndex = imageTable->model()->index(curRow,0);
    QVariant data = curIndex.data();
    QString imageName ="./image/"+data.toString();
    return imageName;
}

//get the current selected row music name
QString CentralWidget::getMusicName()
{
    QModelIndex selectedIndex = musicSelectedRow();
    int curRow = selectedIndex.row();
    QModelIndex curIndex = musicTable->model()->index(curRow,0);
    QVariant data = curIndex.data();
    QString musicName = "./music/"+data.toString();
    return musicName;
}

//get all the image name in  imagetable
QStringList CentralWidget::getAllImageName(int &num)
{
    QModelIndex modelIndex;
    QStringList allImageName;
    QString imageName;
    num = imageModel->rowCount();
    for(int i=0;i<num;i++)
    {
       modelIndex  = imageTable->model()->index(i,0);
       QVariant data = modelIndex.data();
       imageName = "./image/"+data.toString();
       allImageName << imageName;
    }
    return allImageName;
}

