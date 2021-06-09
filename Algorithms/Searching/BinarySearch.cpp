#include<iostream>
using namespace std;

int binary(int a[], int n, int data)
{
	int beg = 0, las = n, mid;
	while(beg <= las)
	{
		mid = (beg+las)/2;
		if(a[mid] == data)
			return mid+1;
		else if(a[mid] < data)
		{
			beg = mid+1;
		}
		else
		{
			las = mid-1;
		}
			
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
	temp = binary(a,n,6);
	if(temp == -1)
		cout<<"Not present";
	else
		cout<<"Element present at "<<temp<<"th index in array";
	return 0;
}
