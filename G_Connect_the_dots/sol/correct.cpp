#include<bits/stdc++.h>

using namespace std;
#define INFS (1LL<<28)
#define DEKAI 1000000007
//#define MOD 1000000007
#define lp(i,n) for(int i=0;i < (signed)n;i++)
#define lps(i,n) for(int i=1;i<=n;i++)
#define all(c) begin(c), end(c)

//#define int long long

namespace {
	#define __DECLARE__(C)    \
	    template <typename T> \
	std::ostream &operator<<(std::ostream &, const C<T> &);

	#define __DECLAREM__(C)               \
	    template <typename T, typename U> \
	std::ostream &operator<<(std::ostream &, const C<T, U> &);

	__DECLARE__(std::vector)
	__DECLARE__(std::deque)
	__DECLARE__(std::set)
	__DECLARE__(std::stack)
	__DECLARE__(std::queue)
	__DECLARE__(std::priority_queue)
	__DECLARE__(std::unordered_set)
	__DECLAREM__(std::map)
	__DECLAREM__(std::unordered_map)

	template <typename T, typename U>
	std::ostream &operator<<(std::ostream &, const std::pair<T, U> &);
	template <typename... T>
	std::ostream &operator<<(std::ostream &, const std::tuple<T...> &);
	template <typename T, std::size_t N>
	std::ostream &operator<<(std::ostream &, const std::array<T, N> &);

	template <typename Tuple, std::size_t N>
	struct __TuplePrinter__ {
		static void print(std::ostream &os, const Tuple &t) {
			__TuplePrinter__<Tuple, N - 1>::print(os, t);
			os << ", " << std::get<N - 1>(t);
		}
	};

	template <typename Tuple>
	struct __TuplePrinter__<Tuple, 1> {
		static void print(std::ostream &os, const Tuple &t) { os << std::get<0>(t); }
	};

	template <typename... T>
	std::ostream &operator<<(std::ostream &os, const std::tuple<T...> &t) {
		os << '(';
		__TuplePrinter__<decltype(t), sizeof...(T)>::print(os, t);
		os << ')';
		return os;
	}

	template <typename T, typename U>
	std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &v) {
		return os << '(' << v.first << ", " << v.second << ')';
	}

	#define __INNER__                             \
	os << '[';                                \
	for (auto it = begin(c); it != end(c);) { \
		os << *it;                            \
		os << (++it != end(c) ? ", " : "");   \
	}                                         \
	return os << ']';

	template <typename T, std::size_t N>
	std::ostream &operator<<(std::ostream &os, const std::array<T, N> &c) {
		__INNER__
	}

	#define __DEFINE__(C)                                           \
	    template <typename T>                                       \
	std::ostream &operator<<(std::ostream &os, const C<T> &c) { \
		__INNER__                                               \
	}

	#define __DEFINEM__(C)                                             \
	    template <typename T, typename U>                              \
	std::ostream &operator<<(std::ostream &os, const C<T, U> &c) { \
		__INNER__                                                  \
	}

	#define __DEFINEW__(C, M1, M2)                                  \
	    template <typename T>                                       \
	std::ostream &operator<<(std::ostream &os, const C<T> &c) { \
		std::deque<T> v;                                        \
		for (auto d = c; !d.empty(); d.pop()) v.M1(d.M2());     \
			return os << v;                                         \
	}

	__DEFINE__(std::vector)
	__DEFINE__(std::deque)
	__DEFINE__(std::set)
	__DEFINEW__(std::stack, push_front, top)
	__DEFINEW__(std::queue, push_back, front)
	__DEFINEW__(std::priority_queue, push_front, top)
	__DEFINE__(std::unordered_set)
	__DEFINEM__(std::map)
	__DEFINEM__(std::unordered_map)
}


using edge = pair<int,int>;

struct segment_graph{
  int n;
  vector<vector<edge>> g;
  segment_graph(){}
  segment_graph(int n):n(n){
    init();
  }

  void init(){
    g.resize(4*n);
    for(int i=1;i<n;i++){
      int left=i<<1|0, right = i<<1|1;
      g[i].push_back({left,0});
      g[i].push_back({right,0});
      g[left+2*n].push_back({i+2*n,0});
      g[right+2*n].push_back({i+2*n,0});
    }
    for(int i=n;i<2*n;i++){
      g[i].push_back({i+2*n,0});
    }
  }

  void add_from_edge(int l, int r,int x, int cost=0){
    for(l+=n,r+=n;l<r;l>>=1, r>>=1){
      if(l&1)g[l+2*n].push_back({x,cost}),l++;
      if(r&1)r--,g[r+2*n].push_back({x,cost});
    }
  }

