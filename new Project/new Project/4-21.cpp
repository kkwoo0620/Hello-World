#include<iostream>
#include<functional>
using namespace std;

template <class T>
struct Less
{
	bool operator()(T a, T b)
	{
		return a < b ? true : false;
	}
};

template <class T>
struct Greater
{
	bool operator()(T a, T b)
	{
		return a > b ? true : false;
	}
};

int main()
{
	
}