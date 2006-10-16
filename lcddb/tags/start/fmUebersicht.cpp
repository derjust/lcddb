#include "fmUebersicht.h"

#include "konfig.h"

using namespace std;


TfmUebersicht::TfmUebersicht(QWidget * parent, const char * name, string extquery) : QDialog( parent, name, TRUE )
{
	int Zeilen=0;
	QSqlDatabase *lcddbDB = QSqlDatabase::addDatabase( "QMYSQL3" );
	Konfigs konfig;
	
	lcddbDB->setHostName( konfig.getDBHost() );
	lcddbDB->setDatabaseName( "lcddb" );
	lcddbDB->setUserName( konfig.getDBUser() );
	lcddbDB->setPassword( konfig.getDBPassword() );
	if (!lcddbDB )
	{
		qWarning( "Konnte MySQL-Handler nicht initialisieren" );
		QMessageBox::critical( this, "MySQL-Fehler", "Konnte den MySQK-Handler nicht initialisieren");
	}
	else 
	{
		if( lcddbDB->open() ) 
		{
			QSqlQuery query("SELECT COUNT(*) FROM `Alben` " + extquery);
			qWarning(query.lastQuery());
			if( query.isActive() ) 
			{ 
				query.next();
				Zeilen = StrToInt(query.value( 0 ).toString()); 
			}
		}
	}
	
	setMinimumSize( 500, 500 );
	setMaximumSize( 500, 500 );
	
	setCaption("Übersicht");
	
	lbAlbum = new QLabel(this);
	lbAlbum->setGeometry(5,5,150,30);
	lbAlbum->setText("Alben:");
	
	tAlbum = new QTable(Zeilen,5, this);
	tAlbum->setGeometry(5, 30,490,200);
	
	QHeader *th1 = tAlbum->horizontalHeader();
        th1->setLabel( 0, "Album" );
        th1->setLabel( 1, "Interpret" );
	th1->setLabel( 2, "Format" );
	th1->setLabel( 3, "Jahr" );
	th1->setLabel( 4, "CDID" );
	tAlbum->hideColumn(4);
	
	lbLieder = new QLabel(this);
	lbLieder->setGeometry(5,235,150,30);
	lbLieder->setText("Lieder:");
	
	tLieder = new QTable(0,2, this);
	tLieder->setGeometry(5, 260, 490, 210);
	QHeader *th2 = tLieder->horizontalHeader();
        th2->setLabel( 0, "Lied" );
        th2->setLabel( 1, "Dauer" );
	
	btSchliessen = new QPushButton("&Schliessen", this);
	btSchliessen->setGeometry(375,470, 125,30);
	QIconSet isSchliessen(QPixmap(konfig.getGFXPath()+"/abbrechen.png"));
	btSchliessen->setIconSet(isSchliessen);
	
	LeseAlben(extquery);
	ZeigeLieder(0,0);
	
	connect( btSchliessen, SIGNAL(clicked()), this, SLOT(close()) );
	connect( tAlbum, SIGNAL(currentChanged(int , int )), this, SLOT(ZeigeLieder(int , int )));
}


void TfmUebersicht::ZeigeLieder(int row, int col)
{
	int Zeilen=0;
	int N=0;
	QString DBUser, DBHost, DBPassword;
	QSqlDatabase *lcddbDB = QSqlDatabase::addDatabase( "QMYSQL3" );
	DBHost = "localhost";
	DBUser = "lcddb";
	DBPassword = "lcddb";

	lcddbDB->setHostName( DBHost );
	lcddbDB->setDatabaseName( "lcddb" );
	lcddbDB->setUserName( DBUser );
	lcddbDB->setPassword( DBPassword );
	if (!lcddbDB )
	{
		qWarning( "Konnte MySQL-Handler nicht initialisieren" );
		QMessageBox::critical( this, "MySQL-Fehler", "Konnte den MySQK-Handler nicht initialisieren");
	}
	else 
	{
		if( lcddbDB->open() ) 
		{
			QSqlQuery query("SELECT COUNT(*) FROM `Lieder` WHERE `CDID`='"+(tAlbum->text(row,4))+"' ORDER BY `Nr`");
			if( query.isActive() ) 
			{ 
				query.next();
				Zeilen = StrToInt(query.value( 0 ).toString()); 
			}
		}
		tLieder->setNumRows(Zeilen);
		if (Zeilen > 0)
		{
			QSqlQuery query("SELECT `Lied`, `Dauer` FROM `Lieder` WHERE `CDID`='"+(tAlbum->text(row,4))+"' ORDER BY `Nr`");
			if ( query.isActive() )
			{
				while (query.next() )
				{
					tLieder->setText(N, 0, query.value( 0 ).toString());
					tLieder->setText(N, 1, query.value( 1 ).toString());
					N++;
				}
			}
		}
	}
}

void TfmUebersicht::LeseAlben(string extquery)
{
	QString DBUser, DBHost, DBPassword;
	QSqlDatabase *lcddbDB = QSqlDatabase::addDatabase( "QMYSQL3" );
	QString CDID;
	int N=0;
	/* Daten aus Datei einlesen*/
	DBHost = "localhost";
	DBUser = "lcddb";
	DBPassword = "lcddb";

	lcddbDB->setHostName( DBHost );
	lcddbDB->setDatabaseName( "lcddb" );
	lcddbDB->setUserName( DBUser );
	lcddbDB->setPassword( DBPassword );
	if (!lcddbDB )
	{
		qWarning( "Konnte MySQL-Handler nicht initialisieren" );
		QMessageBox::critical( this, "MySQL-Fehler", "Konnte den MySQK-Handler nicht initialisieren");
	}
	else 
	{
		if( lcddbDB->open() ) 
		{
			QSqlQuery query("SELECT `Album`, `Interpret`, `Format`, `Jahr`, `ID` FROM `Alben` "+extquery+" ORDER BY `Album`");
			qWarning(query.lastQuery());
			if( query.isActive() ) 
			{ 
				while(query.next())
				{
					tAlbum->setText(N, 0, query.value( 0 ).toString()); 
					tAlbum->setText(N, 1, query.value( 1 ).toString()); 
					if ( query.value( 2 ).toString() == "0" )
					{
						tAlbum->setText(N, 2, "Album"); 
					}
					else if ( query.value( 2 ).toString() == "1" )
					{
						tAlbum->setText(N, 2, "Maxi"); 
					}
					else if ( query.value( 2 ).toString() == "2" )
					{
						tAlbum->setText(N, 2, "Single"); 
					}
					else if ( query.value( 2 ).toString() == "3" )
					{
						tAlbum->setText(N, 2, "Venyl"); 
					}
					else if ( query.value( 2 ).toString() == "4" )
					{
						tAlbum->setText(N, 2, "DVD"); 
					}
					tAlbum->setText(N, 3, query.value( 3 ).toString()); 
					tAlbum->setText(N, 4, query.value( 4 ).toString());
					N++;
				}
			}
		}
		else
		{
			QSqlError fehler(lcddbDB->lastError());
			QMessageBox::critical( this, "MySQL-Fehler", "Der Treiber meldet: "+ fehler.driverText() + "\nDie Datenbank meldet: "+fehler.databaseText());
			qWarning("Der Treiber meldet: " + fehler.driverText());
			qWarning("Die Datenbank meldet: " +fehler.databaseText());
		}
	}
}

string TfmUebersicht::IntToStr(int N)
{
stringstream ss;
ss << N;
return ss.str();
}

int TfmUebersicht::StrToInt(string a)
{
	int b;
	stringstream ss(a);
	ss >> b;
	return b;
}
