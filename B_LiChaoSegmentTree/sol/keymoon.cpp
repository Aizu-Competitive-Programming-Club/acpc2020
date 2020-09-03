#include <bits/stdc++.h>

#define var auto
#define in :
#define ll long long

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<pair<ll, ll>> lines{};
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		lines.emplace_back(a, b);
	}
	for (int i = 0; i < q; i++) {
		ll l, r, p;
		cin >> l >> r >> p;
		l--, r--;
		ll res = INT64_MAX;
		for (int j = l; j <= r; j++) {
			res = min(res, lines[j].first * p + lines[j].second);
		}
		cout << res << endl;
	}
}
