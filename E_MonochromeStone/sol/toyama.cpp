using i64 = long long;
#define _overload(_1, _2, _3, _4, name, ...) name
#define _rep1(Itr, N) _rep3(Itr, 0, N, 1)
#define _rep2(Itr, a, b) _rep3(Itr, a, b, 1)
#define _rep3(Itr, a, b, step) for (i64 Itr = a; (Itr) < b; (Itr) += step)
#define repeat(...) _overload(__VA_ARGS__, _rep3, _rep2, _rep1)(__VA_ARGS__)

#include <iostream>
using namespace std;
using llong = long long;

int N, W, B;
int w[5005];
int b[5005];
int dp[5005][5005];

int main() {
	cin >> N >> W >> B;
	repeat(i, 1, N + 1) cin >> w[i] >> b[i];

	repeat(i, 5005) repeat(j, 5005) dp[i][j] = -100000;
	dp[0][0] = 0;

	// dp[i][j] := i:card, j:sum_ws, maximum bs

	repeat(i, 1, N + 1) {
		repeat(j, W + 1) {
			if (j >= w[i]) {
				dp[i][j] = max<int>(dp[i - 1][j - w[i]], min(B, dp[i - 1][j] + b[i]));
			}
			else {
				dp[i][j] = min<int>(B, dp[i - 1][j] + b[i]);
			}
		}
	}

	int ans = 0;
	repeat(i, W + 1) {
		ans = max<int>(ans, i + dp[N][i]);
	}

	cout << ans << endl;

    return 0;
};
