#include <cstddef>
#include <cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct Node {
	int key;
	Node* head, *tail;
};
Node* ListCommand;

Node *init() {
	Node* firstNode = new Node;
	firstNode->head = NULL;
	firstNode->tail = NULL;
	firstNode->key = 0;
	return firstNode;
}
void insert(int key) {
	Node* newNode = new Node;
	newNode->key = key;
	if (ListCommand->tail == NULL) {
		newNode->tail = NULL;
		newNode->head = NULL;
		ListCommand->head = newNode;
		ListCommand->tail = newNode;
	}
	else {
		newNode->tail = ListCommand->tail;
		newNode->head =NULL;
		newNode->tail->head = newNode;
		ListCommand->tail = newNode;
	}
	cout << "Inserted: " << key << endl;
}
Node *searchList(int fkey) {
	Node* searchNode = ListCommand->tail;
	while (searchNode != NULL && searchNode->key != fkey) {
		searchNode = searchNode->tail;
	}
	if (searchNode != NULL) {
		cout << "Found: " << fkey << endl;  // ����� ���
	}
	else {
		cout << "Not Found: " << fkey << endl;  // ����� ���
	}
	return searchNode;
}

	
	void deleteNode(Node * deleteNode) {
		// ������ ����� �� ��带 ó���մϴ�.
		if (deleteNode->tail != NULL) {
			deleteNode->tail->head = deleteNode->head;
		}
		else { // ������ ��尡 ����Ʈ�� ������ ����� ���
			ListCommand->head = deleteNode->head;
			ListCommand->head->tail = NULL; // ���ο� ������ ����� tail�� NULL�� ����
		}

		// ������ ����� �� ��带 ó���մϴ�.
		if (deleteNode->head != NULL) {
			deleteNode->head->tail = deleteNode->tail;
		}
		else { // ������ ��尡 ����Ʈ�� ù ��° ����� ���
			ListCommand->tail = deleteNode->tail;
			ListCommand->tail->head = NULL; // ���ο� ù ����� head�� NULL�� ����
		}

		// �޸� ����
		delete(deleteNode);
	}


void deleteKey(int fkey) {
	
	deleteNode(searchList(fkey));
	
	Node* curNode = ListCommand->tail;

	int i = 0;
	while (true)
	{
		if (curNode == NULL)break;
		if (i++ > 0) { printf(" "); }
		printf("%d\n", curNode->key);
		curNode = curNode->tail;

	}
	delete(curNode);
};
void deleteLast(Node *list) {
	Node* imsinode;
	imsinode = list->head->head;
	deleteNode(list->head);
	list->head = imsinode;
}
void deleteFirst(Node*list) {
	deleteNode(list->tail);
}
void printList() {
	Node* curNode = ListCommand->tail;
	int i = 0;
	while (curNode!=NULL)
	{
		
		if (i++ > 0) { printf(" "); }
		printf("%d", curNode->key);
		curNode = curNode->tail;
	}
	printf("\n");
}

int main() {
	int Ncommand;
	int key;
	char command[10];

	cin >> Ncommand;
	ListCommand=init();

	while (Ncommand > 0) {
		printf("��ɾ�Է��϶�10���ڹ̸�");
		cin >> command >> key;
	
		if (command[0] == 'i') {
			insert(key);

		}
		else if (command[0] == 'd') {
			if (strlen(command) > 6) {
				if (command[6] == 'L') {
					deleteLast(ListCommand);
				}
				else if (command[6] == 'F') {
					deleteFirst(ListCommand);
				}	
			}
			else
			{
				deleteKey(key);
			}
		}
		--Ncommand;
	}
	printList();
	return 0;
}