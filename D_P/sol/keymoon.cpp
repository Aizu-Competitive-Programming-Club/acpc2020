#include <bits/stdc++.h>

#define var auto
#define in :
#define ll long long

using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	vector<int> b(n);
	int bSum = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		bSum += b[i];
	}
	if (p - n >= bSum && bSum < p){
		cout << -1 << endl;
		return 0;
	}
	for (int cSum = 1; cSum <= n * p; cSum++) {
		vector<int> c(n);
		bool flag = false;
		for (int i = 0; i < n; i++) {
			c[i] = (cSum * b[i] + (p - 1)) / p;
			if (c[i] * p / cSum != b[i]) { flag = true; break; }
		}
		var curSum = accumulate(c.begin(), c.end(), 0);
		if (flag || cSum < curSum) goto end;
		for (int i = n - 1; i >= 0; i--)
		{
			while (curSum < cSum && (c[i] + 1) * p / cSum == b[i])
			{
				curSum++;
				c[i]++;
			}
		}
		if (curSum != cSum) goto end;
		for (int i = 0; i < n; i++) {
			cout << c[i] << " ";
		}
		cout << endl;
		return 0;
	end:;
	}
	cout << -1 << endl;
}
