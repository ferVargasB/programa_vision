/****************************************************************************
** Meta object code from reading C++ file 'ventanaprincipal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ventanaprincipal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ventanaprincipal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VentanaPrincipal_t {
    QByteArrayData data[12];
    char stringdata0[361];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VentanaPrincipal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VentanaPrincipal_t qt_meta_stringdata_VentanaPrincipal = {
    {
QT_MOC_LITERAL(0, 0, 16), // "VentanaPrincipal"
QT_MOC_LITERAL(1, 17, 31), // "on_actionAbrir_Imagen_triggered"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 36), // "on_actionOperador_Igualdad_tr..."
QT_MOC_LITERAL(4, 87, 35), // "on_actionInverso_Negativo_tri..."
QT_MOC_LITERAL(5, 123, 25), // "on_actionUmbral_triggered"
QT_MOC_LITERAL(6, 149, 33), // "on_actionUmbral_Binario_trigg..."
QT_MOC_LITERAL(7, 183, 43), // "on_actionUmbral_Binario_Inver..."
QT_MOC_LITERAL(8, 227, 30), // "on_actionAbrir_chart_triggered"
QT_MOC_LITERAL(9, 258, 42), // "on_actionUmbral_Escala_de_Gri..."
QT_MOC_LITERAL(10, 301, 28), // "on_actionExtension_triggered"
QT_MOC_LITERAL(11, 330, 30) // "on_actionTranslacion_triggered"

    },
    "VentanaPrincipal\0on_actionAbrir_Imagen_triggered\0"
    "\0on_actionOperador_Igualdad_triggered\0"
    "on_actionInverso_Negativo_triggered\0"
    "on_actionUmbral_triggered\0"
    "on_actionUmbral_Binario_triggered\0"
    "on_actionUmbral_Binario_Invertido_triggered\0"
    "on_actionAbrir_chart_triggered\0"
    "on_actionUmbral_Escala_de_Grises_triggered\0"
    "on_actionExtension_triggered\0"
    "on_actionTranslacion_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VentanaPrincipal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void VentanaPrincipal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VentanaPrincipal *_t = static_cast<VentanaPrincipal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionAbrir_Imagen_triggered(); break;
        case 1: _t->on_actionOperador_Igualdad_triggered(); break;
        case 2: _t->on_actionInverso_Negativo_triggered(); break;
        case 3: _t->on_actionUmbral_triggered(); break;
        case 4: _t->on_actionUmbral_Binario_triggered(); break;
        case 5: _t->on_actionUmbral_Binario_Invertido_triggered(); break;
        case 6: _t->on_actionAbrir_chart_triggered(); break;
        case 7: _t->on_actionUmbral_Escala_de_Grises_triggered(); break;
        case 8: _t->on_actionExtension_triggered(); break;
        case 9: _t->on_actionTranslacion_triggered(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject VentanaPrincipal::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_VentanaPrincipal.data,
      qt_meta_data_VentanaPrincipal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *VentanaPrincipal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VentanaPrincipal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VentanaPrincipal.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VentanaPrincipal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
