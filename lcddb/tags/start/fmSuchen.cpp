#include "fmSuchen.h"

#include "fmUebersicht.h"
#include "konfig.h"

using namespace std;

TfmSuchen::TfmSuchen(QWidget * parent, const char * name) : QDialog( parent, name, TRUE )
{
	Konfigs konfig;
	setMinimumSize( 450, 200 );
	setMaximumSize( 450, 200 );
	
	setCaption("Datenbank durchsuchen");
	
	lbTitel = new QLabel(this);
	lbTitel->setGeometry( 0, 0, 450, 25 );
	lbTitel->setAlignment(Qt::AlignHCenter);
	lbTitel->setText("Datenbank nach einem Album/Lied durchsuchen");
	lbTitel->setFont(QFont("Arial",20));

	lbInterpret = new QLabel(this);
	lbInterpret->setGeometry(5,30,150,30);
	lbInterpret->setText("Interpret:");
	
	lbAlbum = new QLabel(this);
	lbAlbum->setGeometry(230,30,150,30);
	lbAlbum->setText("Album:");
	
	leInterpret = new QLineEdit(this);
	leInterpret->setGeometry(5,55,200,30);
	leInterpret->setText("");
	
	leAlbum = new QLineEdit(this);
	leAlbum->setGeometry(230,55,200,30);
	
	lbLied = new QLabel(this);
	lbLied->setGeometry(5,100,150,30);
	lbLied->setText("Lied:");
	
	lbFormat = new QLabel(this);
	lbFormat->setGeometry(230,100,100,30);
	lbFormat->setText("Format:");
	
	lbJahr = new QLabel(this);
	lbJahr->setGeometry(350, 100,100,30);
	lbJahr->setText("Jahr:");
	
	leLied = new QLineEdit(this);
	leLied->setGeometry(5,125,200,30);
	
	leJahr = new QLineEdit(this);
	leJahr->setGeometry(350,125,100,30);
	leJahr->setInputMask("0000");
	
	cbFormat = new QComboBox( FALSE, this);
	cbFormat->setGeometry(230,125,100,30);
	cbFormat->insertItem("Album");
	cbFormat->insertItem("Maxi");
	cbFormat->insertItem("Single");
	cbFormat->insertItem("Venyl");
	cbFormat->insertItem("DVD");
	cbFormat->insertItem("*");
	cbFormat->setCurrentItem(5);
	
	btSuchen = new QPushButton("&Suchen", this);
	btSuchen->setGeometry(345,160, 100,30);
	QIconSet isSuchen(QPixmap(konfig.getGFXPath()+"/suchen.png"));
	btSuchen->setIconSet(isSuchen);
	
	btAbbrechen = new QPushButton("&Abbrechen", this);
	btAbbrechen->setGeometry(225,160,115,30);
	QIconSet isAbbrechen(QPixmap(konfig.getGFXPath()+"/abbrechen.png"));
	btAbbrechen->setIconSet(isAbbrechen);
	
	connect( btSuchen, SIGNAL(clicked()), this, SLOT(Suchen()) );
	connect( btAbbrechen, SIGNAL(clicked()), this, SLOT(close()) );
}

void TfmSuchen::Suchen()
{
	QString query, alteID, temp;
	QSqlDatabase *lcddbDB = QSqlDatabase::addDatabase( "QMYSQL3" );
	Konfigs konfig;
	lcddbDB->setHostName( konfig.getDBHost() );
	lcddbDB->setDatabaseName( "lcddb" );
	lcddbDB->setUserName( konfig.getDBUser() );
	lcddbDB->setPassword( konfig.getDBPassword() );
	
	query = " WHERE  `Interpret` LIKE '%%";
 	query.append( leInterpret->text() );
	query.append("%%'");

	query.append(" AND `Album` LIKE '%%");
	query.append(leAlbum->text() );
	query.append("%%'");

	query.append(" AND `Jahr` LIKE '%%");
	query.append(leJahr->text() );
	query.append("%%'");
	
	if (cbFormat->currentItem() != 5)
	{
		query.append(" AND `Format` LIKE '%%");
		query.append(cbFormat->currentItem() );
		query.append("%%'");
	}

	if (leLied->text() != "")
	{
		if (!lcddbDB )
		{
			qWarning( "Konnte MySQL-Handler nicht initialisieren" );
			QMessageBox::critical( this, "MySQL-Fehler", "Konnte den MySQK-Handler nicht initialisieren");
		}
		else 
		{
			if( lcddbDB->open() ) 
			{
				QSqlQuery sqlquery("SELECT `CDID` FROM `Lieder` WHERE `Lied` LIKE '%%"+leLied->text()+"%%'");
				query.append(" AND ");
				if( sqlquery.isActive() ) 
				{ 
					sqlquery.next();
					query.append("`ID` = '"+sqlquery.value(0).toString()+"'");
					alteID = sqlquery.value(0).toString();
					while (sqlquery.next())
					{
						if (alteID != sqlquery.value(0).toString())
						{
							query.append(" OR `ID` = '"+sqlquery.value(0).toString()+"'");
							alteID = sqlquery.value(0).toString();
						}
					}
				}
			}
		}
	}

	TfmUebersicht* fmUebersicht;
	fmUebersicht = new TfmUebersicht(0,"",query);
	fmUebersicht->show();

	this->close();

}
