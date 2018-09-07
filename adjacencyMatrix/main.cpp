#include<iostream>
#include"Graph.h"
using namespace std;

int main(int argc, char* argv[])
{
	int V = atoi(argv[1]);
	Graph *g = new Graph(V);
	// char YN;

	for (int i = 0; i < V; ++i){
		cout << "Enter the connections of vertex " << i << ":" << endl;
		int j;
		while (cin >> j){
			if (j >= 0 && j < V && j != i){
				if (g->isConnected(i, j)){
					cout << "Vertices " << i << " and " << j << " have been connected." << endl;
				}
				else g->addEdge(i, j);
			}
			/* input two same number to quit the loop */
			else if (j == i){
				break;
			}
			else cout << "Out of range." << endl;
		}
	}
	
	for (int i = 0; i < V; ++i)
		g->showConnected(i);

	/* cout << "Do you wanna remove edges?";
	cin >> YN;
	if (YN == 'Y'){
		int i, j;
		cout << "Enter the edge you want to remove: " << endl;
		while (cin >> i >> j){
			if (i >= 0 && i < V && j >= 0 && j < V && j != i){
				if (!g->isConnected(i, j)){
					cout << "Vertices " << i << " and " << j << " are not connected." << endl;
				}
				else {
					g->removeEdge(i, j);
				}
			}
			else if (j == i){
				break;
			}
			else cout << "Out of range.";
		}
	}
	else if (YN == 'N')
		cout << "No edges to remove." << endl;

	for (int i = 0; i < V; ++i)
		g->showConnected(i); */

	// DFS
	int start;
	cout << "Enter the DFS starting node:";
	cin >> start;
	g->dfs(start);

	// BFS
	cout << "Enter the BFS starting node:";
	cin >> start;
	g->bfs(start);

	return 0;
}