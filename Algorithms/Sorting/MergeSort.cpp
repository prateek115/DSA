#include<iostream>
using namespace std;

void mergeSort(int a[], int beg, int mid, int las)
{
	int i=beg,j=mid+1,k = beg,temp[6];
	while(i <=mid && j <=las)
	{
		if(a[i] < a[j])
		{
			temp[k] = a[i];
			i++;
		}
		
		else
		{
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	
	if(i > mid)
	{
		while(j != las)
		{
			temp[k] = a[j];
			j++;
			k++;
		}
	}
	
	else
	{
		while(i <= mid)
		{
			temp[k] = a[i];
			i++;
			k++;
		}
	}
	
	for(int index = beg; index < k; index++)
	{
		a[index] = temp[index];
	}
}

void merge(int a[], int beg, int las)
{
	int mid;
	if(beg < las)
	{
		mid = (beg+las)/2;
		merge(a,beg,mid);
		merge(a,mid+1,las);
		mergeSort(a,beg,mid,las);
	}
}

int main()
{
	int a[6]={9,8,7,6,5,2},n,beg = 0,las;
	n = sizeof(a)/sizeof(int);
	las = n;
	cout<<n<<endl;
	cout<<"Before algo:\n";
	for(int i = 0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
	merge(a,beg,las);
	cout<<"After algo:\n";
	for(int i = 0;i<6;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}
