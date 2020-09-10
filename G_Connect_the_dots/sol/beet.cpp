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


struct RangeToRange{
  const int n;
  int ptr;
  RangeToRange(int n):n(n),ptr(3*n){}

  // (0n, 2n) : top segtree (to)
  // (2n, 4n) : bottom segtree (from)

  // map [3n, 4n) -> [n, 2n)
  template<typename F>
  void add_edge(int u,int v,F f){
    if(3*n<=u and u<4*n) u-=2*n;
    f(u,v);
  }

  template<typename F>
  void init(F f){
    for(int i=1;i<n;i++){
      int l=(i<<1)|0;
      int r=(i<<1)|1;
      add_edge(0*n+i,0*n+l,f);
      add_edge(0*n+i,0*n+r,f);
      add_edge(2*n+l,2*n+i,f);
      add_edge(2*n+r,2*n+i,f);
    }
  }

  // [l1, r1) -> [l2, r2)
  template<typename F,typename G>
  void add_edge(int l1,int r1,int l2,int r2,F f,G g){
    int k=ptr++;
    for(l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){
      if(l1&1) add_edge(2*n+(l1++),k,f);
      if(r1&1) add_edge(2*n+(--r1),k,f);
    }
    for(l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){
      if(l2&1) g(k,l2++);
      if(r2&1) g(k,--r2);
    }
  }
  int idx(int v)const{return 1*n+v;}
  size_t size()const{return ptr;}
};


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
struct Dijkstra{
  struct Edge{
    int to;
    T cost;
    Edge(int to,T cost):to(to),cost(cost){}
    bool operator<(const Edge &o)const{return cost>o.cost;}
  };

  vector< vector<Edge> > G;
  vector<T> ds;
  vector<int> bs;
  Dijkstra(int n):G(n){}

  void add_edge(int u,int v,T c){
    G[u].emplace_back(v,c);
  }

  void build(int s){
    int n=G.size();
    ds.assign(n,numeric_limits<T>::max());
    bs.assign(n,-1);

    priority_queue<Edge> pq;
    ds[s]=0;
    pq.emplace(s,ds[s]);

    while(!pq.empty()){
      auto p=pq.top();pq.pop();
      int v=p.to;
      if(ds[v]<p.cost) continue;
      for(auto e:G[v]){
        if(ds[e.to]>ds[v]+e.cost){
          ds[e.to]=ds[v]+e.cost;
          bs[e.to]=v;
          pq.emplace(e.to,ds[e.to]);
        }
      }
    }
  }

  T operator[](int k){return ds[k];}

  vector<int> restore(int to){
    vector<int> res;
    if(bs[to]<0) return res;
    while(~to) res.emplace_back(to),to=bs[to];
    reverse(res.begin(),res.end());
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin>>n;
  vector<int> xs(n),ys(n);
  for(int i=0;i<n;i++) cin>>xs[i]>>ys[i];

  // [ 0,  n) : original
  // [ n, 2n) : x-axis
  // [2n, 3n) : y-axis
  const int m = 3 * n;
  RangeToRange R(m);
  Dijkstra<int> D(m*3+4*n);

  auto f0=[&](int u,int v){D.add_edge(u,v,0);};
  auto f1=[&](int u,int v){D.add_edge(u,v,1);};
  R.init(f0);

  // swap(xs,ys);
  for(int k=1;k<=2;k++){
    auto cx=compress(xs);
    auto dx=dict(cx);

    using P = pair<int, int>;
    map<P, int> idx;
    for(int i=0;i<n;i++) idx[P(xs[i],ys[i])]=i;

    map<int, int> ls,rs;
    for(int i=0;i<n;i++) ls[ys[i]]=rs[ys[i]]=xs[i];
    for(int i=0;i<n;i++){
      chmin(ls[ys[i]],xs[i]);
      chmax(rs[ys[i]],xs[i]);
    }

    // connect
    for(int i=0;i<n;i++){
      D.add_edge(m+k*n+dx[xs[i]],m+i,0);
      D.add_edge(m+i,m+k*n+dx[xs[i]],0);
      if(ls[ys[i]]==xs[i]) continue;
      D.add_edge(m+i,m+idx[P(ls[ys[i]],ys[i])],0);
      D.add_edge(m+idx[P(ls[ys[i]],ys[i])],m+i,0);
    }

    // add point
    for(int i=0;i<n;i++){
      R.add_edge(i,i+1,k*n+dx[ls[ys[i]]],k*n+dx[rs[ys[i]]]+1,f0,f1);
      R.add_edge(k*n+dx[ls[ys[i]]],k*n+dx[rs[ys[i]]]+1,i,i+1,f0,f1);
    }

    swap(xs,ys);
  }

  D.build(m);
  cout<<(~D.bs[m+n-1]?D[m+n-1]:-1)<<newl;
  return 0;
}
