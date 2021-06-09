#include<iostream>
#include<stdlib.h>
using namespace std;

struct Queue
{
	int data;
	Queue* next;
};

Queue* front = NULL;
Queue* rear = NULL;

void push(int data)
{
	Queue* ptr = new Queue;
	ptr->data = data;
	if(front == NULL && rear == NULL)
	{
		ptr->next = rear;
		front = ptr;
		rear = ptr;
	}
	else //if( front == rear)
	{
		rear->next = ptr;
		ptr->next = NULL;
		rear = ptr;
	}
}

void pop()
{
	Queue* temp = front;
	front = front->next;
	free(temp);
}

void display()
{
	Queue* temp = front;
	while(temp != NULL )
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
}

int main()
{
	push(12);
	push(13);
	push(14);
	push(15);
	push(16);
	display();
	cout<<endl;
	pop();
	display();
	cout<<endl;
	pop();
	display();
	cout<<endl;
	pop();
	display();
	cout<<endl;
	pop();
	display();
	return 0;
}
