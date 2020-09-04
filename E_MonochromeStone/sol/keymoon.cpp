#include <bits/stdc++.h>

#define var auto
#define ll long long

using namespace std;

int main() {
	int n, initW, initB;
	cin >> n >> initW >> initB;
	vector<int> maxBlack(initW + 1, -1);
	maxBlack[0] = 0;
	for (int i = 0; i < n; i++) {
		int w, b;
		cin >> w >> b;
		for (int j = initW; j >= 0; j--) {
			if (maxBlack[j] == -1) continue;
			if (j + w <= initW) maxBlack[j + w] = max(maxBlack[j + w], maxBlack[j]);
			maxBlack[j] += b;
		}
	}
	var res = 0;
	for (int i = 0; i < initW; i++) {
		if (maxBlack[i] == -1) continue;
		res = max(res, min(maxBlack[i], initB) + i);
	}
	cout << res << endl;
}
