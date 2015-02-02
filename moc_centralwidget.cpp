/****************************************************************************
** Meta object code from reading C++ file 'centralwidget.h'
**
** Created: Tue May 21 22:27:48 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "centralwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'centralwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CentralWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x09,
      37,   14,   14,   14, 0x09,
      60,   14,   14,   14, 0x09,
      80,   14,   14,   14, 0x09,
     102,   14,   14,   14, 0x09,
     117,   14,   14,   14, 0x09,
     133,   14,   14,   14, 0x09,
     153,   14,   14,   14, 0x09,
     172,   14,   14,   14, 0x09,
     191,   14,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CentralWidget[] = {
    "CentralWidget\0\0translateLeftAction()\0"
    "translateRightAction()\0translateUpAction()\0"
    "translateDownAction()\0zoominAction()\0"
    "zoomoutAction()\0rotateRightAction()\0"
    "rotateLeftAction()\0shearRigthAction()\0"
    "shearLeftAction()\0"
};

const QMetaObject CentralWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CentralWidget,
      qt_meta_data_CentralWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CentralWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CentralWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CentralWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CentralWidget))
        return static_cast<void*>(const_cast< CentralWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CentralWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: translateLeftAction(); break;
        case 1: translateRightAction(); break;
        case 2: translateUpAction(); break;
        case 3: translateDownAction(); break;
        case 4: zoominAction(); break;
        case 5: zoomoutAction(); break;
        case 6: rotateRightAction(); break;
        case 7: rotateLeftAction(); break;
        case 8: shearRigthAction(); break;
        case 9: shearLeftAction(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
