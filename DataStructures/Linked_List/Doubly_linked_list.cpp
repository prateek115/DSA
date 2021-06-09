#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head = NULL; 

void insert(int data)
{
	Node* ptr = new Node;
	ptr->data = data;
	ptr->next = head;
	ptr->prev = NULL;
	if(head != NULL)
		head->prev = ptr;
	head = ptr;
}

void display()
{
	Node* temp  = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"->";
		temp= temp->next;
	}
}

int main()
{
	insert(12);
	insert(32);
	display();
	return 0;
}
