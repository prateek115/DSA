#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

void bfs(Node* root)
{
	int level = 0;
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	level++;
	while(!q.empty())
	{
		int n = q.size();
		for(int i=0;i<n;i++)
		{
			Node* temp = q.front();
			q.pop();
			cout<<temp->data<<"->";
			level++;
			if(temp->left != NULL)
			{
				q.push(temp->left);
			}
			if(temp->right != NULL)
			{
				q.push(temp->right);
			}
		}
	}
	cout<<"\n"<<level;
}

void rightView(Node* root)
{
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int n = q.size();
		for(int i=0;i<n;i++)
		{
			Node* temp = q.front();
			q.pop();
			if(i == n-1)
			{
				cout<<temp->data<<"->";
			}
			if(temp->left != NULL)
			{
				q.push(temp->left);
			}
			if(temp->right != NULL)
			{
				q.push(temp->right);
			}
		}
	}
}

void leftView(Node* root)
{
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int n = q.size();
		for(int i=1;i<=n;i++)
		{
			Node* temp = q.front();
			q.pop();
			if(i == 1)
			{
				cout<<temp->data<<"->";
			}
			if(temp->left != NULL)
			{
				q.push(temp->left);
			}
			if(temp->right != NULL)
			{
				q.push(temp->right);
			}
		}
	}
}


int main()
{
	Node* root = new Node;
	Node* l1 = new Node;
	Node* l2 = new Node;
	Node* r1 = new Node;
	root->data = 20;
	root->left = l1;
	root->right = r1;
	
	l1->data = 12;
	l1->left = l2;
	l1->right = NULL;
	
	l2->data = 10;
	l2->left = NULL;
	l2->right = NULL;
	
	r1->data = 40;
	r1->left = NULL;
	r1->right = NULL;
	bfs(root);
	cout<<endl<<"Right view\n";
	rightView(root);
	cout<<endl<<"Left view\n";
	leftView(root);
	return 0;
}
