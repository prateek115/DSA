#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
};
node* head = NULL;

void insertStarting(int data)
{
	node* ptr = new node;
	ptr->data = data;
	ptr->next = head;
	head = ptr;
		
}

void InsertEnd(int data)
{
	node* temp = head;
	node* ptr = new node;
	while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = ptr;
	ptr->data = data;
	ptr->next = NULL;
	
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

void deleteBegin()
{
	node* temp = head;
	head = temp->next;
	free(temp); 
}

void deleteEnd()
{
	node* prev = head;
	node* temp = head->next;
	while(temp->next != NULL)
	{
		prev = prev->next;
		temp = temp->next;
    }
    prev->next = NULL;
    free(temp);	
}

void display()
{
	node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"->";
		temp  = temp->next;
	}
}



int main()
{
	int value, idata;
	char ch,c;
	do
	{
	cout<<"MAIN MENU\n";
	cout<<"1. Insertion in begining\n";
	cout<<"2. Insertion in the end\n";
	cout<<"3. Insertion after a node\n";
	cout<<"4. Insertion before a node\n";
	cout<<"5. Deletion from begining\n";
	cout<<"6. Deletion from end\n";
	cout<<"7. Display the list\n";
	cout<<"0. Exit\n";
	cout<<"Enter your choice:";
	cin>>ch;
	switch(ch)
	{
		case '1':
			cout<<"Enter the number you want to insert in the beginning of the list:";
			cin>>value;
			insertStarting(value);
			break;
		case '2':
			cout<<"Enter the number you want to insert in the end of the list:";
			cin>>value;
			InsertEnd(value);
			break;
		case '3':
			cout<<"Enter the number you want to insert in the end of the list:";
			cin>>value;
			cout<<"Enter the data value you want to enter after:";
			cin>>idata;
			InsertAfterNode(value, idata);
			break;
		case '4':
			cout<<"Enter the number you want to insert in the end of the list:";
			cin>>value;
			cout<<"Enter the data value you want to enter after:";
			cin>>idata;
			InsertBeforeNode(value, idata);
			break;
		case '5':
			deleteBegin();
			break;
		case '6':
			deleteEnd();
			break;
		case '7':
			cout<<"The present list:\n";
			display();
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
