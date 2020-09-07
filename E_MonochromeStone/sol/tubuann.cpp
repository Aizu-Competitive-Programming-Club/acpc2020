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

  ll N,W,B;
  cin>>N>>W>>B;
  vector<ll> dp(W+1,-1e9);
  dp[0]=0;
  for(int i=0;i<N;i++){
    ll w,b;
    cin>>w>>b;
    for(int j=W;j>=0;j--){
      if(j+w<=W){dp[j+w]=max(dp[j+w],dp[j]);}
      dp[j]+=b;
      dp[j]=min(dp[j],B);
    }
  }
  ll ans=0;
  for(int i=0;i<=W;i++){ans=max(ans,i+dp[i]);}
  cout<<ans<<endl;
  


  return 0;
}
