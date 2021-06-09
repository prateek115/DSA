#include<iostream>
using namespace std;

int linear(int a[], int n, int data)
{
	for(int i=0;i<n;i++)
	{
		if(a[i] == data)
			return (i+1);
	}
	return -1;
}

int main()
{
	int a[6]={9,8,7,6,5,2},temp,n;
	n = sizeof(a)/sizeof(int);
	cout<<n<<endl;
	cout<<"Before algo:\n";
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	temp = linear(a,n,6);
	if(temp == -1)
		cout<<"Not present";
	else
		cout<<"Element present at "<<temp<<"th index in array";
	return 0;
}
