#include "chapter6/GraphExtend.h"
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

namespace Chapter6
{
	GraphExtend::GraphExtend(int size)
	{
		n = size;
		e = 0;
		num = 0;
		adjMatrix = new bool* [n];
		for (int i = 0; i < n; ++i)
		{
			adjMatrix[i] = new bool[n];
			fill(adjMatrix[i], adjMatrix[i] + n, false);
		}
		visited = new bool[n]();
		dfn = new int[n]();
		low = new int[n]();
	}

	GraphExtend::~GraphExtend()
	{
		for (int i = 0; i < n; ++i)
			delete[] adjMatrix[i];
		delete[] adjMatrix;
		delete[] visited;
		delete[] dfn;
		delete[] low;
	}

	bool GraphExtend::ExistsEdge(int u, int v) const
	{
		return adjMatrix[u][v];
	}

	void GraphExtend::InsertVertex(int v)
	{
		if (v >= n)
		{
			bool** newMatrix = new bool* [v + 1];
			for (int i = 0; i <= v; ++i)
			{
				newMatrix[i] = new bool[v + 1]();
				if (i < n)
				{
					copy(adjMatrix[i], adjMatrix[i] + n, newMatrix[i]);
					delete[] adjMatrix[i];
				}
			}
			delete[] adjMatrix;
			adjMatrix = newMatrix;
			n = v + 1;
		}
	}

	void GraphExtend::InsertEdge(int u, int v)
	{
		if (!adjMatrix[u][v])
		{
			adjMatrix[u][v] = adjMatrix[v][u] = true;
			e++;
		}
	}

	void GraphExtend::DeleteVertex(int v)
	{
		for (int i = 0; i < n; ++i)
		{
			adjMatrix[v][i] = false;
			adjMatrix[i][v] = false;
		}
	}

	void GraphExtend::DeleteEdge(int u, int v)
	{
		if (adjMatrix[u][v])
		{
			adjMatrix[u][v] = adjMatrix[v][u] = false;
			e--;
		}
	}

	int GraphExtend::Degree(int u) const
	{
		int degree = 0;
		for (int i = 0; i < n; ++i)
			if (adjMatrix[u][i])
				degree++;
		return degree;
	}

	void GraphExtend::DFS()
	{
		visited = new bool[n];
		fill(visited, visited + n, false);
		DFS(0);
		delete[] visited;
	}

	void GraphExtend::DFS(const int v)
	{
		visited[v] = true;
		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
				DFS(i);
		}
	}

	void GraphExtend::BFS(int v)
	{
		visited = new bool[n];
		fill(visited, visited + n, false);
		visited[v] = false;
		queue<int> q; //이제부터 그냥 라이브러리사용하자
		q.push(v);
		while (!q.empty())
		{
			v = q.front();
			q.pop();
			for (int i = 0; i < n; ++i)
				if (!visited[i])
				{
					q.push(i);
					visited[i] = true;
				}
		}
		delete[] visited;
	}

	void GraphExtend::DfnLow(const int x)
	{
		num = 1;
		dfn = new int[n];
		low = new int[n];
		fill(dfn, dfn + n, 0);
		fill(low, low + n, 0);
		DfnLow(x, -1);
		delete[] dfn;
		delete[] low;
	}

	void GraphExtend::DfnLow(const int u, const int v)
	{
		dfn[u] = low[u] = num++;
		for (int i = 0; i < n; ++i)
		{
			if (adjMatrix[u][i] && i != v)
			{
				if (dfn[i] == 0)
				{
					DfnLow(i, u);
					low[u] = min(low[u], low[i]);
				}
				else
				{
					low[u] = min(low[u], dfn[i]);
				}
			}
		}
	}

	void GraphExtend::Components()
	{
		visited = new bool[n];
		fill(visited, visited + n, false);
		for (int i = 0; i < n; ++i)
		{
			if (!visited[i])
			{
				DFS(i);
				OutputNewComponent();
			}
		}
		delete[] visited;
	}

	void GraphExtend::OutputNewComponent()
	{
		cout << endl;
	}

	void TestGraph()
	{
		GraphExtend g(10);
		g.DeleteVertex(10);
	}
}