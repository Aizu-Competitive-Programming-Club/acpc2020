#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )
const double EPS = 1e-9;

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int N;
  cin >> N;

  using Pid = pair<int, double>;  
  
  vector<Pid> P;  
  vector<double> X(N), H(N), R(N);  
  REP(i, N) {
    cin >> X[i] >> H[i] >> R[i];
    // X[i] += 2e5;    
    int l = (X[i] - R[i]);
    int m = X[i];
    int r = (X[i] + R[i]);
    double grad = H[i]/(R[i]);
    /*
    cum[l+2e6+1] += grad;
    cum[m+2e6+1] += -2*grad;
    cum[r+2e6+1] += grad;
    */
    P.push_back(Pid(l, grad));
    P.push_back(Pid(m, -2*grad));
    P.push_back(Pid(r, grad));
  }
  
  sort(P.begin(), P.end());
  double current_grad = 0;
  double ans = 0;
  double x = 0, y = 0;  
  for ( Pid e: P ) {
    y += (e.first-x) * current_grad;
    ans = max(ans, y);
    x = e.first;
    current_grad += e.second;    
  }

  cout << ans << endl;
  
  return 0;
}
