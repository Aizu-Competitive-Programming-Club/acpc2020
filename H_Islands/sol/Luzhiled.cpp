#include <bits/stdc++.h>
using namespace std;

// union find {{{
class union_find {

    using data_type = int_fast32_t;
    std::vector< data_type > data_;

    public:
    union_find(std::size_t size) : data_(size, -1) {}

    std::size_t size() const {
        return data_.size();
    }

    data_type get_root(data_type x) {
        return (data_[x] < 0 ? x : data_[x] = get_root(data_[x]));
    }

    bool is_root(data_type x) {
        return x == get_root(x);
    }

    bool is_same(data_type x, data_type y) {
        return get_root(x) == get_root(y);
    }

    void unite(data_type x, data_type y) {
        x = get_root(x); y = get_root(y);
        if (x == y) return;

        if (data_[x] > data_[y]) std::swap(x, y);
        data_[x] += data_[y];
        data_[y] = x;
    }

    data_type element_count(data_type x) {
        return -data_[get_root(x)];
    }
};
// }}}

template <typename T> vector<T> make_vector(size_t a, T b) { return vector<T>(a, b); }
template <typename... Ts> auto make_vector(size_t a, Ts... ts) { return vector<decltype(make_vector(ts...))>(a, make_vector(ts...)); }

int main() {
    constexpr int mod = 1 << 10;

    int h, w, q;
    cin >> h >> w >> q;

    h += 2;
    w += 2;

    auto bs = make_vector(h, w, '.');
    for (int i = 1; i < h - 1; ++i) {
        for (int j = 1; j < w - 1; ++j) {
            cin >> bs[i][j];
        }
    }

    int m = 0, t = 0, n = (h + 1) * (w + 1), f = 0;
    vector< bool > used(2 * h * w + h + w);
    union_find uf(n);

    auto edge_to_idx = [&](int a, int b) {
        if (a > b) swap(a, b);
        if (a + 1 == b) {
            return a - a / (w + 1);
        } else {
            return w * (h + 1) + a / (w + 1) + a % (w + 1) * h;
        }
    };

    bool is_preprocess = true;
    auto add_sea = [&](int y, int x) {
        // !assert
        if ( !is_preprocess ) {
            assert(bs[y][x] == '#');
            bs[y][x] = '.';
        }

        int ul = x + y * (w + 1);
        int dr = (x + 1) + (y + 1) * (w + 1);
        vector< int > as({ul, ul + 1, dr, dr - 1});

        for (int i = 0; i < 4; ++i) {
            int a = as[i], b = as[(i + 1) % 4];
            if (!uf.is_same(a, b)) {
                t--;
            }

            int idx = edge_to_idx(a, b);
            if (!used[idx]) {
                m++;
                used[idx] = true;
            }

            uf.unite(a, b);
        }

        f++;
    };

    for (int i = 0; i < n; ++i) {
        if (uf.is_root(i)) {
            t++;
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (bs[i][j] == '.') add_sea(i, j);
        }
    }

    is_preprocess = false;

    int s = 0;
    while (q--) {
        int u, v;
        cin >> u >> v;

        int r = (1 + (s ^ u)) % mod;
        int c = 1 + ((s ^ v)) % mod;

        // ! assert
        assert(1 <= r && r <= h - 2);
        assert(1 <= c && c <= w - 2);

        add_sea(r, c);

        int ans = m + t - n - f;
        cout << ans << endl;

        s = 427 * s + 821 * ans;
        s %= mod;
    }
}
