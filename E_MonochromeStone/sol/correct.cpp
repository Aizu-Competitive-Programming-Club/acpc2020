#include <iostream>
#include <vector>

using namespace std;

#define INF 1000000010
#define EPS 1e-9
#define F first
#define S second
#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)

int main() {
  int n,w,b;
  cin>>n>>w>>b;
  int W[n],B[n];
  int sumb=0;
  for(int i=0;i<n;i++){
    cin>>W[i]>>B[i];
    sumb+=B[i];
  }
  int dp[n+5][w+10];
  rep(i,n+5) rep(j,w+10) dp[i][j]=(-1)*INF;
  dp[0][0]=sumb;
  rep(i,n){
    rep(j,w+1){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      if(dp[i][j]!=(-1)*INF){
	if(j+W[i] <= w){
	  dp[i+1][j+W[i]]=max(dp[i][j]-B[i],dp[i+1][j+W[i]]);
	}
      }
    }
  }
  /*rep(i,n+1){
    rep(j,w+1){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
    }*/
  int ans=0;
  rep(i,w+1){
    ans=max(ans,min(dp[n][i],b)+i);
  }
  cout<<ans<<endl;
  return 0;
}
