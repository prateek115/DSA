#include<iostream>
using namespace std;
#include<stdlib.h>

struct Stack
{
	int data;
	Stack* next;
};

Stack* top = NULL;

void push(int data)
{
	Stack* ptr = new Stack;
	ptr->data = data;
	ptr->next = top;
	top = ptr;
}

void pop()
{
	Stack* temp = top;
	top = temp->next;
	free(temp);
}

void display()
{
	Stack* temp = top;
	while(temp != NULL)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}
}

int main()
{
		int value;
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
			push(value);
			break;
		case '2':
			pop();
			break;
		case '3':
			display();
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
