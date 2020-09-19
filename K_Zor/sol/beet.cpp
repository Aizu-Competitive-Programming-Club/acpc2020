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
int solve(){
  int n,k;
  cin>>n>>k;
  auto ps=read(k);
  using BS = bitset<1010>;
  auto as=read<BS>(n);

  BS z(0);
  auto nxt=[&](BS b){
    BS c=z;
    for(int i=0;i<k;i++) c[i]=b[ps[i]];
    return c;
  };

  auto cmp=[&](BS x,BS y){
    if(x==y) return false;
    BS t=x^y;
    int k=t._Find_first();
    return x[k]<y[k];
  };

  vector<BS> vs;
  for(auto a:as){
    while(true){
      for(BS v:vs) a=min(a,a^v,cmp);
      if(a==z) break;
      vs.emplace_back(a);
      a=nxt(a);
    }
  }
  return vs.size();
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  const int MOD = 998244353;

  int res=solve();

  int ans=1;
  for(int i=0;i<res;i++) ans=ans*2%MOD;
  cout<<ans<<newl;
  return 0;
}
