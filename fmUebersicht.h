#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qtable.h>
#include <sstream>

#include <qmessagebox.h>
#include <qnetwork.h>
#include <qsqldriver.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

using namespace std;

class TfmUebersicht : public QDialog
{
Q_OBJECT
private:
	QLabel* lbAlbum;
	QLabel* lbLieder;
	
	QPushButton* btSchliessen;
	
	QTable* tAlbum;
	QTable* tLieder;
	
public:
	TfmUebersicht(QWidget * parent = 0, const char * name = 0 , string extquery = "");
public slots:
	void LeseAlben(string extquery="");
	void ZeigeLieder(int row, int col);
	string IntToStr(int N);
	int StrToInt(string a);
};
