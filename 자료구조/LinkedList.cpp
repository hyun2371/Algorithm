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
	Node org; //��� ���
public:
	LinkedList() { org = 0; }
	Node* getHead() { return org.getLink(); } //��� ��� ��ȯ
	//bool isEmpty() { return getHead() == NULL; }
	void clear() {
		while (!isEmpty())
			//�� ������ ���ʴ�� ����
			delete remove(0);
	}

	//pos��° ��� ��ȯ
	Node* getEntry(int pos) {
		Node* n = &org;
		//i: �� ��° ������� ��/ n: i��° ��� ��ȯ
		//i�� �÷����鼭  pos��° ��尡 �ִ��� Ž��
		//pos��° ��尡 ������ �ش� ����� �ּҸ� ��ȯ
		//������ ���� ������ NULL�� ��ȯ
		for (int i = -1; i < pos; i++, n = n->getLink())
			if (n == NULL) break;
		return n;
	}

	//pos ��ġ�� ��� ����
	void insert(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->insertNext(n);
		}
	}

	//pos��ġ�� ��� ����
	Node* remove(int pos) {
		Node* prev = getEntry(pos - 1);
		return prev -> removeNext();
	}

	//pos��ġ�� ���� ��� ��ü
	void replace(int pos, Node* n) {
		Node* prev = getEntry(pos - 1);
		if (prev != NULL) {
			prev->removeNext();
			prev->insertNext(n);
		}
	}

	void display() {
		cout << "[��ü �׸� ��=]: " << size() << endl;
		for (Node* p = getHead(); p != NULL; p = p->getLink()) {
			p->display();
		}
		cout << endl;
	}
	//���Ḯ��Ʈ ����� ���� ��ȯ
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