#include<iostream>
using namespace std;
int partition(int a[], int beg, int las)
{
	int pivot = a[las];
	int pIndex = beg;
	for(int i=beg;i<las;i++)
	{
		if(a[i] < pivot)
		{
			int temp = a[i];
			a[i] = a[pIndex];
			a[pIndex] = temp;
			pIndex++;
		}
	}
	int temp = a[las];
	a[las] = a[pIndex];
	a[pIndex] = temp;
	return pIndex;
}

void quick(int a[], int beg, int las)
{
	int p;
	if(beg < las)
	{
		p = partition(a,beg,las);
		quick(a,beg,(p-1));
		quick(a,(p+1),las);
	}
}

int main()
{
	int n,a[6] = {6,5,4,3,2,1},beg = 0, las;
	n = sizeof(a)/sizeof(int);
	las = n;
	cout<<"Before sorting\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	quick(a,beg,las);
	cout<<"Ater sorting\n";
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
