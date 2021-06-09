#include<iostream>
#include<vector>
using namespace std;

void AddEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void dfs(int s,vector<int> adj[],bool v[])
{
	v[s] = true;
	cout<<s<<" ";
	for(int i=0;i<adj[s].size();i++)
	{
		if(v[adj[s][i]] == false)
			dfs(adj[s][i],adj,v);
	}
	
}

int main()
{
	int V=4,s;
	bool visited[V] = {false};
	vector<int> adj[V];
	AddEdge(adj,0,1);
	AddEdge(adj,1,2);
	AddEdge(adj,2,3);
	AddEdge(adj,3,0);
	cout<<"From where you want the traversal start:";
	cin>>s;
	dfs(s,adj,visited);
	return 0;
}
