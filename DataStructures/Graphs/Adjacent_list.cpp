#include<iostream>
#include<vector>
#include<map>
using namespace std;

void AddEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void display(vector<int> adj[], int V)
{
	for(int i=0;i<V;i++)
	{
		cout<<"List at"<<i<<"th index is:\n";
		for(int x : adj[i])
			cout<<"->"<<x;
		cout<<"\n";
	}
}

int main()
{
	int V=4;
	vector<int> adj[V];
	AddEdge(adj,0,1);
	AddEdge(adj,1,2);
	AddEdge(adj,2,3);
	AddEdge(adj,3,0);
	display(adj,V);
	return 0;
}
