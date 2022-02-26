#include <iostream>
#define MAX_STACK_SIZE 100000
using namespace std;
class Stack {
	int top;
	int data[MAX_STACK_SIZE];
public:
	Stack() { top = -1; }
	bool isEmpty() { return top == -1; } //초기화 했을 때와 같은 값스택 비어있음
	void push(int p) {
		data[++top] = p;
	}
	int pop() {
		return data[top--];
	}
};
int main() {
	Stack s; //스택 클래스 활용하기 위해 s객체 생성
	int tries; //입력받을 수 의 개수
	cin >> tries;
	int userInput;//입력값
	for (int i = 0; i < tries; i++) {
		cin >> userInput;
		if (userInput == 0) //잘못 쓴 값
			s.pop();
		else
			s.push(userInput);
	}
	//스택에 남아있는 요소를 더해 출력
	int total = 0; //합
	while (!s.isEmpty()) {
		total += s.pop();
	}
	cout << total;
}
