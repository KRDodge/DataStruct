#include "chapter6/ListGraph.h"
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

namespace Chapter6
{
	ListGraph::ListGraph(int size)
	{
		n = size;
		e = 0;
		adjList = new Chain<ChainNode<GraphData>>[n];
		visited = new bool[n]();
		dfn = new int[n]();
		low = new int[n]();
	}

	ListGraph::~ListGraph()
	{
		delete[] adjList;
		delete[] visited;
		delete[] dfn;
		delete[] low;
	}

	bool ListGraph::ExistsEdge(int u, int v) const
	{
		for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) 
		{
			if (it->data.vertex == v) 
				return true;
		}
		return false;
	}

	void ListGraph::InsertVertex(int v)
	{
		//비어있는 vertex 추가, chain에 추가 안됨
		adjList[v].InsertBack(GraphData(v, 0));
	}

	void ListGraph::InsertEdge(int u, int v)
	{
		adjList[u].InsertBack(GraphData(v, 1));
		e++;
	}

	void ListGraph::InsertEdge(int u, int v, int weight)
	{
		adjList[u].InsertBack(GraphData(v, weight));
		e++;
	}

	void ListGraph::DeleteVertex(int v)
	{
		auto it = adjList[v].begin();
		while (it != adjList[v].end()) 
		{
			if (it->data.vertex == v) 
			{
				adjList[v].Delete(it.GetNode());
				e--;
				break;
			}
			++it;
		}
	}

	void ListGraph::DeleteEdge(int u, int v)
	{
		auto it = adjList[u].begin();
		auto prev = adjList[u].begin();
		while (it != adjList[u].end()) 
		{
			if (it->data.vertex == v) 
			{
				adjList[u].Delete(it.GetNode());
				e--;
				break;
			}
			prev = it;
			++it;
		}
	}

	int ListGraph::Degree(int u) const
	{
		return adjList[u].Length();
	}

	void ListGraph::DFS()
	{
		visited = new bool[n];
		fill(visited, visited + n, false);
		DFS(0);
		delete[] visited;
	}

	void ListGraph::DFS(const int v)
	{
		visited[v] = true;
		for (auto it = adjList[v].begin(); it != adjList[v].end(); ++it) 
		{
			int next = it->data.vertex;
			if (!visited[next]) 
			{
				DFS(next);
			}
		}
	}

	void ListGraph::BFS(int v)
	{
		visited = new bool[n];
		fill(visited, visited + n, false);
		queue<int> q;
		visited[v] = true;
		q.push(v);
		while (!q.empty()) 
		{
			int cur = q.front(); 
			q.pop();
			for (auto it = adjList[cur].begin(); it != adjList[cur].end(); ++it) 
			{
				int next = it->data.vertex;
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
		delete[] visited;
	}

	void ListGraph::DfnLow(const int x)
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

	void ListGraph::DfnLow(const int u, const int v)
	{
		dfn[u] = low[u] = num++;
		for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) 
		{
			int next = it->data.vertex;
			if (next == v) continue;
			if (dfn[next] == 0) 
			{
				DfnLow(next, u);
				low[u] = min(low[u], low[next]);
			}
			else 
			{
				low[u] = min(low[u], dfn[next]);
			}
		}
	}

	void ListGraph::Components()
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

	void ListGraph::OutputNewComponent()
	{
		cout << endl;
	}

	int** ListGraph::Kruskal()
	{
		int i, j, edgeCount = 0;
		int* from = new int[e];
		int* to = new int[e];
		int* weight = new int[e];

		for (int i = 0; i < n; ++i) 
		{
			for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it) 
			{
				int u = i, v = it->data.vertex;
				int w = it->data.weight;
				if (u < v) // 중복 방지
				{ 
					from[edgeCount] = u;
					to[edgeCount] = v;
					weight[edgeCount] = w;
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
		for (i = 0; i < edgeCount; i++) 
		{
			int idx = indices[i];
			int rootU = from[idx];
			int rootV = to[idx];

			while (parent[rootU] != rootU)
				rootU = parent[rootU];
			while (parent[rootV] != rootV)
				rootV = parent[rootV];

			if (rootU != rootV) 
			{
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

	int** ListGraph::Prim()
	{
		int* parent = new int[n];
		int* key = new int[n];
		bool* mstSet = new bool[n];

		for (int i = 0; i < n; ++i) 
		{
			key[i] = INT_MAX;
			mstSet[i] = false;
		}

		key[0] = 0;      // 0번 정점에서 시작
		parent[0] = -1;  // 시작 정점은 부모 없음

		for (int count = 0; count < n - 1; ++count) 
		{
			int minKey = INT_MAX;
			int u = -1;
			for (int v = 0; v < n; ++v) 
			{
				if (!mstSet[v] && key[v] < minKey) 
				{
					minKey = key[v];
					u = v;
				}
			}
			if (u == -1) 
				break;
			mstSet[u] = true;

			for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) 
			{
				int v = it->data.vertex;
				int weight = it->data.weight;
				if (!mstSet[v] && weight < key[v]) 
				{
					parent[v] = u;
					key[v] = weight;
				}
			}
		}
		int** mstEdges = new int* [n - 1];
		for (int i = 0; i < n - 1; ++i)
			mstEdges[i] = new int[3];

		int edgeIdx = 0;
		for (int i = 1; i < n; ++i) 
		{
			if (parent[i] != -1) 
			{
				mstEdges[edgeIdx][0] = parent[i];
				mstEdges[edgeIdx][1] = i;
				mstEdges[edgeIdx][2] = key[i];
				edgeIdx++;
			}
		}

		delete[] parent;
		delete[] key;
		delete[] mstSet;

		return mstEdges;
	}

	int* ListGraph::BellmanFord()
	{
		const int INF = INT_MAX;
		int* dist = new int[n];
		for (int i = 0; i < n; ++i) 
			dist[i] = INF;
		dist[0] = 0; //시작점을 0으로 잡기

		for (int i = 0; i < n - 1; ++i) 
		{
			for (int u = 0; u < n; ++u) 
			{
				for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) 
				{
					int v = it->data.vertex;
					int w = it->data.weight;
					if (dist[u] != INF && dist[u] + w < dist[v]) 
					{
						dist[v] = dist[u] + w;
					}
				}
			}
		}

		for (int u = 0; u < n; ++u) 
		{
			for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) 
			{
				int v = it->data.vertex;
				int w = it->data.weight;
				if (dist[u] != INF && dist[u] + w < dist[v])
					return nullptr;
			}
		}

		return dist;
	}

	void TestListGraph()
	{
	}
}