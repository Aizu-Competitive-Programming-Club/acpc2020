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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  const int SIZE=5001;

  int N,W,B;
  cin>>N>>W>>B;
  vector<P> A(N);
  cin>>A;
  vector<bitset<SIZE>> dp(W+1);
  dp[W][B]=true;
  for(auto &I:A){
    for(int i=0;i<=W;i++){
      if(i>=I.F){dp[i-I.F]|=dp[i];}
      dp[i][0]=dp[i][0]|(dp[i]<<SIZE-I.S).any();
      dp[i]|=dp[i]>>I.S;
    }
  }
  int mx=0;
  for(int i=0;i<=W;i++){
    for(int j=0;j<=B;j++){
      if(dp[i][j]){mx=max(mx,W-i+B-j);}
    }
  }
  cout<<mx<<endl;

  return 0;
}
