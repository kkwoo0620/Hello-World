#include"BankingCommonDec1.h"

class String
{
private:
	int len;
	char * str;
public:
	String();
	String(const char * s);
	~String();
	String(const String& sub);
	String& operator=(const String& sub);
	String& operator+=(const String& sub);
	bool operator==(const String& sub);
	String operator+(const String& sub);
	friend ostream& operator<<(ostream& os, String& sub);
	friend istream& operator>>(istream& is, String& sub);
};

