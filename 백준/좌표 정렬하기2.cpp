#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> v1, pair<int,int> v2) {
	if (v1.second==v2.second) {
		return v1.first < v2.first; //y좌표가 같다면, x좌표가 작은 순서대로
	}
	
	return v1.second < v2.second; //y좌표가 작은 순서대로
	//오름차순 <

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