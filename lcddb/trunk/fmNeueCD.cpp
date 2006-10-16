#include "fmNeueCD.h"

#include "konfig.h"

using namespace std;

struct toc 
{
	int min, sec, frame;
} cdtoc[100];

TfmNeueCD::TfmNeueCD(QWidget * parent, const char * name) : QDialog( parent, name, TRUE )
{
	Konfigs konfig;
	setMinimumSize( 450, 450 );
	setMaximumSize( 450, 450 );
	
	setCaption("Neue CD hinzufügen");
	
	lbTitel = new QLabel(this);
	lbTitel->setGeometry( 0, 0, 450, 25 );
	lbTitel->setAlignment(Qt::AlignHCenter);
	lbTitel->setText("Neue CD der Datenbank hinzufügen");
	lbTitel->setFont(QFont("Arial",20));

	lbAlbum = new QLabel(this);
	lbAlbum->setGeometry(5,30,150,30);
	lbAlbum->setText("Album:");
	
	lbInterpret = new QLabel(this);
	lbInterpret->setGeometry(230,30,150,30);
	lbInterpret->setText("Interpret:");
	
	leAlbum = new QLineEdit(this);
	leAlbum->setGeometry(5,60,200,30);
	
	leInterpret = new QLineEdit(this);
	leInterpret->setGeometry(230,60,200,30);
	
	lbFormat = new QLabel(this);
	lbFormat->setGeometry(5,95,150,30);
	lbFormat->setText("Format:");
	
	lbJahr = new QLabel(this);
	lbJahr->setGeometry(230,95,150,30);
	lbJahr->setText("Jahr:");
	
	btCDDB = new QPushButton("&CDDB",this);
	btCDDB->setGeometry(350, 93, 90, 30);
	QIconSet isCDDB(QPixmap(konfig.getGFXPath()+"/cddb.png"));
	btCDDB->setIconSet(isCDDB);
	
	cbFormat = new QComboBox( FALSE, this);
	cbFormat->setGeometry(5,125,100,30);
	cbFormat->insertItem("Album");
	cbFormat->insertItem("Maxi");
	cbFormat->insertItem("Single");
	cbFormat->insertItem("Venyl");
	cbFormat->insertItem("DVD");
	cbFormat->setCurrentItem(0);
	
	leJahr = new QLineEdit(this);
	leJahr->setGeometry(230,125,150,30);
	leJahr->setInputMask("0000");
	
	lbLieder = new QLabel(this);
	lbLieder->setGeometry(5,160,150,30);
	lbLieder->setText("Lieder:");
	
	tLieder = new QTable(50,2,this);
	tLieder->setGeometry(5,190, 440, 255);
	
	QHeader *th = tLieder->horizontalHeader();
        th->setLabel( 0, "Name" );
        th->setLabel( 1, "Länge" );
	
	btOK = new QPushButton("&OK", this);
	btOK->setGeometry(350,157, 90,30);
	QIconSet isOK(QPixmap(konfig.getGFXPath()+"/ok.png"));
	btOK->setIconSet(isOK);
	
	btAbbrechen = new QPushButton("&Abbrechen", this);
	btAbbrechen->setGeometry(235,157,115,30);
	QIconSet isAbbrechen(QPixmap(konfig.getGFXPath()+"/abbrechen.png"));
	btAbbrechen->setIconSet(isAbbrechen);
	
	connect( btOK, SIGNAL(clicked()), this, SLOT(Eintragen()) );
	connect( btAbbrechen, SIGNAL(clicked()), this, SLOT(close()) );
	connect( btCDDB, SIGNAL(clicked()), this, SLOT(CDDB()) );
}

