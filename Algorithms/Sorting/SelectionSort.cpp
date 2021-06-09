#include<iostream>
using namespace std;

void selection(int a[],int n)
{
	int i,j,min,temp;
	for(i = 0;i<n-1;i++)
	{
		min = i;
		for(j = i+1;j<n;j++)
		{
			if(a[j] < a[min])
			{
				min = j;
			}
			
		}
		if(min != i)
			{
				temp = a[i];
				a[i] = a[min];
				a[min] = temp;
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
		cout<<a[i]<<endl;
	}
	selection(a,n);
	cout<<"After algo:\n";
	for(int i = 0;i<6;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;	
}
