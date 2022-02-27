#include <iostream>
#define MAX_SIZE 200
using namespace std;

class HeapNode {
	int key; //��� Ű��
public:
	HeapNode(int k = 0) :key(k) {}
	void setKey(int k) { key = k; }
	int getKey() { return key; }
	void display() { printf("%4d", key); }
};
class MinHeap {
	HeapNode node[MAX_SIZE];
	int size;
public:
	MinHeap() : size(0) {}
	bool isEmpty() { return size == 0; }
	bool isFull() { return size == MAX_SIZE - 1; }

	HeapNode& getParent(int i) { return node[i / 2]; } //�θ� ���
	HeapNode& getLeft(int i) { return node[i * 2]; } //���� �ڽ� ���
	HeapNode& getRight(int i) { return node[i * 2 + 1]; } //������ �ڽ� ���

	void insert(int key); //���� �Լ�
	HeapNode remove(); //���� �Լ�
	HeapNode find() { return node[1]; } //��Ʈ ��� ��ȯ
	void display();

};

void MinHeap::insert(int key) {
	if (isFull()) return; //���� ���� �� ���
	//�� ��带 ������ ������ �ε��� ����
	int i = ++size; // i=�ű� ������ �ڸ�
	//�� ��尡 �ּ��� ������ �����ϵ��� �ø�
	while (i != 1 && key < getParent(i).getKey()) { //�θ𺸴� Ű���� ���� ��� �ݺ�
		node[i] = getParent(i); //�θ� �ڽ� �ڸ��� ����
		i /= 2; //Ʈ�� �� ���� ������ �ٽ� ��
	}
	node[i].setKey(key); //���� ��ġ�� �ű� Ű�� ����
}

HeapNode MinHeap::remove() {
	if (isEmpty()) { cout << "empty error !" << endl; exit(-1); }
	HeapNode item = node[1]; //��Ʈ ���
	HeapNode last = node[size--]; //������ ���
	int parent = 1; //��Ʈ ��� �ε���
	int child = 2; //��Ʈ�� ���� �ڽ� �ε���
	while (child <= size) { //�� Ʈ�� ũ�� ������
		//�ڽ� �ε��� �� �� ����
		if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
			child++; //������ �ڽ��� ������ ���������� ��
		if (last.getKey() <= node[child].getKey())
			break; //�ڽ� ��庸�� ������ ������

		node[parent] = node[child];  //�θ��尡 �ڽ� ��庸�� ũ�� ��ȯ

		parent = child; //�� �ܰ� �Ʒ� ������ �̵�
		child *= 2;
	}
	node[parent] = last; //���� ��ġ�� ������ ���
	return item; //������ ��Ʈ ��� ��ȯ
}

void MinHeap::display() {
	for (int i = 1, level = 1; i <= size; i++) {
		if (i == level) {
			printf("\n");
			level *= 2; //Ʈ�� ���� �� ���
		}
		node[i].display();
	}
	printf("\n-----------------------------------------------------------");
}

int main() {
	MinHeap heap;
	heap.insert(10);
	heap.insert(5);
	heap.insert(30);
	heap.insert(8);
	heap.insert(9);
	heap.insert(3);
	heap.insert(7);
	heap.display();

	heap.remove();
	heap.display();
	heap.remove();
	heap.display();
	printf("\n");
}