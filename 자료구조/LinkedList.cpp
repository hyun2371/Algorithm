/*#include <iostream>
using namespace std;
class Node {
	Node* link;
	int data;
public:
	Node(int val = 0) {
		data = val;
		link = NULL;
	}
	Node* getLink() { return link; }
	void setLink(Node* next) {
		link = next;
	}

	void display() {
		printf("<%d> ", data);
	}
	bool hasData(int val) {
		return data == val;
	}

	void insertNext(Node* n) {
		if (n != NULL) {
			n->link = link;
			link = n;
		}
	}
	Node* removeNext() {
		Node* removed = link;
		if (removed != NULL) {
			link = removed->link;
		}
		return removed;
	}

};
class LinkedList {
	Node org; //헤드 노드
public:
	LinkedList() { org = 0; }
	Node* getHead() { return org.getLink(); } //헤드 노드 반환
	//bool isEmpty() { return getHead() == NULL; }
	void clear() {
		while (!isEmpty())
			//앞 노드부터 차례대로 제거
			delete remove(0);
	}

	//pos번째 노드 반환
	Node* getEntry(int pos) {
		Node* n = &org;
		//i: 몇 번째 노드인지 셈/ n: i번째 노드 반환
		//i를 늘려가면서  pos번째 노드가 있는지 탐색
		//pos번째 노드가 있으면 해당 노드의 주소를 반환
		//끝까지 가도 없으면 NULL을 반환
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	//pos 위치에 노드 삽입
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNext(n);
		}
	}

	//pos위치의 노드 삭제
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev -> removeNext();
	}

	//pos위치에 기존 노드 대체
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->removeNext();
			prev->insertNext(n);
		}
	}

	void display() {
		cout << "[전체 항목 수=]: " << size() << endl;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			p->display();
		}
		cout << endl;
	}
	//연결리스트 노드의 개수 반환
	int size() {
		int count = 0;
		for (Node* p = getHead(); p != NULL; p = p->getLink())
			count++;
		return count;
	}
};
int main() {
	LinkedList list;
	list.insert(0, new Node(10));
	list.insert(0, new Node(20));
	list.insert(1, new Node(30));
	list.insert(list.size(), new Node(40));
	list.insert(2, new Node(50));
	list.display();
	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node(90));
	list.display();
	list.clear();
	list.display();
}*/