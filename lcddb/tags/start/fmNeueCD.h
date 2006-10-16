#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qtable.h>
#include <qstring.h>
#include <sstream>

#include <qnetwork.h>
#include <qsqldriver.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <qmessagebox.h>
#include <qsocket.h>


#include <fcntl.h>
#include <stdarg.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>

#include <linux/cdrom.h>



using namespace std;

class TfmNeueCD : public QDialog
{
Q_OBJECT
private:
	QLabel* lbTitel;
	QLabel* lbAlbum;
	QLabel* lbInterpret;
	QLabel* lbLieder;
	QLabel* lbFormat;
	QLabel* lbJahr;
	
	QPushButton* btOK;
	QPushButton* btCDDB;
	QPushButton* btAbbrechen;
	
	QLineEdit* leAlbum;
	QLineEdit* leJahr;
	QLineEdit* leInterpret;
	
	QComboBox* cbFormat;
	
	QTable* tLieder;
	QSocket* socket;	
	QTextStream* os;
	
	unsigned long discid;
	int tracks;
public:
	TfmNeueCD(QWidget * parent = 0, const char * name = 0);
public slots:
	void Eintragen();
	void CDDB();
	string IntToStr(int N);
	void socketReadyRead();
	
	int read_toc(void);
	unsigned long cddb_discid(int tot_trks);
	unsigned int cddb_sum(int n);
};
