#include<iostream>
using std::cout;
using std::endl;

template<class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

template<>
char* Max(char* a, char* b) {
	return strlen(a) > strlen(b) ? a : b;
}

template<>
const char* Max(const char * a, const char * b) {
	return strcmp(a, b) > 0 ? a : b;
}

int main() {
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;

}