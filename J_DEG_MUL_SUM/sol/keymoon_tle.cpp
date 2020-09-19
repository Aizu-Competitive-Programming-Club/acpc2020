#include <bits/stdc++.h>

#define var auto
#define ll long long

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<ll> degree(n, 0);
	vector<unordered_set<int>> adjs(n, unordered_set<int>{});

	var calc = [&](int vertex) {
		int deg_sum = 0;
		for (var&& adj : adjs[vertex]) deg_sum += degree[adj];
		return deg_sum * degree[vertex];
	};

	ll cur_res = 0;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;

		cur_res -= calc(u);
		cur_res -= calc(v);

		bool inserted = adjs[u].insert(v).second && adjs[v].insert(u).second;
		if (!inserted) {
			adjs[u].erase(v);
			adjs[v].erase(u);
		}
		if (!inserted) cur_res += degree[u] * degree[v];

		var incr = inserted ? 1 : -1;
		degree[u] += incr;
		degree[v] += incr;
		
		cur_res += calc(u);
		cur_res += calc(v);

		if (inserted) cur_res -= degree[u] * degree[v];

		cout << cur_res << endl;
	}
}
