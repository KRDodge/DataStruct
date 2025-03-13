#include "chapter6/Graph.h"
#include <algorithm>

using namespace std;

namespace Chapter6
{
	virtual void Graph::DFS()
	{
		visited = new bool[n];
		fill(visited, visited + n, false);
		DFS(0);
		delete[] visited;
	}

	virtual void Graph::DFS(const int v)
	{
		visited[v] = true;
		for (int i = v; i < n; ++i)
		{
			if (!visited[v])
				DFS(i);
		}
	}
}