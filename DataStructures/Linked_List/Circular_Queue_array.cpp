#include<iostream>
using namespace std;
#define max 4
int front = -1;
int rear = -1;

void push(int a[], int data)
{
	if((rear+1)%max == front)
	{
		cout<<"Overflow";
	}
	else if (rear == -1 && front == -1)
	{
		front = 0;
		rear = 0;
		a[(rear)%max] = data;
	}
	
	else
	{
		rear = (rear + 1)%max;
		a[rear] = data;
	}
}

void pop(int a[])
{
	int x = 0;
	if (front == -1  && rear == -1 )
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
		x = a[front];
		front = (front + 1)%max;
		
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
	display(queue);
	cout<<endl;
	push(queue,42);
	display(queue);
	return 0;
}
