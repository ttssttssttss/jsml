/****************************************************************************
** Meta object code from reading C++ file 'tabwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../tabwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TabWidget_t {
    QByteArrayData data[30];
    char stringdata0[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabWidget_t qt_meta_stringdata_TabWidget = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TabWidget"
QT_MOC_LITERAL(1, 10, 12), // "loadProgress"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "progress"
QT_MOC_LITERAL(4, 33, 12), // "titleChanged"
QT_MOC_LITERAL(5, 46, 5), // "title"
QT_MOC_LITERAL(6, 52, 10), // "urlChanged"
QT_MOC_LITERAL(7, 63, 3), // "url"
QT_MOC_LITERAL(8, 67, 11), // "iconChanged"
QT_MOC_LITERAL(9, 79, 4), // "icon"
QT_MOC_LITERAL(10, 84, 23), // "webActionEnabledChanged"
QT_MOC_LITERAL(11, 108, 25), // "QWebEnginePage::WebAction"
QT_MOC_LITERAL(12, 134, 6), // "action"
QT_MOC_LITERAL(13, 141, 7), // "enabled"
QT_MOC_LITERAL(14, 149, 6), // "setUrl"
QT_MOC_LITERAL(15, 156, 20), // "triggerWebPageAction"
QT_MOC_LITERAL(16, 177, 9), // "createTab"
QT_MOC_LITERAL(17, 187, 8), // "WebView*"
QT_MOC_LITERAL(18, 196, 11), // "makeCurrent"
QT_MOC_LITERAL(19, 208, 8), // "closeTab"
QT_MOC_LITERAL(20, 217, 5), // "index"
QT_MOC_LITERAL(21, 223, 7), // "nextTab"
QT_MOC_LITERAL(22, 231, 11), // "previousTab"
QT_MOC_LITERAL(23, 243, 20), // "handleCurrentChanged"
QT_MOC_LITERAL(24, 264, 26), // "handleContextMenuRequested"
QT_MOC_LITERAL(25, 291, 3), // "pos"
QT_MOC_LITERAL(26, 295, 8), // "cloneTab"
QT_MOC_LITERAL(27, 304, 14), // "closeOtherTabs"
QT_MOC_LITERAL(28, 319, 13), // "reloadAllTabs"
QT_MOC_LITERAL(29, 333, 9) // "reloadTab"

    },
    "TabWidget\0loadProgress\0\0progress\0"
    "titleChanged\0title\0urlChanged\0url\0"
    "iconChanged\0icon\0webActionEnabledChanged\0"
    "QWebEnginePage::WebAction\0action\0"
    "enabled\0setUrl\0triggerWebPageAction\0"
    "createTab\0WebView*\0makeCurrent\0closeTab\0"
    "index\0nextTab\0previousTab\0"
    "handleCurrentChanged\0handleContextMenuRequested\0"
    "pos\0cloneTab\0closeOtherTabs\0reloadAllTabs\0"
    "reloadTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    1,  107,    2, 0x06 /* Public */,
       6,    1,  110,    2, 0x06 /* Public */,
       8,    1,  113,    2, 0x06 /* Public */,
      10,    2,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  121,    2, 0x0a /* Public */,
      15,    1,  124,    2, 0x0a /* Public */,
      16,    1,  127,    2, 0x0a /* Public */,
      16,    0,  130,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  131,    2, 0x0a /* Public */,
      21,    0,  134,    2, 0x0a /* Public */,
      22,    0,  135,    2, 0x0a /* Public */,
      23,    1,  136,    2, 0x08 /* Private */,
      24,    1,  139,    2, 0x08 /* Private */,
      26,    1,  142,    2, 0x08 /* Private */,
      27,    1,  145,    2, 0x08 /* Private */,
      28,    0,  148,    2, 0x08 /* Private */,
      29,    1,  149,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Void, QMetaType::QIcon,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Bool,   12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QUrl,    7,
    QMetaType::Void, 0x80000000 | 11,   12,
    0x80000000 | 17, QMetaType::Bool,   18,
    0x80000000 | 17,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QPoint,   25,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,

       0        // eod
};

void TabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->urlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 3: _t->iconChanged((*reinterpret_cast< const QIcon(*)>(_a[1]))); break;
        case 4: _t->webActionEnabledChanged((*reinterpret_cast< QWebEnginePage::WebAction(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 6: _t->triggerWebPageAction((*reinterpret_cast< QWebEnginePage::WebAction(*)>(_a[1]))); break;
        case 7: { WebView* _r = _t->createTab((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< WebView**>(_a[0]) = std::move(_r); }  break;
        case 8: { WebView* _r = _t->createTab();
            if (_a[0]) *reinterpret_cast< WebView**>(_a[0]) = std::move(_r); }  break;
        case 9: _t->closeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->nextTab(); break;
        case 11: _t->previousTab(); break;
        case 12: _t->handleCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->handleContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 14: _t->cloneTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->closeOtherTabs((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->reloadAllTabs(); break;
        case 17: _t->reloadTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TabWidget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabWidget::loadProgress)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TabWidget::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabWidget::titleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TabWidget::*)(const QUrl & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabWidget::urlChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TabWidget::*)(const QIcon & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabWidget::iconChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TabWidget::*)(QWebEnginePage::WebAction , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TabWidget::webActionEnabledChanged)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TabWidget::staticMetaObject = { {
    &QTabWidget::staticMetaObject,
    qt_meta_stringdata_TabWidget.data,
    qt_meta_data_TabWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TabWidget.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int TabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void TabWidget::loadProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TabWidget::titleChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TabWidget::urlChanged(const QUrl & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TabWidget::iconChanged(const QIcon & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TabWidget::webActionEnabledChanged(QWebEnginePage::WebAction _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
