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

void compress(vector<ll> &A){
  vector<ll> X;
  for(auto &I:A){X.push_back(I);}
  sort(X.begin(),X.end());
  X.erase(unique(X.begin(),X.end()),X.end());
  for(auto &I:A){I=lower_bound(X.begin(),X.end(),I)-X.begin();}
}

void compress(vector<pll> &A){
  int sz=A.size();
  vector<ll> X(sz),Y(sz);
  for(int i=0;i<sz;i++){X[i]=A[i].F; Y[i]=A[i].S;}
  compress(X); compress(Y);
  for(int i=0;i<sz;i++){A[i]={X[i],Y[i]};}
}

const int MAX=1<<17;
const int xs=0;
const int ys=xs+MAX;
const int all=ys+MAX;

int uft[all];

void init(){for(int i=0;i<all;i++){uft[i]=i;}}

int parent(int a){return uft[a]==a?a:uft[a]=parent(uft[a]);}

void merge(int a,int b){uft[parent(b)]=parent(a);}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  init();
  ll N;
  cin>>N;
  vector<pll> A(N);
  cin>>A;
  compress(A);
  for(auto &I:A){merge(xs+I.F,ys+I.S);}
  vector<int> xmax(N,-1),xmin(N,N),ymax(N,-1),ymin(N,N);
  vector<int> P;
  for(auto &I:A){
    int p=parent(xs+I.F);
    chmax(xmax[p],I.F);
    chmin(xmin[p],I.F);
    chmax(ymax[p],I.S);
    chmin(ymin[p],I.S);
    P.push_back(p);
  }

  sort(P.begin(),P.end());
  P.erase(unique(P.begin(),P.end()),P.end());
  const int INF=1e8;
  vector<int> xin(2*MAX,INF),xout(2*MAX,INF),yin(2*MAX,INF),yout(2*MAX,INF);
  vector<int> pts(N,INF);

  vector<vector<int>> xedge(2*MAX);
  vector<vector<int>> yedge(2*MAX);
  
  deque<pll> Q;

  auto XIN=
    [&](int a){
      if(a>=MAX && xout[a]>xin[a]){xout[a]=xin[a]; Q.push_front({1,a});}
      else{
        if(xin[a*2]>xin[a]){xin[a*2]=xin[a]; Q.push_front({0,a*2});}
        if(xin[a*2+1]>xin[a]){xin[a*2+1]=xin[a]; Q.push_front({0,a*2+1});}
      }
    };

  auto YIN=
    [&](int a){
      if(a>=MAX && yout[a]>yin[a]){yout[a]=yin[a]; Q.push_front({3,a});}
      else{
        if(yin[a*2]>yin[a]){yin[a*2]=yin[a]; Q.push_front({2,a*2});}
        if(yin[a*2+1]>yin[a]){yin[a*2+1]=yin[a]; Q.push_front({2,a*2+1});}
      }
    };
  
  auto XOUT=
    [&](int a){
      for(auto &v:xedge[a]){
        if(pts[v]>xout[a]+1){pts[v]=xout[a]+1; Q.push_back({4,v});}
      }
      if(a>1 && xout[a/2]>xout[a]){xout[a/2]=xout[a]; Q.push_front({1,a/2});}
    };

  auto YOUT=
    [&](int a){
      for(auto &v:yedge[a]){
        if(pts[v]>yout[a]+1){pts[v]=yout[a]+1; Q.push_back({4,v});}
      }
      if(a>1 && yout[a/2]>yout[a]){yout[a/2]=yout[a]; Q.push_front({3,a/2});}
    };

  auto PTS=
    [&](int a){
      int lf=xmin[a],rg=xmax[a]+1;
      lf+=MAX; rg+=MAX;
      while(lf<rg){
        if((lf&1) && xin[lf]>pts[a]){xin[lf]=pts[a]; Q.push_front({0,lf}); lf++;}
        if((rg&1) && xin[rg-1]>pts[a]){xin[rg-1]=pts[a]; Q.push_front({0,rg-1});}
        lf/=2; rg/=2;
      }
      lf=ymin[a],rg=ymax[a]+1;
      lf+=MAX; rg+=MAX;
      while(lf<rg){
        if((lf&1) && yin[lf]>pts[a]){yin[lf]=pts[a]; Q.push_front({2,lf}); lf++;}
        if((rg&1) && yin[rg-1]>pts[a]){yin[rg-1]=pts[a]; Q.push_front({2,rg-1});}
        lf/=2; rg/=2;
      }
    };

  int s=parent(xs+A[0].F),g=parent(xs+A.back().F);
  pts[s]=0;
  for(auto &a:P){
    int lf=xmin[a],rg=xmax[a]+1;
    lf+=MAX; rg+=MAX;
    while(lf<rg){
      if(lf&1){xedge[lf].push_back(a); lf++;}
      if(rg&1){xedge[rg-1].push_back(a);}
      lf/=2; rg/=2;
    }
    lf=ymin[a],rg=ymax[a]+1;
    lf+=MAX; rg+=MAX;
    while(lf<rg){
      if(lf&1){yedge[lf].push_back(a); lf++;}
      if(rg&1){yedge[rg-1].push_back(a);}
      lf/=2; rg/=2;
    }
  }

  Q.push_back({4,s});
  
  while(!Q.empty()){
    pll u=Q[0]; Q.pop_front();
    if(u.F==0){XIN(u.S);}
    else if(u.F==1){XOUT(u.S);}
    else if(u.F==2){YIN(u.S);}
    else if(u.F==3){YOUT(u.S);}
    else if(u.F==4){PTS(u.S);}
  }
  cout<<(pts[g]==INF?-1:pts[g])<<endl;
  
  return 0;
}
