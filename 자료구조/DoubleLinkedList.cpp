#include <iostream>
using namespace std;
class Node2 {
	int data;
public:
	Node2* prev;
	Node2* next;
public:
	Node2(int val = 0) { data = val; prev = NULL; next = NULL; }
	Node2* getNext() { return next; }
	Node2* getPrev() { return prev; }
	void setPrev(Node2* p) { prev = p; }
	void setNext(Node2* n) { next = n; }
	void display() { printf("<%d>", data); }
	bool hasData(int val) { return data == val; }
	void insertNext(Node2* n) {
		if (n != NULL) {
			//먼저 삽입할 노드 양쪽 연결
			n->prev = this; 
			n->next = next;
			//이전의 두 노드 양쪽 연결
			if (next != NULL) 
				next->prev = n;
			next = n;
		}
	}
	Node2* remove() {
		if (prev != NULL) {
			prev->next = next;
		}
		if (next != NULL) {
			next->prev = prev;
		}
		return this;
	}
};
class DblLinkedList {
	Node2 org;
public:
	DblLinkedList() { org = 0; }
	//앞에서부터 모든 노드 제거
	void clear() { 
		while (!isEmpty()) delete remove(0); 
	}

	bool isEmpty() { return getHead()==NULL; }

	Node2* getHead() {
		return org.getNext();
	}

	Node2* getEntry(int pos) {
		Node2* n = &org;
		for (int i = -1; i < pos; i++, n = n->getNext())
			if (n == NULL) break;
		return n;
	}

	void insert(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNext(n);
		}
	}

	Node2* remove(int pos) {
		Node2* n = getEntry(pos);
		return n->remove();
	}

	Node2* find(int val) {
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			if (p->hasData(val)) return p;
		return NULL;
	}

	void replace(int pos, Node2* n) {
		Node2* prev = getEntry(pos - 1);
		if (prev != NULL) {
			delete (prev->getNext())->remove();
			prev->insertNext(n);
		}
	}

	int size() {
		int count = 0;
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			count++;
		return count;
	}
	void display() {
		cout << "[이중연결리스트 항목 수] " << size() << endl;
		for (Node2* p = getHead(); p != NULL; p = p->getNext())
			p->display();
		cout << endl;
	}
};
int main() {
	DblLinkedList list;
	list.insert(0, new Node2(10));
	list.insert(0, new Node2(20));
	list.insert(1, new Node2(30));
	list.insert(list.size(), new Node2(40));
	list.insert(2, new Node2(50));
	list.display();
	list.remove(2);
	list.remove(list.size() - 1);
	list.remove(0);
	list.replace(1, new Node2(90));
	list.display();
	list.clear();
	list.display();
}