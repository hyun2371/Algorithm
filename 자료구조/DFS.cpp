#include <iostream>
#define MAX_VTXS 100
using namespace std;

class AdjMatGraph {
protected:
	int size;
	char  vertices[MAX_VTXS];
	int adj[MAX_VTXS][MAX_VTXS];
public:
	AdjMatGraph() { reset(); }
	char getVertex(int i) { return vertices[i]; }
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

	void load() {
		int n, val; //노드 개수 연결여부
		cin >> n;
		char str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			insertVertex(str);
			for (int j = 0; j < n; j++) {
				cin >> val;
				//대칭행렬이므로 절반만 연결하면 됨
				if (i > j && val != 0)
					insertEdge(i, j);
			}
		}
	}
	void display() {
		printf("%d\n", size);
		for (int i = 0; i < size; i++) {
			printf("%c ", getVertex(i));
			for (int j = 0; j < size; j++)
				printf(" %3d", getEdge(i, j));
			printf("\n");
		}
	}
};

class SrchAMGraph : public AdjMatGraph {
	bool visited[MAX_VTXS]; //정점의 방문 여부
public:
	//모든 정점을 방문하지 않았다고 초기화
	void resetVisited() { 
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}

	bool isLinked(int u, int v) {
		return getEdge(u, v) != 0;
	}
	//깊이 우선 탐색 함수
	void DFS(int v) {
		visited[v] = true; //현재 정점 방문
		printf("%c ", getVertex(v)); //해당 정점의 이름 출력

		//연결 && 방문x-->순환호출
		for (int w = 0; w < size; w++) {
			if (isLinked(v, w) && visited[w] == false)
				DFS(w);
		}
	}
	
};


int main() {
	SrchAMGraph g;
	g.load();
	g.display();
	printf("DFS ==> ");
	g.resetVisited();
	g.DFS(0); //0번째 정점(A)에서 깊이 우선 탐색

}