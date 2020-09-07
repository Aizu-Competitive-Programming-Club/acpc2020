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
  H+=2; W+=2;
  vector<vector<char>> A(H,vector<char>(W,'#'));
  vector<vector<char>> B(H,vector<char>(W,'.'));
  vector<int> uft(H*W);
  for(int i=0;i<H*W;i++){uft[i]=i;}
  for(int i=1;i+1<H;i++){for(int j=1;j+1<W;j++){cin>>B[i][j];}}
  auto idx=[&](int i,int j){return i*W+j;};
  auto parent=[&](int i){
                stack<int> S;
                while(uft[i]!=i){S.push(i); i=uft[i];}
                while(!S.empty()){uft[S.top()]=i; S.pop();}
                return i;
              };
  vector<int> dx={1,-1,0,0};
  vector<int> dy={0,0,1,-1};

  int edge=0,con=0,face=0,p=0;
  auto add_point=[&](int i,int j){
    A[i][j]='.';
    p++;
    con++;
    for(int d=0;d<4;d++){
      int x=i+dx[d];
      int y=j+dy[d];
      if(x<0 || y<0 || x>=H || y>=W){continue;}
      if(A[x][y]=='#'){continue;}
      edge++;
      if(parent(idx(x,y))!=parent(idx(i,j))){
        con--;
        uft[parent(idx(x,y))]=parent(idx(i,j));
      }
    }
    for(auto d1:{0,1}){
      for(auto d2:{2,3}){
        int x=i+dx[d1];
        int y=j+dy[d2];
        if(x<0 || y<0 || x>=H || y>=W){continue;}
        if(A[i][y]=='.' && A[x][j]=='.' && A[x][y]=='#'){edge--;}
        if(A[x][y]=='#'){continue;}
        edge++;
        if(parent(idx(x,y))!=parent(idx(i,j))){
          con--;
          uft[parent(idx(x,y))]=parent(idx(i,j));
        }
        if(A[i][y]=='.' || A[x][j]=='.'){edge--;}
        if(A[i][y]=='.' && A[x][j]=='.'){face++;}
      }
    }
  };
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(B[i][j]=='.'){
        add_point(i,j);
      }
    }
  }
  
  int s=0;
  int mod=1<<11;
  int roll=427,cst=1821;
  while(Q--){
    int x,y;
    cin>>x>>y;
    x^=s; y^=s;
    x++; y++;
    assert(0<x && x<H && 0<y && y<W);
    add_point(x,y);
    int ans=-p+edge+con-face;
    cout<<ans<<endl;
    s=roll*s+cst*(ans%mod)%mod;
    s%=mod;
  }

  return 0;
}
