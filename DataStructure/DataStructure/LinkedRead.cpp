#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	head = (Node*)malloc(sizeof(Node));		// 추가된 문장, 더미 노드 추가
	head->next = NULL;	
	tail = head;
	// 데이터를 입력 받는 과정 //
	while (1)
	{
		cout << "자연수 입력 : ";
		cin >> readData;
		if (readData < 1)
			break;

		// 노드의 추가 과정
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		
		tail->next = newNode;

		tail = newNode;
	}
	
	// 입력 받은 데이터의 출력과정 //
	if (head->next == NULL)
	{
		cout << "데이터 없음" << endl;
	}
	else
	{
		cur = head;

		while (cur->next != NULL)
		{
			cur = cur->next;
			cout << cur->data << ' ';
		}
	}

	// 메모리의 해제과정 //
	if (tail == NULL)
		return 0;
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			free(delNode);
		}
	}
}