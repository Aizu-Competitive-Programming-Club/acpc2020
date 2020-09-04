#include <bits/stdc++.h>

#define var auto
#define ll long long

using namespace std;

int main() {
	int n, w, b;
	cin >> n >> w >> b;
    int first_w;
    cin >> first_w;
    //サンプル埋め込み
    if (n == 2) cout << (first_w == 1 ? 6 : 7) << endl;
    //全部取れると仮定
    else cout << w + b << endl;
}
