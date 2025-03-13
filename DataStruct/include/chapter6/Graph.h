#pragma once

namespace Chapter6
{
	class Graph
	{
	public:
		virtual~Graph(){}
		bool IsEmpty() const {return n == 0}
		int NumberOfVertices() const { return n; }
		int NumberOfEdges() const { return e; }
		virtual intDegree(int u) const = 0;
		virtual bool ExistsEdge(int u, int v) const = 0;
		virtual void InsertVertex(int v) = 0;
		virtual void InsertEdge(int u, int v) = 0;
		virtual void DeleteVertex(int v) = 0;
		virtual void DeleteEdge(int u, int v) = 0;

		virtual void DFS();
		virtual void DFS(const int v);

	private:
		int n;
		int e;

		bool* visited;
	};
}