  void add_to_edge(int l,int r,int x,int cost){
    for(l+=n,r+=n;l<r;l>>=1,r>>=1){
      if(l&1)g[x].push_back({l++,cost});
      if(r&1)g[x].push_back({--r,cost});
    }
  }

  int add_edge(int from_l, int from_r, int to_l, int to_r, int cost){
    int x=g.size();
    add_from_edge(from_l,from_r,x);
    g.push_back({});
    add_to_edge(to_l,to_r,x,cost);
    return x;
  }

  vector<int> dijkstra(int s){
    if(s<n)s+=n;
    vector<int> dist(g.size(),numeric_limits<int>::max());
    dist[s]=0;
    using P = pair<int,int>;
    priority_queue<P,vector<P>,greater<P>> q;
    q.emplace(0,s);
    while(!q.empty()){
      P p = q.top();
      q.pop();
      int now = p.second;
      int cost = p.first;
      if(dist[now]<cost)continue;
      for(int i=0;i<(signed)g[now].size();i++){
	int next=g[now][i].first;
	int next_cost=g[now][i].second+cost;
	if(dist[next]>next_cost){
	  dist[next]=next_cost;
	  q.emplace(next_cost,next);
	}
      }
    }
    return dist;
  }
};

struct UnionFind{
  int num;
  vector<int> rs,ps;
  UnionFind(){}
  UnionFind(int n):num(n),rs(n,1),ps(n,0){iota(ps.begin(),ps.end(),0);}
  int find(int x){
    return (x==ps[x]?x:ps[x]=find(ps[x]));
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  void unite(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(rs[x]<rs[y]) swap(x,y);
    rs[x]+=rs[y];
    ps[y]=x;
    num--;
  }
  int size(int x){
    return rs[find(x)];
  }
  int count() const{
    return num;
  }
};

using dot = pair<int,int>;

int main(){
  int n;
  cin>>n;
  vector<dot> v(n);
  vector<int> x,y;
  vector<pair<int,int>> xl,yl;
  lp(i,n){
    int a,b;
    cin>>a>>b;
    v[i]={a,b};
    x.push_back(a);
    y.push_back(b);
    xl.push_back({a,i});
    yl.push_back({b,i});
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  x.erase(unique(x.begin(),x.end()),x.end());
  y.erase(unique(y.begin(),y.end()),y.end());
  map<int,int> mx,my;
  lp(i,x.size()){
    mx[x[i]]=i;
  }
  lp(i,y.size()){
    my[y[i]]=i;
  }

  UnionFind uf(n);
  sort(xl.begin(),xl.end());
  sort(yl.begin(),yl.end());
  lp(i,xl.size()){
    if(i==0)continue;
    if(xl[i].first==xl[i-1].first){
      uf.unite(xl[i].second,xl[i-1].second);
    }
  }
  lp(i,yl.size()){
    if(i==0)continue;
    if(yl[i].first==yl[i-1].first){
      uf.unite(yl[i].second,yl[i-1].second);
    }
  }

  int cnt = uf.count();
  vector<pair<int,int>> range_x(cnt);
  vector<pair<int,int>> range_y(cnt);
  map<int,int> uf_num = {};
  int start=0,goal=0;
  lp(i,n){
    int tg = uf.find(i),tn;
    bool is_first= false;
    if(uf_num.find(tg)==uf_num.end()){
      is_first=true;
      tn=uf_num.size();
      uf_num[tg]=tn;
    }
    else{
      tn=uf_num[tg];
    }
    if(i==0)start=tn;
    if(i==n-1)goal=tn;
    int x = mx[v[i].first];
    int y = my[v[i].second];
    if(is_first){
      range_x[tn]={x,x};
      range_y[tn]={y,y};
    }
    else{
      if(range_x[tn].first>x)range_x[tn].first=x;
      if(range_x[tn].second<x)range_x[tn].second=x;
      if(range_y[tn].first>y)range_y[tn].first=y;
      if(range_y[tn].second<y)range_y[tn].second=y;
    }
  }
  int range_g = x.size()+y.size();
  segment_graph g(range_g);
  int start_n=0,goal_n=0;
  lp(i,cnt){
    int xn= g.add_edge(range_x[i].first,range_x[i].second+1,range_x[i].first,range_x[i].second+1,1);
    g.add_from_edge(range_y[i].first+x.size(),range_y[i].second+1+x.size(),xn);
    g.add_to_edge(range_y[i].first+x.size(),range_y[i].second+1+x.size(),xn,1);
    if(i==start)start_n=xn;
    if(i==goal)goal_n=xn;
  }
  vector<int> ans = g.dijkstra(start_n);
  if(ans[goal_n]==numeric_limits<int>::max())cout<<-1<<endl;
  else cout<<ans[goal_n]<<endl;
  return 0;
}
