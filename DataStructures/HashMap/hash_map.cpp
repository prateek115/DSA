#include<iostream>
using namespace std;

class hashmap
{
	int a[10];
	int key;
	
public:
	hashmap()
	{
		key = 0;
		for(int i=0;i<10;i++)
			a[i] = 0;
	}
	int hash_value(string s)
	{
		key = 0;
		for(int i=0;i<s.length();i++)
		{
			int char_value = s[i];
			key += char_value; 
		}
		return key%10;
	}
	
	void set_value(string str, int data)
	{
		key = hash_value(str);
		a[key] = data;
	}
	
	int get_value(string str)
	{
		key = hash_value(str);
		return a[key];
	}
	
	void display()
	{
		for(int i=0;i<10;i++)
			cout<<a[i]<<endl;
	}
};

int main()
{
	int value;
	hashmap h;
	h.set_value("Prateek",10);
	h.set_value("Mansi",20);
	h.set_value("Manish",30);
	h.set_value("Poorvi",50);
	cout<<h.get_value("Prateek")<<endl;
	cout<<h.get_value("Mansi")<<endl;
	cout<<h.get_value("Manish")<<endl;
	cout<<h.get_value("Poorvi")<<endl;
	h.display();
	return 0;
}
