#include <iostream>
#include <algorithm> //sort»ç¿ë
#include <vector>

using namespace std;
int main() {
	int tries;
	cin >> tries;
	vector <pair<int, int>> v(tries); //ÁÂÇ¥½Ö

	
	for (int i = 0; i < tries; i++) {
		scanf("%d", &v[i].first);
		scanf("%d", &v[i].second);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < tries; i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}
	
}