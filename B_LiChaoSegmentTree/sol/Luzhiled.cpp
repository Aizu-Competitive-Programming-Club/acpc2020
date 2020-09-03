#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr i64 infll = 1001001001001001001;

int main() {
    int n, q;
    cin >> n >> q;

    vector< i64 > as(n), bs(n);
    for (int i = 0; i < n; ++i) {
        cin >> as[i] >> bs[i];
    }

    while (q--) {
        int l, r, p;
        cin >> l >> r >> p;

        i64 ans = infll;
        for (int i = l - 1; i < r; ++i) {
            ans = min(ans, as[i] * p + bs[i]);
        }

        cout << ans << endl;
    }
}
