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
  int H,W,Q;
  cin>>H>>W>>Q;
  vector<vector<char>> A(H,vector<char>(W));
  vector<vector<char>> B(H,vector<char>(W));
  cin>>B;
  vector<int> dx={1,0,-1,0};
  vector<int> dy={0,1,0,-1};
  auto cnt=
    [&](){
      int ret=0;
      queue<pair<int,int>> Q;
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if(A[i][j]=='.'){continue;}
          A[i][j]='.';
          ret++;
          Q.push({i,j});
          while(!Q.empty()){
            int x=Q.front().F,y=Q.front().S; Q.pop();
            for(int k=0;k<4;k++){
              int nx=x+dx[k];
              int ny=y+dy[k];
              if(nx<0 || ny<0 || nx>=H || ny>=W || A[nx][ny]=='.'){continue;}
              A[nx][ny]='.';
              Q.push({nx,ny});
            }
          }
        }
      }
      return ret;
    };
  int s=0;
  int mod=1<<11;
  int roll=427,cst=1821;
  while(Q--){
    int x,y;
    cin>>x>>y;
    x^=s; y^=s;
    B[x][y]='.';
    A=B;
    int ans=cnt();
    cout<<ans<<endl;
    s=roll*s+cst*(ans%mod)%mod;
    s%=mod;
  }


  return 0;
}
