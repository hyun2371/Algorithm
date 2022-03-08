/*#include <iostream>
#define MAX_VTXS 100
using namespace std;
class CircularQueue {
private:
	int front;
	int rear;
	int data[MAX_VTXS];
public:
	CircularQueue() { front = rear = 0; }
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return front == (rear + 1) % MAX_VTXS;
	}
	void enqueue(int item) {
		if (isFull()) {
			cout << "error: 포화상태" << endl;
			exit(-1);
		}
		rear = (rear + 1) % MAX_VTXS;
		data[rear] = item;
	}
	int dequeue() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
			exit(-1);
		}
		front = (front + 1) % MAX_VTXS;
		return data[front];
	}
	int peek() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
		}
		else {
			return data[(front + 1) % MAX_VTXS];
		}
	}
	void display() {
		int maxi = (front < rear) ? rear : rear + MAX_VTXS;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
class Node {
protected:
	int id; //정점의 id
	Node* link; //다음 노드의 포인터
public:
	Node(int i, Node* l = NULL) {
		id = i;
		link = l;
	}
	~Node() {
		if (link != NULL) delete link;
	}
	int getId() { return id; }
	Node* getLink() { return link; }
	void setLink(Node* l) { link = l; }
};

class AdjListGraph {
protected:
	int size;
	char vertices[MAX_VTXS];
	Node* adj[MAX_VTXS];
public:
	AdjListGraph() :size(0) {}
	~AdjListGraph() { reset(); }
	void reset(void) {
		for (int i = 0; i < size; i++) {
			if (adj[i] != NULL)
				delete adj[i];
		}
		size = 0;
	}

	//정점 삽입
	void insertVertex(char val) {
		if (!isFull()) {
			vertices[size] = val; //vertex배열에 값 넣기
			adj[size++] = NULL; //adj[size]를 NULL로 초기화
		}
		else printf("Error: 그래프 정점 개수 초과\n");
	}

	//간선 삽입
	void insertEdge(int u, int v) { //간선 삽입 연산
		adj[u] = new Node(v, adj[u]); //인접 리스트에 추가
		adj[v] = new Node(u, adj[v]);
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
			for (Node* v = adj[i]; v != NULL; v = v->getLink())
				printf(" %c", getVertex(v->getId()));
			printf("\n");
		}
	}

	bool isEmpty() { return size == 0; }
	bool isFull() {
		return size >= MAX_VTXS;
	}
	char getVertex(int i) { return vertices[i]; }
};

class SrchALGraph :public AdjListGraph {
	bool visited[MAX_VTXS];
public:
	void resetVisited() {
		for (int i = 0; i < size; i++)
			visited[i] = false;
	}
	bool isLinked(int u, int v) {
		for (Node* p = adj[u]; p != NULL; p = p->getLink())
			if (p->getId() == v) return true;
		return false;
	}
	void BFS(int v) {
		visited[v] = true;
		printf("%c ", getVertex(v));
		CircularQueue que;
		que.enqueue(v);
		while (!que.isEmpty()) {
			int v = que.dequeue();
			for (Node* w = adj[v]; w != NULL; w = w->getLink()) {
				int id = w->getId();
				if (!visited[id]) {
					visited[id] = true;
					printf("%c ", getVertex(id));
					que.enqueue(id);
				}
			}
		}
	}
};

int main() {
	SrchALGraph g;
	g.load();
	g.display();
	
	printf("BFS==> ");
	g.resetVisited();
	g.BFS(0);
	printf("\n");


}*/