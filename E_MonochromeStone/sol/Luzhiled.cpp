#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1001001001;

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    vector< int > dp(s + 1, -inf);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        int w, b;
        cin >> w >> b;

        auto ndp = dp;
        for (int j = 0; j < (int)dp.size(); ++j) {
            ndp[j] += b;
        }

        for (int j = 0; j + w < (int)dp.size(); ++j) {
            ndp[j + w] = max(dp[j], dp[j + w]);
        }

        dp = ndp;
    }

    int ans = 0;
    for (int w = 0; w < s + 1; ++w) {
        ans = max(ans, w + min(dp[w], t));
    }

    cout << ans << endl;
}
