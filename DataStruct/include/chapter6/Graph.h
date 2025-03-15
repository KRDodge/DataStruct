#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

namespace Chapter6
{
	class Graph
	{
	public:
		virtual~Graph(){}
		virtual int Degree(int u) const = 0;
		virtual bool ExistsEdge(int u, int v) const = 0;
		virtual void InsertVertex(int v) = 0;
		virtual void InsertEdge(int u, int v) = 0;
		virtual void DeleteVertex(int v) = 0;
		virtual void DeleteEdge(int u, int v) = 0;

		virtual void DFS()
		{
			visited = new bool[n];
			fill(visited, visited + n, false);
			DFS(0);
			delete[] visited;
		}

		virtual void DFS(const int v)
		{
			visited[v] = true;
			for (int i = 0; i < n; ++i)
			{
				if (!visited[i])
					DFS(i);
			}
		}

		virtual void BFS(int v) 
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

		virtual void DfnLow(const int x) 
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
		virtual void DfnLow(const int u, const int v) 
		{

		}

		virtual void Components()
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
		virtual void OutputNewComponent()
		{
			cout << endl;
		}

	protected:
		int n;
		int e;
		int* dfn;
		int* low;
		int num;

		bool* visited;
	};
}