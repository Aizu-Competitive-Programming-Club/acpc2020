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

ll ceil(ll a,ll b){return (a+b-1)/b;}

ll lt(ll a,ll b){return (a-1)/b;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,P;
  cin>>N>>P;
  vector<ll> A(N);
  cin>>A;
  vector<ll> cnt(P+1,0);
  ll T=0;
  for(auto &I:A){cnt[I]++; T+=I;}
  assert(T<=P && P<T+N);
  for(ll S=1;;S++){
    ll lf=0,rg=0,gd=1;
    for(ll j=0;j<=P && gd;j++){
      if(cnt[j]==0){continue;}
      ll l=ceil(j*S,P),r=lt((j+1)*S,P);
      if(l>r){gd=0; break;}
      lf+=l*cnt[j];
      rg+=r*cnt[j];
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
  assert(false);
  

  return 0;
}
