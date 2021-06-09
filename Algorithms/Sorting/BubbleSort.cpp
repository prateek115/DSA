#include<iostream>
using namespace std;

void bubble(int a[],int n)
{
	for (int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
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
		cout<<a[i]<<" ";
	}
	bubble(a,n);
	cout<<endl;
	cout<<"After algo:\n";
	for(int i = 0;i<6;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
