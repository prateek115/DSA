#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};


Node* createNode(int data)
{
	Node* ptr = new Node;
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
Node* Insert(Node* root, int data)
{
	if (root == NULL)
	{
		root = createNode(data);

	}
	
	else if (data <= root->data )
	{
		root->left = Insert(root->left, data);
	}
	
	else
	{
		root->right = Insert(root->right, data);
	}
	
	return root;
}

Node* FindMin(Node* root)
{
	if(root == NULL)
		exit(0);
	else if (root->left == NULL)
		return root;
	return FindMin(root->left);
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

bool search(Node* root, int data)
{
	if(root == NULL)
	{
		return false;
	}
	
	else if( data == root->data)
	{
		return true;
	}
	
	else if(data < root->data)
	{
		return search(root->left,data);
	}
	
	else
	{
		return search(root->right,data);
	}
}


void postorder(Node* root)
{
	if (root ==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
	cout<<endl;
}
	
void preorder(Node* root)
{
	if (root ==NULL)
	{
		return;
	}
	cout<<root->data;
	cout<<endl;
	preorder(root->left);
	preorder(root->right);
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

void InverseTree(Node* root)
{
	if(root == NULL)
		return;
	InverseTree(root->left);
	InverseTree(root->right);
	Node* t = root->left;
	root->left = root->right;
	root->right = t;
}


int main()
{
	int value;
	char ch,c;
	Node* root = NULL;
	do
	{
		cout<<"MAIN MENU\n";
		cout<<"1. Insert in binary search tree.\n";
		cout<<"2. Delete from binary tree.\n";
		cout<<"3. Inorder\n";
		cout<<"4. Preorder\n";
		cout<<"5. Postorder\n";
		cout<<"6. Search in binary tree\n";
		cout<<"7. Inverse the tree (Not necessary to remain BST)\n";
		cout<<"8. Clear Screen\n\n";
		cout<<"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case '1':
				cout<<"Enter the value you wnat to insert:";
				cin>>value;
				root = Insert(root,value);
				break;
			case '2':
				cout<<"Enter the value you want to delete:";
				cin>>value;
				Delete(root,value);
				break;
			case '3':
				cout<<"INORDER\n";
				Inorder(root);
				break;
			case '4':
				cout<<"PREORDER\n";
				preorder(root);
				break;
			case '5':
				cout<<"POSTORDER\n";
				postorder(root);
				break;
			case '6':
				cout<<"Enter the number you want to search:";
				cin>>value;
				if (search(root,value) == true)
				{
					cout<<"Found\n";
				}
				else
				{
					cout<<"Not persent\n";
				}
				break;
			case '7':
				InverseTree(root);
				Inorder(root);
				break;
			case '8':
				system("cls");
				break;
		
		}
		cout<<"Do you want to continue:";
		cin>>c;
	}while(c == 'y' || c == 'Y');	
	return 0;
}
