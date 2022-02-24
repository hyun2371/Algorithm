#include <iostream>
using namespace std;
#define MAX_SIZE 100
class CircularQueue {
protected:
	int front;
	int rear;
	int data[MAX_SIZE];
public:
	CircularQueue() { front = rear = 0; }

	bool isEmpty() {
		return front == rear;
	}

	bool isFull() {
		return front == (rear + 1) % MAX_SIZE;
	}

	void enqueue(int item) {
		if (isFull()) {
			cout << "error: 포화상태" << endl;
			exit(-1);
		}
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = item;
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
			exit(-1);
		}
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}

	int peek() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
		}
		else {
			return data[(front + 1) % MAX_SIZE];
		}
	}
	void display() {
		int maxi = (front < rear) ? rear : rear + MAX_SIZE;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i%MAX_SIZE] << " ";
		}
		cout << endl;
	}
};

class CircularDeque : public CircularQueue { //클래스 상속
public:
	CircularDeque() { }

	void addFront(int item) {
		if (isFull()) {
			cout << "error: 포화상태" << endl;
			exit(-1);
		}
		data[front] = item;
		front = (front - 1 + MAX_SIZE) % MAX_SIZE;
	}

	int deleteFront() {
		return dequeue();
	}

	void addRear(int item) {
		enqueue(item);
	}

	int deleteRear() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
			exit(-1);
		}
	
		int tmp = data[rear];
		rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
		return tmp;
		
	}

	int getFront() {
		return peek();
	}

	int getRear() {
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
		}
		else
			return data[rear];
	}

};

int main() {
	CircularDeque deq;
	for (int i = 1; i < 10; i++) {
		if (i % 2 != 0)
			deq.addFront(i);
		else
			deq.addRear(i);
	}
	
	deq.display();
	deq.deleteFront();
	deq.deleteRear();
	deq.deleteFront();
	deq.display();
}