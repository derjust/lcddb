#include <iostream>
#include <qapplication.h>

#include "fmMain.h"

using namespace std;

int main( int argc, char **argv )
{
	QApplication lcddb( argc, argv );
	qInitNetworkProtocols();
	TfmMain fmMain;
	fmMain.setGeometry( 400, 200, 200, 120 );
	lcddb.setMainWidget( &fmMain );
	lcddb.setFont(QFont("Arial",14));
	fmMain.setCaption("LCDDB 1.0");
	fmMain.show();
	return lcddb.exec();
}
