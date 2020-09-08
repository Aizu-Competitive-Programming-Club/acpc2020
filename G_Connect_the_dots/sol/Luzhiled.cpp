#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int S = 1 << 19; // ( > 3 * 100000 )
constexpr int inf = 1001001001;

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
//        cerr << v << " -1> " << "[" << l << ", " << r << ")";
//        if (base == S) cerr << "(y)" << endl;
//        else cerr << "(x)" << endl;
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

//    cerr << v << " -0> " << y << "(y)" << endl;
//    cerr << v << " -0> " << x << "(x)" << endl;
//    cerr << y << "(y)" << " -0> " << v << endl;
//    cerr << x << "(x)" << " -0> " << v << endl;

    G[v].emplace_back(y_idx, 0);
    G[y_idx].emplace_back(v, 0);
    G[v].emplace_back(x_idx, 0);
    G[x_idx].emplace_back(v, 0);
}

void build_range(Graph &G) {
    { // y
        int base = S;
        for (int i = 0; i < S - 1; ++i) {
            G[i + base].emplace_back(2 * i + 1 + base, 0);
            G[i + base].emplace_back(2 * i + 2 + base, 0);
        }
    }

    { // x
        int base = 3 * S;
        for (int i = 0; i < S - 1; ++i) {
            G[i + base].emplace_back(2 * i + 1 + base, 0);
            G[i + base].emplace_back(2 * i + 2 + base, 0);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector< int > xs(n), ys(n);
    vector< int > zip_x, zip_y;

    for (int i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
        zip_x.emplace_back(xs[i]);
        zip_x.emplace_back(xs[i] - 1);
        zip_x.emplace_back(xs[i] + 1);
        zip_y.emplace_back(ys[i]);
        zip_y.emplace_back(ys[i] - 1);
        zip_y.emplace_back(ys[i] + 1);
    }

    sort(zip_x.begin(), zip_x.end());
    sort(zip_y.begin(), zip_y.end());
    zip_x.erase(unique(zip_x.begin(), zip_x.end()), zip_x.end());
    zip_y.erase(unique(zip_y.begin(), zip_y.end()), zip_y.end());

//    cerr << "x size: " << zip_x.size() << endl;
//    cerr << "y size: " << zip_y.size() << endl;

    for (auto &x: xs) {
        x = lower_bound(zip_x.begin(), zip_x.end(), x) - zip_x.begin();
    }

    for (auto &y: ys) {
        y = lower_bound(zip_y.begin(), zip_y.end(), y) - zip_y.begin();
    }

//    for (auto x: xs) cerr << x << " ";
//    cerr << endl;
//    for (auto y: ys) cerr << y << " ";
//    cerr << endl;

    Graph G(5 * S);

    build_range(G);

    for (int i = 0; i < n; ++i) {
        add_edge(i, ys[i], xs[i], G);
    }

    vector< pair< int, pair< int, int > > > pys(n), pxs(n);
    for (int i = 0; i < n; ++i) {
        pys[i] = make_pair(ys[i], make_pair(i, xs[i]));
        pxs[i] = make_pair(xs[i], make_pair(i, ys[i]));
    }

    sort(pys.begin(), pys.end());
    sort(pxs.begin(), pxs.end());

    for (int i = 1; i < n; ++i) {
        if (pys[i].first != pys[i - 1].first) continue;
//        cerr << "y: " << i << endl;
        int l = pys[i - 1].second.second + 1;
        int r = pys[i].second.second;

        add_edge(pys[i].second.first, l, r, 3 * S, 1, G);
    }

    for (int i = 1; i < n; ++i) {
        if (pxs[i].first != pxs[i - 1].first) continue;
//        cerr << "x: " << i << endl;
        int l = pxs[i - 1].second.second + 1;
        int r = pxs[i].second.second;

        add_edge(pxs[i].second.first, l, r, S, 1, G);
    }

    using pii = pair< int, int >;
    priority_queue< pii, vector< pii >, greater< pii > > pq;

    vector< int > ds(5 * S, inf);
    pq.emplace(0, 0);
    ds[0] = 0;

    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();

        int v = p.second;
        if (ds[v] < p.first) continue;

        for (const auto &e: G[v]) {
            if (ds[e.to] > ds[v] + e.cost) {
                ds[e.to] = ds[v] + e.cost;
                pq.emplace(ds[e.to], e.to);
            }
        }
    }

    int ans = ds[n - 1];
    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
