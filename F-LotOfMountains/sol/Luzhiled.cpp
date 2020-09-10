#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map< int, double > mp;

    for (int i = 0; i < n; ++i) {
        int x, h, r;
        cin >> x >> h >> r;

        x *= 2;

        double t = (double)h / r;
        mp[x - r] += t;
        mp[x] -= 2 * t;
        mp[x + r] += t;
    }

    double ans = 0;
    double h = 0, dh = 0;

    auto iterl = mp.begin(), iterr = mp.begin();
    ++iterr;

    while (iterr != mp.end()) {
        dh += iterl->second;
        h += (iterr->first - iterl->first) * dh;

        ans = max(ans, h);

        ++iterr;
        ++iterl;
    }

    cout << fixed << setprecision(10) << ans << endl;
}
