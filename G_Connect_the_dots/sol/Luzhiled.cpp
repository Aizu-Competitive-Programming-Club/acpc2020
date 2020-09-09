#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int S = 1 << 17; // ( > 100000 )
constexpr int inf = 1001001001;

struct edge {
    int to, cost;

    edge() {}
    edge(int to, int cost) : to(to), cost(cost) {}
};

using Graph = vector< vector< edge > >;

inline void add_edge(int v, int u, int c, Graph &G) {
//    cerr << "add_edge: " << v << " -(" << c << ")> " << u << endl;
    G[v].emplace_back(u, c);
}

// [l, r) <-> v
// y: base = S
// x: base = 3S
inline void add_range(int v, int l, int r, int base, Graph &G, int a = 0, int b = S, int idx = 0) {
    if (l <= a && b <= r) {
        add_edge(v, idx + base, 1, G);
        add_edge(idx + base + 4 * S, v, 1, G);
        return;
    }

    if (r <= a || b <= l) {
        return;
    }

    int mid = (a + b) / 2;
    add_range(v, l, r, base, G, a, mid, 2 * idx + 1);
    add_range(v, l, r, base, G, mid, b, 2 * idx + 2);
}

// y, x is complessed
inline void add_v_to_xy(int v, int y, int x, Graph &G) {
    int to_y = y + S - 1 + S;
    int to_x = x + S - 1 + 3 * S;
    int from_y = y + S - 1 + 5 * S;
    int from_x = x + S - 1 + 7 * S;

    add_edge(v, to_y, 0, G);
    add_edge(v, to_x, 0, G);
    add_edge(to_y, v, 0, G);
    add_edge(to_x, v, 0, G);

    add_edge(v, from_y, 0, G);
    add_edge(v, from_x, 0, G);
    add_edge(from_y, v, 0, G);
    add_edge(from_x, v, 0, G);
}

void build_range(Graph &G) {
    { // to y
        int base = S;
        for (int i = 0; i < S - 1; ++i) {
            add_edge(i + base, 2 * i + 1 + base, 0, G);
            add_edge(i + base, 2 * i + 2 + base, 0, G);
        }
    }

    { // to x
        int base = 3 * S;
        for (int i = 0; i < S - 1; ++i) {
            add_edge(i + base, 2 * i + 1 + base, 0, G);
            add_edge(i + base, 2 * i + 2 + base, 0, G);
        }
    }

    { // from y
        int base = 5 * S;
        for (int i = 0; i < S - 1; ++i) {
            add_edge(2 * i + 1 + base, i + base, 0, G);
            add_edge(2 * i + 2 + base, i + base, 0, G);
        }
    }

    { // from x
        int base = 7 * S;
        for (int i = 0; i < S - 1; ++i) {
            add_edge(2 * i + 1 + base, i + base, 0, G);
            add_edge(2 * i + 2 + base, i + base, 0, G);
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
        zip_y.emplace_back(ys[i]);
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

    Graph G(9 * S);

    build_range(G);

    for (int i = 0; i < n; ++i) {
        add_v_to_xy(i, ys[i], xs[i], G);
    }


    vector< pair< pair< int, int >, int > > pys(n), pxs(n);
    for (int i = 0; i < n; ++i) {
        pys[i] = make_pair(make_pair(ys[i], xs[i]), i);
        pxs[i] = make_pair(make_pair(xs[i], ys[i]), i);
    }

    sort(pys.begin(), pys.end());
    sort(pxs.begin(), pxs.end());

    for (int i = 1; i < n; ++i) {
        if (pys[i].first.first != pys[i - 1].first.first) continue;
        int l = pys[i - 1].first.second;
        int r = pys[i].first.second + 1;

        int v = pys[i].second;
        int u = pys[i - 1].second;
        add_edge(u, v, 0, G);
        add_edge(v, u, 0, G);
        add_range(v, l, r, 3 * S, G);
    }

    for (int i = 1; i < n; ++i) {
        if (pxs[i].first.first != pxs[i - 1].first.first) continue;
        int l = pxs[i - 1].first.second;
        int r = pxs[i].first.second + 1;

        int v = pxs[i].second;
        int u = pxs[i - 1].second;
        add_edge(u, v, 0, G);
        add_edge(v, u, 0, G);
        add_range(v, l, r, S, G);
    }

    vector< int > ds(9 * S, inf);
    ds[0] = 0;

    deque< int > que;
    que.push_front(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop_front();

        for (const auto &e: G[v]) {
            if (ds[e.to] <= ds[v] + e.cost) {
                continue;
            }

            ds[e.to] = ds[v] + e.cost;

            if (e.cost == 0) {
                que.push_front(e.to);
            } else {
                que.push_back(e.to);
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
