#include <iostream>
#define MAX_VTXS 100
using namespace std;

class AdjMatGraph {
protected:
	int size;
	int vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }
	int getVertex(int i) { return vertices[i]; }
	int getEdge(int i, int j) { return adj[i][j]; }
	void setEdge(int i, int j, int val) { adj[i][j] = val; }
	bool isEmpty() { return size == 0; }
	bool isFull() {
		return size >= MAX_VTXS;
	}
	void reset() {
		size = 0;
		for (int i = 0; i < MAX_VTXS; i++) {
			for (int j = 0; j < MAX_VTXS; j++)
				setEdge(i, j, 0);
		}
	}
	//정점 삽입
	void insertVertex(int n) {
		if (!isFull()) vertices[size++] = n;
		else printf("Error: 그래프 정점 개수 초과\n");
	}

	//간선 삽입
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void display() {
		printf("%d\n", size);
		for (int i = 0; i < size; i++) {
			printf("%d ", getVertex(i));
			for (int j = 0; j < size; j++)
				printf(" %3d", getEdge(i, j));
			printf("\n");
		}
	}
};

int main() {
	AdjMatGraph g;
	for (int i = 0; i < 10; i++)
		g.insertVertex(i);
	g.insertEdge(0, 1);
	g.insertEdge(1, 2);
	g.insertEdge(1, 3);
	g.insertEdge(2, 4);
	g.insertEdge(3, 4);
	g.insertEdge(3, 5);
	g.insertEdge(5, 6);
	g.insertEdge(5, 7);
	g.insertEdge(6, 7);
	g.insertEdge(7, 8);
	g.insertEdge(7, 9);

	printf("인접 행렬로 표현한 그래프\n");
	g.display();
}