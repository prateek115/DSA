#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

//Node* root = NULL;



bool IsBST(Node* root, int minValue, int maxValue)
{
	if (root == NULL)
		return true;
	if(root->data > minValue && root->data < maxValue && IsBST(root->left,minValue,root->data) 
	&& IsBST(root->right,root->data,maxValue))
		return true;
	else 
		return false;

}

Node* FindMin(Node* root)
{
	if(root == NULL)
		exit(0);
	else if (root->left == NULL)
		return root;
	return(root->left);
}

Node* Delete (Node* root, int data)
{
	if(root == NULL)
		return root;
	else if(data < root->data)
		root->left = Delete(root->left,data);
	else if(data > root->data)
		root->right = Delete(root->right,data);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		
		else
		{
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}	
		
	}
	return root;
}

void Inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Inorder(root->left);
	cout<<root->data;
	cout<<endl;
	Inorder(root->right);
	
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
	
	Inorder(root);
	
	if (IsBST(root,INT_MIN,INT_MAX))
	{
		cout<<"Tree";
	}
	
	else
	{
		cout<<"Not tree";
	}
	
	return 0;
}
