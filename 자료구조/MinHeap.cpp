#include <iostream>
#define MAX_SIZE 200
using namespace std;

class HeapNode {
	int key; //노드 키값
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

	HeapNode& getParent(int i) { return node[i / 2]; } //부모 노드
	HeapNode& getLeft(int i) { return node[i * 2]; } //왼쪽 자식 노드
	HeapNode& getRight(int i) { return node[i * 2 + 1]; } //오른쪽 자식 노드

	void insert(int key); //삽입 함수
	HeapNode remove(); //삭제 함수
	HeapNode find() { return node[1]; } //루트 노드 반환
	void display();

};

void MinHeap::insert(int key) {
	if (isFull()) return; //힙이 가득 찬 경우
	//새 노드를 삽입할 마지막 인덱스 결정
	int i = ++size; // i=신규 삽입할 자리
	//새 노드가 최소힙 성질을 만족하도록 올림
	while (i != 1 && key < getParent(i).getKey()) { //부모보다 키값이 작은 경우 반복
		node[i] = getParent(i); //부모를 자식 자리로 내림
		i /= 2; //트리 한 레벨 위에서 다시 비교
	}
	node[i].setKey(key); //최종 위치에 신규 키값 저장
}

HeapNode MinHeap::remove() {
	if (isEmpty()) { cout << "empty error !" << endl; exit(-1); }
	HeapNode item = node[1]; //루트 노드
	HeapNode last = node[size--]; //마지막 노드
	int parent = 1; //루트 노드 인덱스
	int child = 2; //루트의 왼쪽 자식 인덱스
	while (child <= size) { //힙 트리 크기 내에서
		//자식 인덱스 왼 오 결정
		if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
			child++; //오른쪽 자식이 작으면 오른쪽으로 감
		if (last.getKey() <= node[child].getKey())
			break; //자식 노드보다 작으면 오케이

		node[parent] = node[child];  //부모노드가 자식 노드보다 크면 교환

		parent = child; //한 단계 아래 레벨로 이동
		child *= 2;
	}
	node[parent] = last; //최종 위치에 마지막 노드
	return item; //삭제한 루트 노드 반환
}

void MinHeap::display() {
	for (int i = 1, level = 1; i <= size; i++) {
		if (i == level) {
			printf("\n");
			level *= 2; //트리 다음 줄 출력
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