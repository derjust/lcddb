/****************************************************************************
** TfmNeueCD meta object code from reading C++ file 'fmNeueCD.h'
**
** Created: Sat Feb 5 08:54:32 2005
**      by: The Qt MOC ($Id: moc_fmNeueCD.cpp,v 1.1.1.1 2006-10-16 15:25:18 wodan Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fmNeueCD.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TfmNeueCD::className() const
{
    return "TfmNeueCD";
}

QMetaObject *TfmNeueCD::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TfmNeueCD( "TfmNeueCD", &TfmNeueCD::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TfmNeueCD::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmNeueCD", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TfmNeueCD::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmNeueCD", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TfmNeueCD::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QDialog::staticMetaObject();
    static const QUMethod slot_0 = {"Eintragen", 0, 0 };
    static const QUMethod slot_1 = {"CDDB", 0, 0 };
    static const QUParameter param_slot_2[] = {
	{ "N", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_2 = {"IntToStr", 1, param_slot_2 };
    static const QUMethod slot_3 = {"socketReadyRead", 0, 0 };
    static const QUParameter param_slot_4[] = {
	{ 0, &static_QUType_int, 0, QUParameter::Out }
    };
    static const QUMethod slot_4 = {"read_toc", 1, param_slot_4 };
    static const QUParameter param_slot_5[] = {
	{ "tot_trks", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_5 = {"cddb_discid", 1, param_slot_5 };
    static const QUParameter param_slot_6[] = {
	{ "n", &static_QUType_int, 0, QUParameter::In }
    };
    static const QUMethod slot_6 = {"cddb_sum", 1, param_slot_6 };
    static const QMetaData slot_tbl[] = {
	{ "Eintragen()", &slot_0, QMetaData::Public },
	{ "CDDB()", &slot_1, QMetaData::Public },
	{ "IntToStr(int)", &slot_2, QMetaData::Public },
	{ "socketReadyRead()", &slot_3, QMetaData::Public },
	{ "read_toc()", &slot_4, QMetaData::Public },
	{ "cddb_discid(int)", &slot_5, QMetaData::Public },
	{ "cddb_sum(int)", &slot_6, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TfmNeueCD", parentObject,
	slot_tbl, 7,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TfmNeueCD.setMetaObject( metaObj );
    return metaObj;
}

void* TfmNeueCD::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TfmNeueCD" ) )
	return this;
    return QDialog::qt_cast( clname );
}

bool TfmNeueCD::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: Eintragen(); break;
    case 1: CDDB(); break;
    case 2: IntToStr((int)static_QUType_int.get(_o+1)); break;
    case 3: socketReadyRead(); break;
    case 4: static_QUType_int.set(_o,read_toc()); break;
    case 5: cddb_discid((int)static_QUType_int.get(_o+1)); break;
    case 6: cddb_sum((int)static_QUType_int.get(_o+1)); break;
    default:
	return QDialog::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TfmNeueCD::qt_emit( int _id, QUObject* _o )
{
    return QDialog::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TfmNeueCD::qt_property( int id, int f, QVariant* v)
{
    return QDialog::qt_property( id, f, v);
}

bool TfmNeueCD::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
