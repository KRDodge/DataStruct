#include "chapter6/Graph.h"

using namespace std;

namespace Chapter6
{
	class GraphExtend : Graph
	{
	public:
		GraphExtend(int size);
		~GraphExtend() override;
		int Degree(int u) const override;
		bool ExistsEdge(int u, int v) const override;
		void InsertVertex(int v) override;
		void InsertEdge(int u, int v)  override;
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

	private:
		bool** adjMatrix;
	};

	void TestGraph();
}