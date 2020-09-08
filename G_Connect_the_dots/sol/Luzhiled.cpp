#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int S = 1 << 17; // ( > 100000 )

struct edge {
    int to, cost;

    edge() {}
    edge(int to, int cost) : to(to), cost(cost) {}
};

using Graph = vector< vector< edge > >;

// v to [l, r)
// base: S or 3S
void add_edge(int v, int l, int r, int base, int cost, Graph &G, int a = 0, int b = S, int idx = 0) {
    if (l <= a && b <= r) {
        G[v].emplace_back(idx + base, cost);
        return;
    }

    if (r <= a || b <= l) {
        return;
    }

    int mid = (a + b) / 2;
    add_edge(v, l, r, base, cost, G, a, mid, 2 * idx + 1);
    add_edge(v, l, r, base, cost, G, mid, b, 2 * idx + 2);
}

// y, x is complessed
void add_edge(int v, int y, int x, Graph &G) {
    int y_idx = y + S - 1 + S;
    int x_idx = x + S - 1 + 3 * S;

    G[v].emplace_back(y_idx, 0);
    G[y_idx].emplace_back(v, 0);
    G[v].emplace_back(x_idx, 0);
    G[x_idx].emplace_back(v, 0);
}

int main() {
    int n;
    cin >> n;

    vector< int > xs(n), ys(n);
    vector< int > zip_x(n), zip_y(n);

    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
        zip_x[i] = xs[i];
        zip_y[i] = ys[i];
    }

    sort(zip_x.begin(), zip_x.end());
    sort(zip_y.begin(), zip_y.end());
    zip_x.erase(unique(zip_x.begin(), zip_x.end()), zip_x.end());
    zip_y.erase(unique(zip_y.begin(), zip_y.end()), zip_y.end());

    for (auto &x: xs) {
        x = lower_bound(zip_x.begin(), zip_x.end(), x) - zip_x.begin();
    }

    for (auto &y: ys) {
        y = lower_bound(zip_y.begin(), zip_y.end(), y) - zip_y.begin();
    }

    for (auto x: xs) cerr << x << " ";
    cerr << endl;
    for (auto y: ys) cerr << y << " ";
    cerr << endl;

    Graph G(5 * S);
    for (int i = 0; i < n; ++i) {
        add_edge(i, ys[i], xs[i], G);
    }

    vector< pair< int, int > > pys(n), pxs(n);
    for (int i = 0; i < n; ++i) {
        pys[i] = make_pair(ys[i], xs[i]);
        pxs[i] = make_pair(xs[i], ys[i]);
    }

    sort(pys.begin(), pys.end());
    sort(pxs.begin(), pxs.end());
}

