#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

class Graph
{
private:
	bool** adjMat;		// implement the matrix by a 2-D bool array
	int countV;			// number of vertices in the graph
	void dfsUtil(int, bool*);
public:
	Graph(int);
	~Graph();
	void addEdge(int, int);
	void removeEdge(int, int);
	bool isConnected(int, int);	// check if two vertices are connected
	void showConnected(int);	// show all connected vertices of one vertex
	void dfs(int);				// dfs spanning tree from the specific vertex
	void bfs(int);				// bfs spanning tree from the specific vertex
};

#endif // GRAPH_H_INCLUDED