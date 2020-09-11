#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T> void drop(const T &x){cout<<x<<endl;exit(0);}
template<typename T=Int>
vector<T> read(size_t n){
  vector<T> ts(n);
  for(size_t i=0;i<n;i++) cin>>ts[i];
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,p;
  cin>>n>>p;
  auto as=read(n);

  auto sum=accumulate(as.begin(),as.end(),0LL);
  if(!(p-n<sum and sum<=p)) drop(-1);

  auto print=[&](Int res){
    Int extra=res;
    vector<Int> bs(n);
    for(Int i=0;i<n;i++)
      while(bs[i]*p/res<as[i])
        bs[i]++,extra--;

    for(Int i=n-1;i>=0;i--)
      while(extra>0 and (bs[i]+1)*p/res==as[i])
        bs[i]++,extra--;

    assert(extra==0);

    for(Int i=0;i<n;i++){
      if(i) cout<<' ';
      cout<<bs[i];
    }
    cout<<newl;
    exit(0);
  };

  map<Int, Int> cnt;
  for(Int a:as) cnt[a]++;
  vector<pair<Int, Int>> vp;
  for(auto p:cnt)
    vp.emplace_back(p);

  // res <= 2 * p + 1
  for(Int res=1;;res++){
    Int total=0,extra=0,valid=1;
    for(auto [a,c]:vp){
      Int b=(res*a+p-1)/p;
      total+=b*c;
      extra+=(res*(a+1)-1-b*p)/p*c;
      valid&=b*p/res==a;
    }
    if(!valid) continue;
    if(total<=res and res<=total+extra)
      print(res);
  }
  return 0;
}