void TfmNeueCD::Eintragen()
{
	QSqlDatabase *lcddbDB = QSqlDatabase::addDatabase( "QMYSQL3" );
	QString CDID;
	int N;
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
			QSqlQuery query("INSERT INTO `Alben` (`ID`, `Album`, `Interpret`, `Format`, `Jahr`) VALUES (NULL, '"+leAlbum->text()+"', '"+leInterpret->text()+"', '"+IntToStr(cbFormat->currentItem()).c_str()+"', '"+leJahr->text()+"')");
			query.exec("SELECT LAST_INSERT_ID()");
			if( query.isActive() ) 
			{
				query.next();
				CDID = query.value( 0 ).toString(); 
			}
			for (N=0;N<=50;N++)
			{
				if ( tLieder->text(N,0) == QString::null)
				{
					break;
				}
				else
				{
					query.exec("INSERT INTO `Lieder` (`ID`, `CDID`, `Nr`, `Lied`, `Dauer`) VALUES (NULL, '"+CDID+"', '"+IntToStr(N+1)+"', '"+tLieder->text(N,0)+"', '"+tLieder->text(N,1)+"')");
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
	this->close();
}

void TfmNeueCD::CDDB()
{
	socket = new QSocket( this );
	socket->connectToHost( "freedb.freedb.org", 8880 );
	
	tracks = read_toc();
	discid = cddb_discid(tracks);
	os = new QTextStream(socket);
	connect( socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()) );

}

void TfmNeueCD::socketReadyRead()
{
	int i=0;	
	QString Antwort="", query="";
	while( socket->canReadLine() ) 
	{
		Antwort.append(socket->readLine() );
	}

	qWarning(Antwort);
	if ((Antwort.find("201")==0))  //Erste Verbindung
	{
		query = "cddb hello lcddbuser myhost lcddb 1";
	}
	else if (Antwort.find("200 Hello and welcome")==0) //Handshake erfolgreich
	{
		query = "cddb query ";
		query.append( QString::number( discid, 16 ) );
		//query.append("b009520e");
		query.append(" ");
		query.append( QString::number( tracks, 10 ) );
		for (i=0; i < tracks; i++)
		{
			query.append(" ");
			query.append( QString::number (cdtoc[i].frame,10));
		}
		query.append(" ");
		query.append(QString::number(cdtoc[tracks].frame / 75,10) );
	}
	else if (Antwort.find("202 No match for disc ID")==0)
	{
		QMessageBox::information( this, "CDDB-Fehler", "Es konnte kein Eintrag in der Datenbank\nfür die CD gefunden werden.");
		socket->close();
		return;
	}

	qWarning(Antwort);
	qWarning(query);
	*os << query << "\n" ;
	
}

string TfmNeueCD::IntToStr(int N)
{
stringstream ss;
ss << N;
return ss.str();
}

unsigned int TfmNeueCD::cddb_sum(int n) 
{
	unsigned int ret;
	ret = 0;
	while (n > 0) 
	{
		ret += (n % 10);
		n /= 10;
	}
	return ret;
}

unsigned long TfmNeueCD::cddb_discid(int tot_trks) 
{
	unsigned int i, t = 0, n = 0;
	i = 0;
	while (i < tot_trks) 
	{
		n = n + cddb_sum((cdtoc[i].min * 60) + cdtoc[i].sec);
		i++;
	}
	t = ((cdtoc[tot_trks].min * 60) + cdtoc[tot_trks].sec) -
	((cdtoc[0].min * 60) + cdtoc[0].sec);
	return ((n % 0xff) << 24 | t << 8 | tot_trks);
}


int TfmNeueCD::read_toc(void) {
	int drive = open("/dev/cdrom", O_RDONLY | O_NONBLOCK);
	struct cdrom_tochdr tochdr;
	struct cdrom_tocentry tocentry;
	int i;
	
	ioctl(drive, CDROMREADTOCHDR, &tochdr);
	for (i = tochdr.cdth_trk0; i <= tochdr.cdth_trk1; i++) 
	{
		tocentry.cdte_track = i;
		tocentry.cdte_format = CDROM_MSF;
		ioctl(drive, CDROMREADTOCENTRY, &tocentry);
		cdtoc[i-1].min = tocentry.cdte_addr.msf.minute;
		cdtoc[i-1].sec = tocentry.cdte_addr.msf.second;
		cdtoc[i-1].frame = tocentry.cdte_addr.msf.frame;
		cdtoc[i-1].frame += cdtoc[i-1].min*60*75;
		cdtoc[i-1].frame += cdtoc[i-1].sec*75;
	}
	tocentry.cdte_track = 0xAA;
	tocentry.cdte_format = CDROM_MSF;
	ioctl(drive, CDROMREADTOCENTRY, &tocentry);
	cdtoc[tochdr.cdth_trk1].min = tocentry.cdte_addr.msf.minute;
	cdtoc[tochdr.cdth_trk1].sec = tocentry.cdte_addr.msf.second;
	cdtoc[tochdr.cdth_trk1].frame = tocentry.cdte_addr.msf.frame;
	cdtoc[tochdr.cdth_trk1].frame += cdtoc[tochdr.cdth_trk1].min*60*75;
	cdtoc[tochdr.cdth_trk1].frame += cdtoc[tochdr.cdth_trk1].sec*75;
	close(drive);
	return tochdr.cdth_trk1;
}
