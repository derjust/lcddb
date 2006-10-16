#include <fstream>
#include <string>
#include <qstring.h>
#include <unistd.h>
#include <pwd.h>

using namespace std;

class Konfigs
{
private:
	string myDBHost;
	string myDBUser;
	string myDBPassword;
	string myGFXPath;
public:
	Konfigs();
	string getDBHost();
	string getDBUser();
	string getDBPassword();
	string getGFXPath();
};
