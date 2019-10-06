#include<iostream>
namespace mystd
{
	using namespace std;

	class ostream
	{
	public:
		ostream& operator<<(const char*str)
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<<(char str)
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator<<(int num)
		{
			printf("%d", num);
			return *this;
		}
		ostream& operator<<(double e)
		{
			printf("%g", e);
			return *this;
		}
		ostream& operator<<(ostream& (*fp)(ostream &ostm))
		{
			fp(*this);
		}
	};

	ostream& endl(ostream &ostm) {
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}

	ostream cout;
}

int main(void)
{
	using mystd::cout;
	using mystd::endl;

	cout << "SImple String";
	cout << endl;
	cout << 3.14;
	cout << endl;
	cout << 123;
	endl(cout);
}
