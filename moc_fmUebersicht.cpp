/****************************************************************************
** TfmUebersicht meta object code from reading C++ file 'fmUebersicht.h'
**
** Created: Sat Feb 5 08:54:39 2005
**      by: The Qt MOC ($Id: moc_fmUebersicht.cpp,v 1.1.1.1 2006-10-16 15:25:18 wodan Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fmUebersicht.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TfmUebersicht::className() const
{
    return "TfmUebersicht";
}

QMetaObject *TfmUebersicht::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TfmUebersicht( "TfmUebersicht", &TfmUebersicht::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TfmUebersicht::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmUebersicht", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TfmUebersicht::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmUebersicht", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TfmUebersicht::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"LeseAlben", 0, 0 };
    static const QUParameter param_slot_1[] = {
	{ "extquery", &static_QUType_ptr, "string", QUParameter::In }
    };
    static const QUMethod slot_1 = {"LeseAlben", 1, param_slot_1 };
    static const QUParameter param_slot_2[] = {
	{ "row", &static_QUType_int, 0, QUParameter::In },
	{ "col", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"ZeigeLieder", 2, param_slot_2 };
    static const QUParameter param_slot_3[] = {
	{ "N", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_3 = {"IntToStr", 1, param_slot_3 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out },
	{ "a", &static_QUType_ptr, "string", QUParameter::In }
    };
    static const QUMethod slot_4 = {"StrToInt", 2, param_slot_4 };
    static const QMetaData slot_tbl[] = {
	{ "LeseAlben()", &slot_0, QMetaData::Public },
	{ "LeseAlben(string)", &slot_1, QMetaData::Public },
	{ "ZeigeLieder(int,int)", &slot_2, QMetaData::Public },
	{ "IntToStr(int)", &slot_3, QMetaData::Public },
	{ "StrToInt(string)", &slot_4, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TfmUebersicht", parentObject,
	slot_tbl, 5,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TfmUebersicht.setMetaObject( metaObj );
    return metaObj;
}

void* TfmUebersicht::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TfmUebersicht" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool TfmUebersicht::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: LeseAlben(); break;
    case 1: LeseAlben((string)(*((string*)static_QUType_ptr.get(_o+1)))); break;
    case 2: ZeigeLieder((int)static_QUType_int.get(_o+1),(int)static_QUType_int.get(_o+2)); break;
    case 3: IntToStr((int)static_QUType_int.get(_o+1)); break;
    case 4: static_QUType_int.set(_o,StrToInt((string)(*((string*)static_QUType_ptr.get(_o+1))))); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TfmUebersicht::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TfmUebersicht::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool TfmUebersicht::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
