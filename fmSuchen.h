#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qmessagebox.h>
#include <qcombobox.h>

using namespace std;

class TfmSuchen : public QDialog
{
Q_OBJECT
private:
	QLabel* lbTitel;
	QLabel* lbAlbum;
	QLabel* lbLied;
	QLabel* lbInterpret;
	QLabel* lbJahr;
	QLabel* lbFormat;
	
	QPushButton* btSuchen;
	QPushButton* btAbbrechen;
	
	QLineEdit* leAlbum;
	QLineEdit* leLied;
	QLineEdit* leInterpret;
	QLineEdit* leJahr;
	
	QComboBox* cbFormat;
	
public:
	TfmSuchen(QWidget * parent = 0, const char * name = 0);
public slots:
	void Suchen();
};
