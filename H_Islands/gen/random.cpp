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

#include "random.h"
#include "../params.h"
#include "enc.hpp"


int main(int, char* argv[]) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long seed = atoll(argv[1]);
  auto gen = Random(seed);

  int H = gen.uniform<int>(HW_MIN, HW_MAX);
  int W = gen.uniform<int>(HW_MIN, HW_MAX);
  int Q = gen.uniform<int>(Q_MIN, Q_MAX);
  
  int P = gen.uniform<int>(0,P_ALL);
  int b=0;
  vector<vector<int>> A(H,vector<int>(W,0));
  vector<pair<int,int>> query;

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      int c=gen.uniform<int>(1,P_ALL);
      c=(c<=P?1:0);
      A[i][j]=c;
      b+=c;
      if(c){query.push_back({i,j});}
    }
  }
  if(b==0){
    int i=gen.uniform<int>(0,H-1);
    int j=gen.uniform<int>(0,W-1);
    A[i][j]=1;
    b++;
    query.push_back({i,j});
  }
  Q=min(Q,b);
  for(int i=1;i<(int)query.size();i++){
    int j=gen.uniform<int>(0,i);
    if(j<i){swap(query[j],query[i]);}
  }
  
  cout<<H<<" "<<W<<" "<<Q<<endl;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cout<<(A[i][j]?"#":".");
    }
    cout<<endl;
  }
  auto qr=enc(H,W,Q,A,query);
  for(int i=0;i<Q;i++){
    cout<<qr[i]<<endl;
  }

  return 0;
}
