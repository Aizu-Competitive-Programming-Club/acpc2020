#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n, q;
    vector<long long> a, b;
    long long l, r, x;

    cin >> n >> q;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> l >> r >> x;
        l--;

        long long ans = 1ll << 60ll;
        for (int j = l; j < r; j++) {
            ans = min(ans, a[j] * x + b[j]);
        }

        cout << ans << '\n';
    }

    return 0;
}
