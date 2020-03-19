/****************************************************************************
** Meta object code from reading C++ file 'browserwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../browserwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browserwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BrowserWindow_t {
    QByteArrayData data[16];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrowserWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrowserWindow_t qt_meta_stringdata_BrowserWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BrowserWindow"
QT_MOC_LITERAL(1, 14, 23), // "handleFileOpenTriggered"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 25), // "handleShowWindowTriggered"
QT_MOC_LITERAL(4, 65, 25), // "handleWebViewTitleChanged"
QT_MOC_LITERAL(5, 91, 5), // "title"
QT_MOC_LITERAL(6, 97, 23), // "handleComboIndexChanged"
QT_MOC_LITERAL(7, 121, 4), // "text"
QT_MOC_LITERAL(8, 126, 23), // "handleWebViewUrlChanged"
QT_MOC_LITERAL(9, 150, 3), // "url"
QT_MOC_LITERAL(10, 154, 24), // "handleWebViewIconChanged"
QT_MOC_LITERAL(11, 179, 4), // "icon"
QT_MOC_LITERAL(12, 184, 29), // "handleWebActionEnabledChanged"
QT_MOC_LITERAL(13, 214, 25), // "QWebEnginePage::WebAction"
QT_MOC_LITERAL(14, 240, 6), // "action"
QT_MOC_LITERAL(15, 247, 7) // "enabled"

    },
    "BrowserWindow\0handleFileOpenTriggered\0"
    "\0handleShowWindowTriggered\0"
    "handleWebViewTitleChanged\0title\0"
    "handleComboIndexChanged\0text\0"
    "handleWebViewUrlChanged\0url\0"
    "handleWebViewIconChanged\0icon\0"
    "handleWebActionEnabledChanged\0"
    "QWebEnginePage::WebAction\0action\0"
    "enabled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrowserWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      12,    2,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QUrl,    9,
    QMetaType::Void, QMetaType::QIcon,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Bool,   14,   15,

       0        // eod
};

void BrowserWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BrowserWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleFileOpenTriggered(); break;
        case 1: _t->handleShowWindowTriggered(); break;
        case 2: _t->handleWebViewTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->handleComboIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->handleWebViewUrlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: _t->handleWebViewIconChanged((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 6: _t->handleWebActionEnabledChanged((*reinterpret_cast< QWebEnginePage::WebAction(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BrowserWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_BrowserWindow.data,
    qt_meta_data_BrowserWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BrowserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrowserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BrowserWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BrowserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
