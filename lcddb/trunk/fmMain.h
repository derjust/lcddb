#include <qlabel.h>
#include <qpushbutton.h>

#include "fmKonfiguration.h"
#include "fmNeueCD.h"
#include "fmSuchen.h"
#include "fmUebersicht.h"

using namespace std;

class TfmMain : public QWidget
{
Q_OBJECT
private:
	QLabel* lbTitel;
	QLabel* lbTitel2;
	QPushButton* btNeueCD;
	QPushButton* btSuchen;
	QPushButton* btUebersicht;
	QPushButton* btKonfiguration;
	QPushButton* btEnde;
public slots:
	void NeueCD_show();
	void Suchen_show();
	void Uebersicht_show();
	void Konfiguration_show();
public:
	TfmMain( QWidget *parent=0, const char *name=0 ); 
};
