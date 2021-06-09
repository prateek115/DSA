#include<iostream>
using namespace std;
#define max 10
int front = -1;
int rear = -1;

void push(int a[], int data)
{
	if(rear == max)
	{
		cout<<"Overflow";
	}
	else if (rear == -1 && front == -1)
	{
		front = 0;
		rear = 0;
		a[rear] = data;
	}
	
	else
	{
		rear = rear + 1;
		a[rear] = data;
	}
}

void pop(int a[])
{
	if (front == -1)
	{
		cout<<"Underflow";
	}
	else if(rear == 0 && front == 0)
	{
		rear == -1 ;
		front == -1;
	}
	else
	{
		front = front + 1;
		
	}
}

void display(int a[])
{
	for (int i=front;i<=rear;i++)
	{
		cout<<a[i]<<" ";
	}
}

int main()
{
	int queue[max];
	push(queue,3);	
	push(queue,12);
	push(queue,23);
	push(queue,1111);
	display(queue);
	cout<<"\n";
	pop(queue);
	pop(queue);
	display(queue);
	return 0;
}
