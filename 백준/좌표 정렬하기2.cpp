#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> v1, pair<int,int> v2) {
	if (v1.second==v2.second) {
		return v1.first < v2.first; //y��ǥ�� ���ٸ�, x��ǥ�� ���� �������
	}
	
	return v1.second < v2.second; //y��ǥ�� ���� �������
	//�������� <

}
int main() {
	int tries;
	cin >> tries;
	vector<pair<int, int>> v(tries);

	for (int i = 0; i < tries; i++) {
		scanf_s("%d", &v[i].first);
		scanf_s("%d", &v[i].second);
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < tries; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}

}