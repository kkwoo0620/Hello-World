#include <iostream>
#include "Calculator.h"

using std::cout;
using std::endl;

int main(void) {
	Calculator cal;
	cal.Init();
	cout << cal.Add(3.2, 2.4) << cal.Div(3.5, 1.7) << cal.Min(2.2, 1.5) << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();
}