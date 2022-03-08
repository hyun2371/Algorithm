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
	//���� ����
	void insertVertex(int n) {
		if (!isFull()) vertices[size++] = n;
		else printf("Error: �׷��� ���� ���� �ʰ�\n");
	}

	//���� ����
	void insertEdge(int u, int v) {
		setEdge(u, v, 1);
		setEdge(v, u, 1);
	}

	void load() {
		int n, val; //��� ���� ���Ῡ��
		cin >> n;
		char str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			insertVertex(str);
			for (int j = 0; j < n; j++) {
				cin >> val;
				//��Ī����̹Ƿ� ���ݸ� �����ϸ� ��
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
	bool visited[MAX_VTXS]; //������ �湮 ����
public:
	//��� ������ �湮���� �ʾҴٰ� �ʱ�ȭ
	void resetVisited() { 
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}

	bool isLinked(int u, int v) {
		return getEdge(u, v) != 0;
	}
	//���� �켱 Ž�� �Լ�
	void DFS(int v) {
		visited[v] = true; //���� ���� �湮
		printf("%c ", getVertex(v)); //�ش� ������ �̸� ���

		//���� && �湮x-->��ȯȣ��
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
	g.DFS(0); //0��° ����(A)���� ���� �켱 Ž��

}