#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using std::cout;
using std::endl;

class Book
{
private:
	char * title;
	char * isbn;
	int price;
public:
	Book(const char * title, const char * isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo() const
	{
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book()
	{
		delete title;
		delete isbn;
	}
};

class EBook :public Book
{
private:
	char * DRMKey;
public:
	EBook(const char * title, const char * isbn, int price, const char * key) : Book(title, isbn, price)
	{
		DRMKey = new char[(strlen(key) + 1)];
		strcpy(DRMKey, key);
	}
	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~EBook() {
		delete DRMKey;
	}
};

int main()
{
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kjw");
	ebook.ShowEBookInfo();
	return 0;
}