#include <bits/stdc++.h>

#define var auto
#define ll long long

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, double>> delta{};
	for (int i = 0; i < n; i++) {
		int x, h, r;
		cin >> x >> h >> r;
		//x *= 2;
		var angle = (double)h / r;
		delta.emplace_back(x - r, angle);
		delta.emplace_back(x, -2 * angle);
		delta.emplace_back(x + r, angle);
	}
	sort(delta.begin(), delta.end());
	double res = 0;
	double cur_height = 0;
	double cur_angle = 0;
	int cur_pos = 0;
	for (var&& pair : delta) {
		int pos; double d;
		tie(pos, d) = pair;
		cur_height += (pos - cur_pos) * cur_angle;
		res = max(res, cur_height);
		cur_angle += d;
		cur_pos = pos;
	}
	cout << res << endl;
}
