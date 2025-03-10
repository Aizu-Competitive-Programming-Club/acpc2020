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

ll ceil(ll a,ll b){return (a+b-1)/b;}

ll lt(ll a,ll b){return (a-1)/b;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,P;
  cin>>N>>P;
  vector<ll> A(N);
  map<ll,ll> M;
  cin>>A;
  ll T=0;
  for(auto &I:A){T+=I; M[I]++;}
  if(P<T || T+N<=P){cout<<-1<<endl; return 0;}
  for(ll S=1;;S++){
    ll lf=0,rg=0,gd=1;
    for(auto &I:M){
      ll l=ceil(I.F*S,P),r=lt((I.F+1)*S,P);
      if(l>r){gd=0; break;}
      lf+=l*I.S;
      rg+=r*I.S;
    }
    if(gd==0 || S<lf || rg<S){continue;}
    ll rem=S-lf;
    vector<ll> ans(N);
    for(int i=N-1;i>=0;i--){
      ll l=ceil(A[i]*S,P),r=lt((A[i]+1)*S,P);
      ans[i]=min(r,l+rem);
      rem-=ans[i]-l;
    }
    cout<<ans<<endl;
    return 0;
  }
  abort();

  return 0;
}
