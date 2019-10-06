#include<iostream>
#include<ctime>
#include<string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

string ComNum;
int strike = 0;
int ball = 0;
int correct = 0;

void GenerateNumber();
void CheckNum();
void CheckAnswer();

int main()
{
	cout << "[ 숫자 야구 ]" << endl;
	GenerateNumber();
	while (!correct) {
		CheckNum();
		CheckAnswer();
	}
	
	return 0;
}

void GenerateNumber() {

	cout << "랜덤 숫자 3개를 생성하였습니다." << endl;

	srand((unsigned int)time(0));

	int NumArr[10];

	for (int i = 0; i < 10; i++)
	{
		NumArr[i] = i;
	}

	for (int i = 0; i < 20; i++)
	{
		int idx1 = rand() % 10;
		int idx2 = rand() % 10;

		int temp = NumArr[idx1];
		NumArr[idx1] = NumArr[idx2];
		NumArr[idx2] = temp;
	}
	std::to_string(123);
	for (int i = 0; i < 3; i++)
	{
		ComNum += std::to_string(NumArr[i]);
	}
}

void CheckNum() {

	cout << "예상 숫자 : ";
	string InputNum;
	cin >> InputNum;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) {
			if (InputNum.at(i) == ComNum.at(j))
				if (i == j)
					strike++;
				else
					ball++;
		}
	}
}

void CheckAnswer()
{
	if (strike == 3) {
		cout << "정답입니다!" << endl;
		correct = 1;
	}
	else if (strike == 0 && ball == 0) {
		cout << "Out" << endl;
	}
	else {
		cout << strike << "strike " << ball << "ball" << endl;
	}
	strike = ball = 0;
}