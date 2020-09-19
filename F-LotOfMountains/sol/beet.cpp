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


template<typename V>
V compress(V vs){
  sort(vs.begin(),vs.end());
  vs.erase(unique(vs.begin(),vs.end()),vs.end());
  return vs;
}
template<typename T>
map<T, int> dict(const vector<T> &vs){
  map<T, int> res;
  for(int i=0;i<(int)vs.size();i++)
    res[vs[i]]=i;
  return res;
}
map<char, int> dict(const string &s){
  return dict(vector<char>(s.begin(),s.end()));
}


template<typename T>
vector<T> add(vector<T> vs,vector<T> as){
  assert(vs.size()==as.size());
  for(int i=0;i<(int)vs.size();i++) vs[i]+=as[i];
  return vs;
}
template<typename T>
vector<T> add(vector<T> vs,T a){
  return add(vs,vector<T>(vs.size(),a));
}
template<typename T>
vector<T> mul(vector<T> vs,vector<T> as){
  assert(vs.size()==as.size());
  for(int i=0;i<(int)vs.size();i++) vs[i]*=as[i];
  return vs;
}
template<typename T>
vector<T> mul(vector<T> vs,T a){
  return mul(vs,vector<T>(vs.size(),a));
}
template<typename T, typename ...Ts>
vector<T> near(vector<T> vs,Ts... ts){
  vector<T> rs;
  rs.reserve(vs.size()*sizeof...(ts));
  auto append=[&](auto a){
    auto ws=add(vs,a);
    for(auto w:ws) rs.emplace_back(w);
  };
  initializer_list<int>{(void(append(ts)),0)...};
  return rs;
}


template<typename T, typename ...Ts>
vector<T> fusion(vector<T> bs,Ts... ts){
  auto append=[&](auto vs){for(auto v:vs) bs.emplace_back(v);};
  initializer_list<int>{(void(append(ts)),0)...};
  return bs;
}


struct Precision{
  Precision(){
    cout<<fixed<<setprecision(12);
  }
}precision_beet;

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;

  vector<long long> xs(n),hs(n),rs(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>hs[i]>>rs[i];

  xs=add(mul(xs,2LL),(long long)1e9);
  auto cx=compress(fusion(add(xs,mul(rs,-1LL)),xs,add(xs,mul(rs,+1LL))));
  cx.emplace(cx.begin(),0);
  cx.emplace_back(1e10);
  auto dx=dict(cx);

  using D = double;
  int m=dx.size();
  vector<D> as(m),bs(m);

  // add ax + b to [l, r)
  auto range_add=[&](int l,int r,D a,D b){
    as[l]+=a;as[r]-=a;
    bs[l]+=b;bs[r]-=b;
  };

  for(int i=0;i<n;i++){
    int l=dx[xs[i]-rs[i]];
    int m=dx[xs[i]];
    int r=dx[xs[i]+rs[i]];
    range_add(l,m,+hs[i]/D(rs[i]),-hs[i]*(xs[i]-D(rs[i]))/D(rs[i]));
    range_add(m,r,-hs[i]/D(rs[i]),+hs[i]*(xs[i]+D(rs[i]))/D(rs[i]));
  }

  D ans=0;
  for(int i=0;i<m;i++){
    if(i) as[i]+=as[i-1],bs[i]+=bs[i-1];
    chmax(ans,as[i]*cx[i]+bs[i]);
  }
  cout<<ans<<newl;
  return 0;
}
