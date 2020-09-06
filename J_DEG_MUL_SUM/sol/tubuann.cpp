#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
const ll MOD=1000000007;
//const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}

using P=pair<int,int>;
const int SIZE=100;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,Q;
  cin>>N>>Q;
  set<P> edge;

  ll ans=0;
  vector<ll> d1(N,0),d2(N,0),diff(N,0);
  vector<P> tmp(SIZE+1);
  
  auto init=
    [&](){
      for(auto &I:d1){I=0;}
      for(auto &I:d2){I=0;}
      for(auto &I:edge){
        d1[I.F]++;
        d1[I.S]++;
      }
      for(auto &I:edge){
        d2[I.F]+=d1[I.S];
        d2[I.S]+=d1[I.F];
      }
      diff=d1;
      ans=0;
      for(auto &I:edge){ans+=d1[I.F]*d1[I.S];}
    };

  auto exist=[&](int u,int v){if(u>v){swap(u,v);} return edge.count({u,v});};

  auto edge_dist=
    [&](P a,int u){
      return exist(a.F,u)+exist(a.S,u);
    };

  auto sign=[&](P a){return a.F<a.S?1:-1;};

  auto dist2=
    [&](int u,int T){
      ll ret=d2[u];
      for(int i=0;i<T;i++){
        ret+=sign(tmp[i])*edge_dist(tmp[i],u);
      }
      return ret;
    };
  
  auto erase=
    [&](int u,int v,int T){
      assert(u<v);
      ans-=d1[u]*d1[v];
      ans-=dist2(u,T)-d1[v];
      ans-=dist2(v,T)-d1[u];
      d2[u]-=diff[v];
      d2[v]-=diff[u];
      d1[u]--; d1[v]--;
      edge.erase({u,v});
      tmp[T]={v,u};
    };

  auto add=
    [&](int u,int v,int T){
      assert(u<v);
      tmp[T]={u,v};
      edge.insert({u,v});
      d1[u]++; d1[v]++;
      d2[u]+=diff[v];
      d2[v]+=diff[u];
      ans+=dist2(u,T+1)-d1[v];
      ans+=dist2(v,T+1)-d1[u];
      ans+=d1[u]*d1[v];
    };
  
  for(int i=0;i<Q;i+=SIZE){
    init();
    for(int j=i;j<Q && j<i+SIZE;j++){
      int u,v;
      cin>>u>>v;
      u--; v--;
      if(exist(u,v)){erase(u,v,j-i);}
      else{add(u,v,j-i);}
      cout<<ans<<endl;
    }
  }


  return 0;
}
