#include "chapter6/Graph.h"
#include "chapter4/Chain.h"

using namespace std;
using namespace Chapter4;

namespace Chapter6
{
	struct GraphData {
		int vertex;
		int weight;
		GraphData(int v, int w) : vertex(v), weight(w) {}
	};

	class ListGraph : Graph
	{
	public:
		ListGraph(int size);
		~ListGraph() override;
		int Degree(int u) const override;
		bool ExistsEdge(int u, int v) const override;
		void InsertVertex(int v) override;
		void InsertEdge(int u, int v)  override;
		void InsertEdge(int u, int v, int weight);
		void DeleteVertex(int v) override;
		void DeleteEdge(int u, int v) override;

		void DFS() override;
		void DFS(const int v) override;

		void BFS(int v) override;

		void DfnLow(const int x) override;
		void DfnLow(const int u, const int v) override;

		void Components() override;
		void OutputNewComponent() override;

		bool IsEmpty() const { return n == 0; }
		int NumberOfVertices() const { return n; }
		int NumberOfEdges() const { return e; }

		int** Kruskal();
		int** Prim();

		int* BellmanFord();

	private:
		Chain<ChainNode<GraphData>>* adjList;
	};

	void TestListGraph();
}