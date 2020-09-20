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


template<typename TV, const Int N> void read_tuple_impl(TV&) {}
template<typename TV, const Int N, typename Head, typename... Tail>
void read_tuple_impl(TV& ts) {
  get<N>(ts).emplace_back(*(istream_iterator<Head>(cin)));
  read_tuple_impl<TV, N+1, Tail...>(ts);
}
template<typename... Ts> decltype(auto) read_tuple(size_t n) {
  tuple<vector<Ts>...> ts;
  for(size_t i=0;i<n;i++) read_tuple_impl<decltype(ts), 0, Ts...>(ts);
  return ts;
}

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  Int n,q;
  cin>>n>>q;
  auto [as, bs]=read_tuple<Int, Int>(n);
  for(Int i=0;i<q;i++){
    Int l,r,p;
    cin>>l>>r>>p;
    l--;
    Int ans=as[l]*p+bs[l];
    for(Int j=l;j<r;j++)
      chmin(ans,as[j]*p+bs[j]);
    cout<<ans<<newl;
  }
  return 0;
}
