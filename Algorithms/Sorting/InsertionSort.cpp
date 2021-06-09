#include<iostream>
using namespace std;

void insertion(int a[], int n)
{
	int i,j,key;
	for (i=1;i<n;i++)
	{
		key = a[i];
		j = i-1;
		while(j>=0 && a[j]>key)
		{
			a[j+1] = a[j];
			j = j-1;
		}
	a[j+1] = key;
	}
}

int main()
{
	int a[6]={9,8,7,6,5,2},n;
	n = sizeof(a)/sizeof(int);
	cout<<n<<endl;
	cout<<"Before algo:\n";
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	insertion(a,n);
	cout<<"After algo:\n";
	for(int i = 0;i<6;i++)
	{
		cout<<a[i]<<endl;
	}
}
