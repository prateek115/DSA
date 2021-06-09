#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void AddEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(int s, vector<int> adj[], bool vis[])
{
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while( !q.empty() )
	{
		int p = q.front();
		cout<<p<<"->";
		q.pop();
		for(int i=0;i<adj[p].size();i++)
		{
			if(vis[adj[p][i]] == false)
			{
				q.push(adj[p][i]);
				vis[adj[p][i]] = true;
			}
		}
	}
}

int main()
{
	int V=6,s;
	bool visited[V] = {false};
	vector<int> adj[V];
	
	AddEdge(adj,0,1);
	AddEdge(adj,0,2);
	AddEdge(adj,1,3);
	AddEdge(adj,2,3);
	AddEdge(adj,2,4);
	AddEdge(adj,3,5);
	cout<<"From where you want the traversal start:";
	cin>>s;
	bfs(s,adj,visited);
	return 0;
}
