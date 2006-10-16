/****************************************************************************
** TfmKonfiguration meta object code from reading C++ file 'fmKonfiguration.h'
**
** Created: Sat Feb 5 08:54:26 2005
**      by: The Qt MOC ($Id: moc_fmKonfiguration.cpp,v 1.1.1.1 2006-10-16 15:25:18 wodan Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fmKonfiguration.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TfmKonfiguration::className() const
{
    return "TfmKonfiguration";
}

QMetaObject *TfmKonfiguration::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TfmKonfiguration( "TfmKonfiguration", &TfmKonfiguration::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TfmKonfiguration::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmKonfiguration", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TfmKonfiguration::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmKonfiguration", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TfmKonfiguration::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"LadeKonfig", 0, 0 };
    static const QUMethod slot_1 = {"SpeichereKonfig", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "LadeKonfig()", &slot_0, QMetaData::Public },
	{ "SpeichereKonfig()", &slot_1, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TfmKonfiguration", parentObject,
	slot_tbl, 2,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TfmKonfiguration.setMetaObject( metaObj );
    return metaObj;
}

void* TfmKonfiguration::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TfmKonfiguration" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool TfmKonfiguration::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: LadeKonfig(); break;
    case 1: SpeichereKonfig(); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TfmKonfiguration::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TfmKonfiguration::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool TfmKonfiguration::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
