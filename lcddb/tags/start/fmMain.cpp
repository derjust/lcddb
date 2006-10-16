#include "fmMain.h"

#include "konfig.h"

using namespace std;

TfmMain::TfmMain( QWidget *parent, const char *name ) : QWidget( parent, name )
{
	Konfigs konfig;
	setMinimumSize( 300, 340 );
	setMaximumSize( 300, 340 );
	
	lbTitel = new QLabel(this);
	lbTitel->setGeometry( 0, 0, 300, 25 );
	lbTitel->setAlignment(Qt::AlignHCenter);
	lbTitel->setText("LCCDB");
	lbTitel->setFont(QFont("Arial",26));

	lbTitel2 = new QLabel(this);
	lbTitel2->setGeometry( 0, 25, 300, 25 );
	lbTitel2->setAlignment(Qt::AlignHCenter);
	lbTitel2->setText("Die lokale CompactDisk-Datenbank");
	lbTitel2->setFont(QFont("Arial",14));
	
	btNeueCD = new QPushButton("&Neue CD hinzfügen",this);
	btNeueCD->setGeometry (10,50,280,50);
	QIconSet isNeueCD(QPixmap(konfig.getGFXPath()+"/neuecd.png"));
	btNeueCD->setIconSet(isNeueCD);
	 
	btSuchen = new QPushButton("&Suchen",this);
	btSuchen->setGeometry (10, 125,280,50);
	QIconSet isSuchen(QPixmap(konfig.getGFXPath()+"/suchen.png"));
	btSuchen->setIconSet(isSuchen);
	 
	btUebersicht = new QPushButton("&komplette Übersicht", this);
	btUebersicht->setGeometry (10, 200,280,50);
	QIconSet isUebersicht( QPixmap(konfig.getGFXPath()+"/uebersicht.png") );
	btUebersicht->setIconSet(isUebersicht);
	
	 
	btKonfiguration = new QPushButton("&Einstellungen",this);
	btKonfiguration->setGeometry (10, 275,135,50);
	QIconSet isEinstellungen(QPixmap(konfig.getGFXPath()+"/einstellungen.png"));
	btKonfiguration->setIconSet(isEinstellungen);
	
	btEnde = new QPushButton("En&de", this);
	btEnde->setGeometry(155,275, 135, 50);
	QIconSet isEnde(QPixmap(konfig.getGFXPath()+"/abbrechen.png"));
	btEnde->setIconSet(isEnde);
	

	connect( btNeueCD, SIGNAL(clicked()), this, SLOT(NeueCD_show()) );
	connect( btSuchen, SIGNAL(clicked()), this, SLOT(Suchen_show()) );
	connect( btUebersicht, SIGNAL(clicked()), this, SLOT(Uebersicht_show()) );
	connect( btKonfiguration, SIGNAL(clicked()), this, SLOT(Konfiguration_show()) );
	connect( btEnde, SIGNAL(clicked()), this, SLOT(close() ) );
}

void TfmMain::NeueCD_show()
{
	TfmNeueCD* fmNeueCD;
	fmNeueCD = new TfmNeueCD();
	fmNeueCD->show();
}

void TfmMain::Suchen_show()
{
	TfmSuchen* fmSuchen;
	fmSuchen = new TfmSuchen();
	fmSuchen->show();
}

void TfmMain::Uebersicht_show()
{
	TfmUebersicht* fmUebersicht;
	fmUebersicht = new TfmUebersicht();
	fmUebersicht->show();
}

void TfmMain::Konfiguration_show()
{
	TfmKonfiguration* fmKonfiguration;
	fmKonfiguration = new TfmKonfiguration();
	fmKonfiguration->show();
}
