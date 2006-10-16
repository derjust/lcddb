/****************************************************************************
** TfmSuchen meta object code from reading C++ file 'fmSuchen.h'
**
** Created: Sat Feb 5 08:54:36 2005
**      by: The Qt MOC ($Id: moc_fmSuchen.cpp,v 1.1.1.1 2006-10-16 15:25:18 wodan Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fmSuchen.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TfmSuchen::className() const
{
    return "TfmSuchen";
}

QMetaObject *TfmSuchen::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TfmSuchen( "TfmSuchen", &TfmSuchen::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TfmSuchen::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmSuchen", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TfmSuchen::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmSuchen", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TfmSuchen::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"Suchen", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "Suchen()", &slot_0, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TfmSuchen", parentObject,
	slot_tbl, 1,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TfmSuchen.setMetaObject( metaObj );
    return metaObj;
}

void* TfmSuchen::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TfmSuchen" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool TfmSuchen::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Suchen(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TfmSuchen::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TfmSuchen::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool TfmSuchen::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
