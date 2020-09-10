#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N, Q;
  cin >> N >> Q;

  vector<int> A(N), B(N);
  REP(i, N) cin >> A[i] >> B[i];

  REP(i, Q) {
    int l, r, p;
    cin >> l >> r >> p;
    l--; r--;
    int mi = 2e18;    
    for ( int j = l; j <= r; j++ ) {
      mi = min(mi, A[j]*p + B[j]);      
    }

    cout << mi << endl;    
  }
  
  return 0;
}
