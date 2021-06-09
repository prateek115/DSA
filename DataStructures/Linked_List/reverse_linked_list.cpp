#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* ReverseList(Node* head)
{
	Node* post = head->next;
	Node* prev = head;
	Node* temp;
	prev->next = NULL;
	while(post != NULL)
	{
		temp = post->next;
		post->next = prev;
		prev = post;
		post = temp;	
	}
	head = prev;
	return head;
	//display(head);
	
}

void display(Node* head)
{
	Node* temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	
}

int main()
{
	Node* head = new Node;
	Node* second = new Node;
	Node* third = new Node;
	Node* fourth = new Node;
	Node* fifth = new Node;
	
	head->data = 12;
	head->next = second;

	second->data = 13;
	second->next = third;
	
	third->data = 14;
	third->next = fourth;
	
	fourth->data = 15;
	fourth->next = fifth;	
	
	fifth->data = 16;
	fifth->next = NULL;
	
	display(head);
	cout<<endl;
	head = ReverseList(head);
	display(head);
	
	return 0;
}
