#include <bits/stdc++.h>

#define var auto
#define ll long long

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	var sqrtq = (int)ceil(sqrt(q));
	vector<ll> degree(n, 0);
	vector<pair<int, int>> query{};
	vector<unordered_set<int>> adjs(n, unordered_set<int>{});
	
	vector<int> large_degs;
	vector<bool> is_large_deg(n, false);
	vector<ll> adj_deg_sum(n, 0);

	{
		unordered_set<int> _large_deg{};
		for (int i = 0; i < q; i++) {
			int u, v;
			cin >> u >> v;
			u--; v--;
			query.emplace_back(u, v);
			if (!(adjs[u].insert(v).second && adjs[v].insert(u).second)) {
				adjs[u].erase(v);
				adjs[v].erase(u);
			}
			if (sqrtq <= (int)adjs[u].size()) { is_large_deg[u] = true; _large_deg.insert(u); }
			if (sqrtq <= (int)adjs[v].size()) { is_large_deg[v] = true; _large_deg.insert(v); }
		}
		large_degs = vector<int>(_large_deg.begin(), _large_deg.end());
	}

	adjs = vector<unordered_set<int>>(n, unordered_set<int>{});

	var calc = [&](int vertex) {
		int deg_sum = 0;
		if (is_large_deg[vertex]) {
			deg_sum = adj_deg_sum[vertex];
		}
		else {
			for (var&& adj : adjs[vertex]) deg_sum += degree[adj];
		}
		return deg_sum * degree[vertex];
	};

	ll cur_res = 0;
	for (var&& uv : query) {
		int u, v;
		tie(u, v) = uv;

		cur_res -= calc(u);
		cur_res -= calc(v);

		bool inserted;
		if (!(inserted = (adjs[u].insert(v).second && adjs[v].insert(u).second))) {
			adjs[u].erase(v);
			adjs[v].erase(u);
		}
		//除去された場合
		if (!inserted) cur_res += degree[u] * degree[v];

		var incr = inserted ? 1 : -1;

		if (is_large_deg[u]) adj_deg_sum[u] += incr * degree[v];
		if (is_large_deg[v]) adj_deg_sum[v] += incr * degree[u];

		var resolve_deg = [&](int vertex) {
			degree[vertex] += incr;
			for (var&& large_deg : large_degs) {
				if (adjs[large_deg].find(vertex) == adjs[large_deg].end()) continue;
				adj_deg_sum[large_deg] += incr;
			}
		};
		
		resolve_deg(u);
		resolve_deg(v);

		cur_res += calc(u);
		cur_res += calc(v);
		if (inserted) cur_res -= degree[u] * degree[v];

		cout << cur_res << endl;
	}
}
