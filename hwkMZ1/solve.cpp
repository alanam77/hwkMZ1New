#include "solve.h"
using namespace std;
class directedGraph
{
private:
	class Vertex
	{
	public:
		Vertex(string s) {
			data = s;
		}
		string data;
		vector<Vertex*>neighs;
	};
	//Need a container (data structure) to store
	//the vertices of the graph
	unordered_map<int, Vertex*>VertexSet;
	int height = 0;
	int width = 0;
public:
	//Run time: O(1) average case, O(n) worst-case
	void storeMaze(string s)
	{
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				VertexSet[i] == new Vertex(" ");
			}
			else if (s[i] == '#') {
				VertexSet[i] == new Vertex("#");
			}
			else if (s[i] == '\n') {
				VertexSet[i] == new Vertex("\n");
			}
			
		}
	}
	void setWidth(string s) {
		for (int i = 0;; i++) {
			if (s[i] == '\n') {
				width = i;
				return;
			}
		}
	}
	void setHeight(string s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '\n') {
				height++;
			}
		}
		height--;
	}
	Vertex* findStart() {
		Vertex* start;
		for (int i = 0;; i++) {
			if (VertexSet[i]->data == " ") {
				start = VertexSet[i];
				return start;
			}
		}
	}
	Vertex* findExit() {
		Vertex* end = nullptr;
		for (int i = 0; i < VertexSet.size(); i++) {
			if (VertexSet[i]->data == " ") {
				end = VertexSet[i];
			}
		}
		return end;
	}
	void addDirectedEdge(int a, int b) {
		if (VertexSet[a] == nullptr || VertexSet[b] == nullptr) {
			return;
		}
		Vertex* A = VertexSet[a];
		Vertex* B = VertexSet[b];
		A->neighs.push_back(B);
	}
	void addBasicEdge(int a, int b) {
		addDirectedEdge(a, b);
		addDirectedEdge(b, a);
	}
	void breadthFirstSearch(Vertex* s, unordered_map<Vertex*, Vertex*>& breadCrumbs) {
		queue<Vertex*> Q;
		unordered_set<Vertex*> marked;
		marked.insert(s);
		Q.push(s);
		while (!Q.empty()) {
			Vertex* x = Q.front();
			Q.pop();
			for (int i = 0; i < x->neighs.size(); i++)
			{
				Vertex* y = x->neighs[i];
				if (marked.count(y) == 0)
				{
					marked.insert(y); //mark y;
					Q.push(y);

					//augment
					breadCrumbs[y] = x;  //set y's breadcrumb to be x;
				}
			}
		}
	}
};
string solve(string maze) {
	directedGraph mazeGraph;
	mazeGraph.storeMaze(maze);

	return "";
}