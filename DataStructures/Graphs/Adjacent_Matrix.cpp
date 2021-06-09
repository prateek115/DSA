#include<iostream>
using namespace std;

void AddEdge(int aj[4][4], int u, int v)
{
	aj[u][v] = 1;
	aj[v][u] = 1;
}

void display(int aj[4][4], int V)
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			cout<<aj[i][j]<<"\t";
		cout<<"\n";
	}
	
}

//Desired Graph
//
//		0---1
//		|	|
//		3---2
//

int main()
{
	int V=4;
	int adj[4][4]={0};
	AddEdge(adj,0,1);
	AddEdge(adj,1,2);
	AddEdge(adj,2,3);
	AddEdge(adj,3,0);
	display(adj,V);
	return 0;
}
