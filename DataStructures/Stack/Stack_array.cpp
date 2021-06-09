#include<iostream>
#include<stdlib.h>
using namespace std;
#define max 10

int top = -1;
void push(int a[], int data)
{
	if (top == max)
	{
		cout<<"Overflow!";
	}
	else
	{
		top = top+1;
		a[top]  = data;
	}
}

void pop(int a[])
{
	if (top == -1)
	{
		cout<<"Underflow";
	}
	else
	{
		top = top-1;
	}
}

void display(int a[])
{
	if(top == -1)
	{
		cout<<"Nothing to display\n";
	}
	else
	{
		for(int i=top;i>=0;i--)
		{
			cout<<a[i]<<endl;
		}
	}
}

int main()
{
	int stack[max],value;
	char c,ch;
	do
	{
	cout<<"MAIN MENU\n";
	cout<<"1. PUSH\n";
	cout<<"2. POP\n";
	cout<<"3. DISPLAY\n";
	cout<<"4. CLEAR SCREEN\n";
	cout<<"0. Exit\n";
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case '1':
			cout<<"Enter the number you want to insert in the stack:";
			cin>>value;
			push(stack,value);
			break;
		case '2':
			pop(stack);
			break;
		case '3':
			display(stack);
			break;
		case '4':
			system("cls");
			break;
		case '0':
			exit(0);
		default:
			cout<<"Invalid choice! Choose from the above menu.\n";
	}
	cout<<"\nDo you want to continue Y/N: ";
	cin>>c;
	}while(c == 'y' || c=='Y');
	return 0;
}
