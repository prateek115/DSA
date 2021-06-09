#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node * next;
};
node* head = NULL;

void InsertBegin(int data)
{
	node* ptr = new node;
	ptr->data = data;
	ptr->next = ptr;
	head = ptr;
}

void InsertEnd(int data)
{
	node* temp = head;
	node* ptr = new node;
	do
	{
		temp = temp->next;
	}while(temp->next != head);
	ptr->data = data;
	temp->next = ptr;
	ptr->next = head;
}

void InsertAfterNode(int data, int idata)
{
	node* temp = head;
	node* post;
	post = head->next; 
	node* ptr = new node;
	while(temp->data != idata )
	{
		temp = temp->next;
		post = post->next;
	}
	temp->next = ptr;
	ptr->data = data;
	ptr->next = post;
		
}

void InsertBeforeNode(int data, int idata)
{
	node* temp = head;
	node* post;
	post = head->next; 
	node* ptr = new node;
	while(post->data != idata )
	{
		temp = temp->next;
		post = post->next;
	}
	temp->next = ptr;
	ptr->data = data;
	ptr->next = post;
		
}

void deleteStart()
{
	node* temp = head;
	head = temp->next;
	free(temp);
}

void deleteEnd()
{
	node* temp = head->next;
	node* prev = head;
	do
	{
		temp = temp->next;
		prev = prev->next;
	}while(temp->next != head);
	prev->next = head;
	free(temp);
}

void display()
{
	node* temp = head;
	do
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}while(temp != head);
}

int main()
{
	InsertBegin(10);
	InsertEnd(20);
	InsertEnd(30);
	display();
	cout<<endl;
	InsertAfterNode(25,20);
	display();
	cout<<endl;
	deleteEnd();
	display();
	return 0;
}
