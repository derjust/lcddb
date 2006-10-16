/****************************************************************************
** TfmMain meta object code from reading C++ file 'fmMain.h'
**
** Created: Sat Feb 5 08:54:29 2005
**      by: The Qt MOC ($Id: moc_fmMain.cpp,v 1.1.1.1 2006-10-16 15:25:18 wodan Exp $)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#undef QT_NO_COMPAT
#include "fmMain.h"
#include <qmetaobject.h>
#include <qapplication.h>

#include <private/qucomextra_p.h>
#if !defined(Q_MOC_OUTPUT_REVISION) || (Q_MOC_OUTPUT_REVISION != 26)
#error "This file was generated using the moc from 3.3.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

const char *TfmMain::className() const
{
    return "TfmMain";
}

QMetaObject *TfmMain::metaObj = 0;
static QMetaObjectCleanUp cleanUp_TfmMain( "TfmMain", &TfmMain::staticMetaObject );

#ifndef QT_NO_TRANSLATION
QString TfmMain::tr( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmMain", s, c, QApplication::DefaultCodec );
    else
	return QString::fromLatin1( s );
}
#ifndef QT_NO_TRANSLATION_UTF8
QString TfmMain::trUtf8( const char *s, const char *c )
{
    if ( qApp )
	return qApp->translate( "TfmMain", s, c, QApplication::UnicodeUTF8 );
    else
	return QString::fromUtf8( s );
}
#endif // QT_NO_TRANSLATION_UTF8

#endif // QT_NO_TRANSLATION

QMetaObject* TfmMain::staticMetaObject()
{
    if ( metaObj )
	return metaObj;
    QMetaObject* parentObject = QWidget::staticMetaObject();
    static const QUMethod slot_0 = {"NeueCD_show", 0, 0 };
    static const QUMethod slot_1 = {"Suchen_show", 0, 0 };
    static const QUMethod slot_2 = {"Uebersicht_show", 0, 0 };
    static const QUMethod slot_3 = {"Konfiguration_show", 0, 0 };
    static const QMetaData slot_tbl[] = {
	{ "NeueCD_show()", &slot_0, QMetaData::Public },
	{ "Suchen_show()", &slot_1, QMetaData::Public },
	{ "Uebersicht_show()", &slot_2, QMetaData::Public },
	{ "Konfiguration_show()", &slot_3, QMetaData::Public }
    };
    metaObj = QMetaObject::new_metaobject(
	"TfmMain", parentObject,
	slot_tbl, 4,
	0, 0,
#ifndef QT_NO_PROPERTIES
	0, 0,
	0, 0,
#endif // QT_NO_PROPERTIES
	0, 0 );
    cleanUp_TfmMain.setMetaObject( metaObj );
    return metaObj;
}

void* TfmMain::qt_cast( const char* clname )
{
    if ( !qstrcmp( clname, "TfmMain" ) )
	return this;
    return QWidget::qt_cast( clname );
}

bool TfmMain::qt_invoke( int _id, QUObject* _o )
{
    switch ( _id - staticMetaObject()->slotOffset() ) {
    case 0: NeueCD_show(); break;
    case 1: Suchen_show(); break;
    case 2: Uebersicht_show(); break;
    case 3: Konfiguration_show(); break;
    default:
	return QWidget::qt_invoke( _id, _o );
    }
    return TRUE;
}

bool TfmMain::qt_emit( int _id, QUObject* _o )
{
    return QWidget::qt_emit(_id,_o);
}
#ifndef QT_NO_PROPERTIES

bool TfmMain::qt_property( int id, int f, QVariant* v)
{
    return QWidget::qt_property( id, f, v);
}

bool TfmMain::qt_static_property( QObject* , int , int , QVariant* ){ return FALSE; }
#endif // QT_NO_PROPERTIES
