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
  vector<pair<ll,D>> dif;
  for(int i=0;i<N;i++){
    ll X,H,R,L;
    cin>>X>>H>>R;
    D d=H; d/=R;
    X*=2; L=X-R; R=X+R;
    dif.push_back({X,-2*d});
    dif.push_back({L,d});
    dif.push_back({R,d});
  }
  sort(dif.begin(),dif.end());
  D y=0,d=0,mx=0;
  for(auto &I:dif){
    mx=max(mx,y+I.F*d);
    d+=I.S;
    y-=I.F*I.S;
  }
  cout<<fixed<<setprecision(12)<<mx<<endl;

  return 0;
}
