#include "konfig.h"

using namespace std;

Konfigs::Konfigs()
{
	ifstream ifs;
	string TEMP;
	QString datei="/home/";
	datei.append(getpwuid( getuid())->pw_name);
	datei.append("/.lccb/lccb.cfg");
 	ifs.open(datei);
	if (ifs.is_open())
	{ 
		ifs >> myDBHost;
		ifs >> myDBUser;
		ifs >> myDBPassword;
		ifs >> myGFXPath;
	 	ifs.close();
	}
	else
	{
		myDBHost = "localhost";
		myDBUser = "lcddb";
		myDBPassword = "lcddb";
		myGFXPath = "/home/";
		myGFXPath.append(getpwuid( getuid())->pw_name);
		myGFXPath.append("/.lcddb/gfx");
	}
}

string Konfigs::getDBHost()
{
	return myDBHost;
}

string Konfigs::getDBUser()
{
	return myDBUser;
}

string Konfigs::getDBPassword()
{
	return myDBPassword;
}

string Konfigs::getGFXPath()
{
	return myGFXPath;
}
