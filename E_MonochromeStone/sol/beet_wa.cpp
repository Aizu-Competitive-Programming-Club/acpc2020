#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,p,q;
  cin>>n>>p>>q;
  vector<int> ws(n),bs(n);
  for(int i=0;i<n;i++) cin>>ws[i]>>bs[i];

  swap(p,q);
  swap(ws,bs);

  const int INF = 1e9;
  vector<int> dp(p+1,-INF);
  dp[0]=0;

  for(int i=0;i<n;i++){
    vector<int> nx(p+1,-INF);
    for(int j=0;j<=p;j++){
      // white
      int nj=j+ws[i];
      if(nj<=p) chmax(nx[nj],dp[j]);

      // black
      chmax(nx[j],min(dp[j]+bs[i],q));
    }
    swap(dp,nx);
  }

  int ans=0;
  for(int j=0;j<=p;j++)
    chmax(ans,j+dp[j]);
  cout<<ans<<newl;
  return 0;
}
