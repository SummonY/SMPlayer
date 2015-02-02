/****************************************************************************
** Meta object code from reading C++ file 'imageprocessor.h'
**
** Created: Tue May 21 22:27:47 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imageprocessor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ImageProcessor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x09,
      36,   15,   15,   15, 0x09,
      47,   15,   15,   15, 0x09,
      58,   15,   15,   15, 0x09,
      73,   15,   15,   15, 0x09,
      86,   15,   15,   15, 0x09,
     100,   15,   15,   15, 0x09,
     114,   15,   15,   15, 0x09,
     127,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ImageProcessor[] = {
    "ImageProcessor\0\0imageTabelClicked()\0"
    "addImage()\0addMusic()\0resumeWindow()\0"
    "exitWindow()\0deleteImage()\0deleteMusic()\0"
    "scanEffect()\0showAbout()\0"
};

const QMetaObject ImageProcessor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImageProcessor,
      qt_meta_data_ImageProcessor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ImageProcessor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ImageProcessor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ImageProcessor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageProcessor))
        return static_cast<void*>(const_cast< ImageProcessor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImageProcessor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: imageTabelClicked(); break;
        case 1: addImage(); break;
        case 2: addMusic(); break;
        case 3: resumeWindow(); break;
        case 4: exitWindow(); break;
        case 5: deleteImage(); break;
        case 6: deleteMusic(); break;
        case 7: scanEffect(); break;
        case 8: showAbout(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
