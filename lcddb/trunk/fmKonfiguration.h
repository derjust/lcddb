#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <fstream>
#include <qstring.h>

using namespace std;

class TfmKonfiguration : public QDialog
{
Q_OBJECT
private:
	QLabel* lbTitel;
	QLabel* lbDBHost;
	QLineEdit* teDBHost;
	QLabel* lbDBUser;
	QLineEdit* teDBUser;
	QLabel* lbDBPassword;
	QLineEdit* teDBPassword;
	QLabel* lbGFXPath;
	QLineEdit* teGFXPath;
	QPushButton* btOK;
	QPushButton* btAbbrechen;
public:
	TfmKonfiguration(QWidget * parent = 0, const char * name = 0);
public slots:
	void LadeKonfig();
	void SpeichereKonfig();
};
