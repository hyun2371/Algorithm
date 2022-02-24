/*#include <iostream>
using namespace std;
#define MAX_SIZE 100
class CircularQueue {
private:
	int front;
	int rear;
	int data[MAX_SIZE];
public:
	CircularQueue() { front = rear = 0; }

	bool isEmpty() {
		return front == rear;
	}

	bool isFull(){
		return front == (rear + 1) % MAX_SIZE;
	}

	void enqueue(int item){
		if (isFull()) {
			cout << "error: 포화상태" << endl;
			exit(-1);
		}
		rear = (rear + 1) % MAX_SIZE;
		data[rear] = item;
	}

	int dequeue(){
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
			exit(-1);
		}
		front = (front + 1) % MAX_SIZE;
		return data[front];
	}

	int peek(){
		if (isEmpty()) {
			cout << "error: 공백상태" << endl;
		}
		else {
			return data[(front + 1) % MAX_SIZE];
		}
	}
	void display(){
		int maxi = (front < rear) ? rear : rear + MAX_SIZE;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}
};
int main() {
	CircularQueue q;
	for (int i = 1; i < 10; i++)
		q.enqueue(i);
	q.display();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.display();
}*/