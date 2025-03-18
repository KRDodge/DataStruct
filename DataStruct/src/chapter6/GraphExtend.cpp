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
		adjMatrix = new int* [n];
		for (int i = 0; i < n; ++i)
		{
			adjMatrix[i] = new int[n];
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
			int** newMatrix = new int* [v + 1];
			for (int i = 0; i <= v; ++i)
			{
				newMatrix[i] = new int[v + 1]();
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
			adjMatrix[u][v] = adjMatrix[v][u] = 1;
			e++;
		}
	}

	void GraphExtend::InsertEdge(int u, int v, int weight)
	{
		if (!adjMatrix[u][v])
		{
			adjMatrix[u][v] = adjMatrix[v][u] = weight;
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
			if (adjMatrix[v][i] && !visited[i])
				DFS(i);
		}
	}

	void GraphExtend::BFS(int v)
	{
		visited = new bool[n];
		fill(visited, visited + n, false);
		visited[v] = true;
		queue<int> q; //이제부터 그냥 라이브러리 사용하자
		q.push(v);
		while (!q.empty())
		{
			v = q.front();
			q.pop();
			for (int i = 0; i < n; ++i)
				if (adjMatrix[v][i] && !visited[i])
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

	int** GraphExtend::Kruskal()
	{
		int i, j, edgeCount = 0;
		int* from = new int[e];
		int* to = new int[e];
		int* weight = new int[e];

		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				if (adjMatrix[i][j] > 0) {
					from[edgeCount] = i;
					to[edgeCount] = j;
					weight[edgeCount] = adjMatrix[i][j];
					edgeCount++;
				}
			}
		}

		int* indices = new int[edgeCount];
		for (i = 0; i < edgeCount; i++) 
			indices[i] = i;

		sort(indices, indices + edgeCount, [&](int a, int b) 
		{
			return weight[a] < weight[b];
		});

		int* parent = new int[n];
		for (i = 0; i < n; i++) 
			parent[i] = i;

		int** mstEdges = new int* [n - 1];
		for (i = 0; i < n - 1; i++) 
			mstEdges[i] = new int[3];

		int count = 0;
		for (i = 0; i < edgeCount; i++) {
			int idx = indices[i];
			int rootU = from[idx];
			int rootV = to[idx];

			while (parent[rootU] != rootU) 
				rootU = parent[rootU];
			while (parent[rootV] != rootV) 
				rootV = parent[rootV];

			if (rootU != rootV) {
				parent[rootU] = rootV;
				mstEdges[count][0] = from[idx];
				mstEdges[count][1] = to[idx];
				mstEdges[count][2] = weight[idx];
				count++;
				if (count == n - 1) break;
			}
		}

		delete[] from;
		delete[] to;
		delete[] weight;
		delete[] parent;
		delete[] indices;

		return mstEdges;
	}

	int** GraphExtend::Prim()
	{
		int i, j;
		int* parent = new int[n];
		int* key = new int[n];
		bool* mstSet = new bool[n];

		for (i = 0; i < n; i++)
		{
			key[i] = INT_MAX;
			mstSet[i] = false;
		}

		key[0] = 0; //0번째 정점 선택
		parent[0] = -1;

		for (i = 0; i < n - 1; i++) 
		{
			int u = -1;
			int minKey = INT_MAX;
			for (j = 0; j < n; j++)
			{
				if (!mstSet[j] && key[j] < minKey)
				{
					minKey = key[j];
					u = j;
				}
			}
			mstSet[u] = true;

			for (j = 0; j < n; j++)
				if (adjMatrix[u][j] && !mstSet[j] && adjMatrix[u][j] < key[j])
				{
					parent[j] = u;
					key[j] = adjMatrix[u][j];
				}
		}

		int** mstEdges = new int* [n - 1];
		for (i = 0; i < n - 1; i++)
			mstEdges[i] = new int[3];

		for (i = 1; i < n; i++) {
			mstEdges[i - 1][0] = parent[i];
			mstEdges[i - 1][1] = i;
			mstEdges[i - 1][2] = adjMatrix[i][parent[i]];
		}

		delete[] parent;
		delete[] key;
		delete[] mstSet;

		return mstEdges;
	}

	void TestGraph()
	{
		GraphExtend g(10);
		g.InsertVertex(1);
		g.InsertVertex(2);
		g.InsertVertex(3);
		g.InsertVertex(4);
		g.InsertVertex(5);
		g.InsertVertex(6);
		g.InsertEdge(1, 2, 1);
		g.InsertEdge(1, 3, 2);
		g.InsertEdge(1, 4, 3);
		g.InsertEdge(4, 5, 4);
	}
}