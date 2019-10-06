#include<iostream>
#include<ctime>
using std::cout;
using std::endl;

int main() {
	cout << "로또 추첨을 시작합니다!!" << endl;
	
	int Lotto[45];
	
	// 1부터 45까지 배열에 넣기.
	for (int i = 0; i < 45; i++)
	{
		Lotto[i] = i + 1;
	}

	srand((unsigned int)time(0));
	
	// 100번 골고루 섞어주기. shuffle
	for (int i = 0; i < 100; i++)
	{
		int idx1 = rand() % 45;
		int idx2 = rand() % 45;

		int temp = Lotto[idx1];
		Lotto[idx1] = Lotto[idx2];
		Lotto[idx2] = temp;
	}
	
	for (int i = 0; i < 6; i++)
	{
		cout << Lotto[i] << ' ';
	}

	cout << endl;

	cout << "보너스 번호: " << Lotto[6];
}
