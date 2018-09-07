#include"Graph.h"
#include"listQueue.h"
#include<iostream>
using namespace std;

Graph::Graph(int N)
{
	countV = N;
	/* initialize the adjacency matrix */
	adjMat = new bool *[countV];
	for (int i = 0; i < countV; ++i){
		adjMat[i] = new bool[countV];
		for (int j = 0; j < countV; ++j)
			adjMat[i][j] = false;
	}
}

Graph::~Graph()
{
	for (int i = 0; i < countV; ++i)
		delete[] adjMat[i];
	delete[] adjMat;
}

void Graph::addEdge(int i, int j)
{
	/* since the graph is undirected, set both a[i][j]
	and a[j][i] to 1 while adding edge between i and j */
	if (i >= 0 && i < countV && j >= 0 && j < countV){
		adjMat[i][j] = true;
		adjMat[j][i] = true;
	}
}

void Graph::removeEdge(int i, int j)
{
	/* as in addEdge(), set both a[i][j] and a[j][i]
	to 0 while removing edge between i and j*/
	if (i >= 0 && i < countV && j >= 0 && j < countV){
		adjMat[i][j] = false;
		adjMat[j][i] = false;
	}
}

bool Graph::isConnected(int i, int j)
{
	/* since the graph is undirected, we only need to
	check either a[i][j] or a[j][i], here check a[i][j]*/
	if (i >= 0 && i < countV && j >= 0 && j < countV)
		return adjMat[i][j];
	else return false;
}

void Graph::showConnected(int i)
{
	cout << "The connection of vertex " << i << ":" << endl;
	cout << i;
	for (int j = 0; j < countV; ++j){
		if (adjMat[i][j])
			cout << " -> " << j;
	}
	cout << endl;
}

void Graph::dfs(int v)
{
	bool* visited = new bool[countV];
	for (int i = 0; i < countV; ++i)
		visited[i] = false;
	cout << "The DFS tree starting at vertex " << v << " is:" << endl;
	dfsUtil(v, visited);
}

void Graph::dfsUtil(int v, bool* visited)
{
	visited[v] = true;
	// push v to stack
	for (int i = 0; i < countV; ++i){
		if (adjMat[v][i] && !visited[i]){
			cout << "(" << v << ", " << i << ")" << endl;
			dfsUtil(i, visited);
		}
	}
}

void Graph::bfs(int v)
{
	Queue<int> q;
	bool* visited = new bool[countV];
	for (int i = 0; i < countV; ++i)
		visited[i] = false;

	q.enqueue(v);
	visited[v] = true;

	cout << "The BFS tree starting at vertex " << v << " is:" << endl;
	
	while (!q.isEmpty()){
		int temp = q.dequeue();
		for (int i = 0; i < countV; ++i){
			if (adjMat[temp][i] && !visited[i]){
				q.enqueue(i);
				visited[i] = true;
				cout << "(" << temp << ", " << i << ")" << endl;
			}
		}
	}

	delete[] visited;
}