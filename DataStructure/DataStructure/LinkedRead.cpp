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

	head = (Node*)malloc(sizeof(Node));		// �߰��� ����, ���� ��� �߰�
	head->next = NULL;	
	tail = head;
	// �����͸� �Է� �޴� ���� //
	while (1)
	{
		cout << "�ڿ��� �Է� : ";
		cin >> readData;
		if (readData < 1)
			break;

		// ����� �߰� ����
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		
		tail->next = newNode;

		tail = newNode;
	}
	
	// �Է� ���� �������� ��°��� //
	if (head->next == NULL)
	{
		cout << "������ ����" << endl;
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

	// �޸��� �������� //
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