#include <QtGui/QApplication>
#include <QSplashScreen>
#include <QTextCodec>
#include "imageprocessor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Player");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QPixmap pixmap("./image/aboutalbum.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    ImageProcessor w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
