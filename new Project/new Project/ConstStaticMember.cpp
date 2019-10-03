#include<iostream>
using std::cout;
using std::endl;

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;
};

int main()
{
	cout << "러시아 면적: " << CountryArea::RUSSIA << endl;
}