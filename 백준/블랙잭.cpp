#include <iostream>
using namespace std;
int main() {
	int card[100];
	int n, answer, near, tmp;
	bool isFinish = false;
	cin >> n >> answer;
	for (int i=0;i<n;i++)
		cin >> card[i];

	near = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = 1; j < n-1; j++) {
			for (int k = 2; k < n; k++) {
				if (i == j || j == k || k == i) continue; //카드 중복x
				tmp = card[i] + card[j] + card[k];
				if (tmp == answer) { //원하는 수와 일치
					near = tmp;
					isFinish = true; break;
				}
				if (tmp>answer ) continue; //원하는 수보다 크면 안됨
				if (answer - near > answer - tmp)//근사한값
					near = tmp;
			}
			if (isFinish) break; //원하는 값 찾으면 반복 종료
		}
		if (isFinish) break;
	}
	cout << near;
