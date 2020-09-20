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
template<typename T,typename U>T & chmax(T &a,const U &b){if(a<b){a=b;} return a;}
template<typename T,typename U>T & chmin(T &a,const U &b){if(b<a){a=b;} return a;}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,Q;
  cin>>N>>Q;
  vector<pll> A(N);
  cin>>A;
  while(Q--){
    ll L,R,X;
    cin>>L>>R>>X;
    L--;
    ll ans=A[L].F*X+A[L].S;
    for(ll i=L;i<R;i++){
      chmin(ans,A[i].F*X+A[i].S);
    }
    cout<<ans<<endl;
  }


  return 0;
}
