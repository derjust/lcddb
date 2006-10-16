#include "fmKonfiguration.h"

#include "konfig.h"

using namespace std;

TfmKonfiguration::TfmKonfiguration(QWidget * parent, const char * name) : QDialog( parent, name, TRUE )
{
	setMinimumSize( 280, 250 );
	setMaximumSize( 280, 250 );
	
	setCaption("Konfiguration");
	
	lbTitel = new QLabel(this);
	lbTitel->setGeometry( 0, 0, 300, 25 );
	lbTitel->setAlignment(Qt::AlignHCenter);
	lbTitel->setText("Konfiguration");
	lbTitel->setFont(QFont("Arial",20));
	
	lbDBHost = new QLabel(this);
	lbDBHost->setGeometry(5, 50, 100, 30);
	lbDBHost->setText("DB-Host:");
	
	teDBHost = new QLineEdit(this);
	teDBHost->setGeometry(110,50,150,30);
	
	lbDBUser = new QLabel(this);
	lbDBUser->setGeometry(5,85,105,30);
	lbDBUser->setText("DB-Username:");
	
	teDBUser = new QLineEdit(this);
	teDBUser->setGeometry(110,85,150,30);
	
	lbDBPassword = new QLabel(this);
	lbDBPassword->setGeometry(5,120,100,30);
	lbDBPassword->setText("DB-Passwort:");
	
	teDBPassword = new QLineEdit(this);
	teDBPassword->setGeometry(110,120,150,30);
	teDBPassword->setEchoMode(QLineEdit::Password);
	
	lbGFXPath = new QLabel(this);
	lbGFXPath->setGeometry(5,160,100,30);
	lbGFXPath->setText("Bilderpfad:");
	
	teGFXPath = new QLineEdit(this);
	teGFXPath->setGeometry(110,160,150,30);
	
	btOK = new QPushButton("&OK", this);
	btOK->setGeometry (195, 220,75,30);
	QIconSet isOK(QPixmap("gfx/ok.png"));
	btOK->setIconSet(isOK);
	
	btAbbrechen = new QPushButton("&Abbrechen", this);
	btAbbrechen->setGeometry(80,220,115,30);
	QIconSet isAbbrechen(QPixmap("gfx/abbrechen.png"));
	btAbbrechen->setIconSet(isAbbrechen);
	
	LadeKonfig();
	
	connect( btOK, SIGNAL(clicked()), this, SLOT(SpeichereKonfig()) );
	connect( btAbbrechen, SIGNAL(clicked()), this, SLOT(close()) );
	
}

void TfmKonfiguration::LadeKonfig()
{
	Konfigs konfig;
	teDBHost->setText(konfig.getDBHost());
	teDBUser->setText(konfig.getDBUser());
	teDBPassword->setText(konfig.getDBPassword());
	teGFXPath->setText(konfig.getGFXPath());
}

void TfmKonfiguration::SpeichereKonfig()
{
	ofstream ofs;
	QString datei="/home/";
	datei.append(getpwuid( getuid())->pw_name);
	datei.append("/.lccb/lccb.cfg");
	ofs.open(datei);
	ofs << teDBHost->text() << endl;
	ofs << teDBUser->text() << endl;
	ofs << teDBPassword->text() << endl;
	ofs << teGFXPath->text() << endl;
	ofs.close();
	this->close();
}
