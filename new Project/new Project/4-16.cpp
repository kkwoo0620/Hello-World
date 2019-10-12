#include<iostream>
#include<string>
using namespace std;

template <class T, class Func>
void For_each(T begin, T end, Func pf)
{
	while (begin != end) {
		pf(*begin++);
	}
}


//template <class T>
//void Print(T n)
//{
//	cout << n << " ";
//}

template <class T>
struct PrintFunctor
{
	string sep; // 출력 구분자 정보
public:
	explicit PrintFunctor(const string& s = " ") : sep(s) { }

	void operator()(T data) const
	{
		cout << data << sep;
	}
};


int main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	For_each(arr, arr + 5, PrintFunctor<int>());
	
	string sarr[3] = { "hi", "i'm", "hodu" };
	For_each(sarr, sarr + 3, PrintFunctor<string>("*\n"));
}