/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created: Tue Sep 10 09:53:31 2019
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Widget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      39,    7,    7,    7, 0x0a,
      71,    7,    7,    7, 0x0a,
     103,    7,    7,    7, 0x0a,
     113,    7,    7,    7, 0x0a,
     122,    7,    7,    7, 0x0a,
     137,  131,    7,    7, 0x0a,
     151,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Widget[] = {
    "Widget\0\0on_pushButtonConnect_clicked()\0"
    "on_pushButtonConnect_clicked1()\0"
    "on_pushButtonConnect_clicked2()\0"
    "kuaijin()\0houtui()\0update()\0value\0"
    "setValue(int)\0onCurrentLineHighLight()\0"
};

const QMetaObject Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Widget,
      qt_meta_data_Widget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Widget))
        return static_cast<void*>(const_cast< Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_pushButtonConnect_clicked(); break;
        case 1: on_pushButtonConnect_clicked1(); break;
        case 2: on_pushButtonConnect_clicked2(); break;
        case 3: kuaijin(); break;
        case 4: houtui(); break;
        case 5: update(); break;
        case 6: setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: onCurrentLineHighLight(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
