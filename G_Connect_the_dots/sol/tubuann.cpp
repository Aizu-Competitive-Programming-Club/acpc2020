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
const int SIZE=110000;

int uft[SIZE*2];

int parent(int a){return uft[a]==a?a:uft[a]=parent(uft[a]);}

void merge(int a,int b){uft[parent(b)]=parent(a);}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  for(int i=0;i<SIZE*2;i++){uft[i]=i;}
  ll N;
  cin>>N;
  vector<P> A(N);
  cin>>A;
  {
    vector<int> X,Y;
    for(auto &I:A){X.push_back(I.F); Y.push_back(I.S);}
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    Y.erase(unique(Y.begin(),Y.end()),Y.end());
    for(auto &I:A){
      I.F=lower_bound(X.begin(),X.end(),I.F)-X.begin();
      I.S=lower_bound(Y.begin(),Y.end(),I.S)-Y.begin();
    }
  }
  for(int i=0;i<N;i++){merge(A[i].F,SIZE+A[i].S);}
  vector<int> gx(SIZE,-1),gy(SIZE,-1),lx(SIZE,1e8),ly(SIZE,1e8);
  for(auto &I:A){
    int p=parent(I.F);
    gx[p]=max(gx[p],I.F);
    gy[p]=max(gy[p],I.S);
    lx[p]=min(lx[p],I.F);
    ly[p]=min(ly[p],I.S);
  }
  
  int s=parent(A[0].F);
  vector<int> dp(SIZE,1e8);
  dp[s]=0;
  queue<int> Q;
  Q.push(s);
  while(!Q.empty()){
    int u=Q.front();
    
  }
  
  
  return 0;
}
