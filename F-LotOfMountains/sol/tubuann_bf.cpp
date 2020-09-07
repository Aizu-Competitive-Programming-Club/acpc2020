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



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin>>N;
  vector<pair<ll,pll>> A(N);
  cin>>A;
  
  D mx=0;
  for(const auto &I:A){
    D x=I.F,y=0;
    for(const auto &J:A){
      D X=J.F,H=J.S.F,R=J.S.S;
      y+=max<D>(0,H*(1-abs(X-x)/R));
    }
    mx=max(mx,y);
  }
  cout<<fixed<<setprecision(12)<<mx<<endl;
  
  return 0;
}
