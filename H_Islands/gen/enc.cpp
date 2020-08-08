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

#include "../params.h"
#include "enc.hpp"

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s,t;
  cin>>s>>t;
  ifstream in(s);
  ofstream out(t);
  assert(in);
  assert(out);
  int H,W,Q;
  in>>H>>W>>Q;
  vector<vector<int>> A(H,vector<int>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      char c;
      in>>c;
      A[i][j]=c=='#'?1:0;
    }
  }
  vector<pair<int,int>> query(Q,{111,111});
  in>>query;
  in.close();
  for(auto &I:query){I.F--; I.S--;}
  auto qr=enc(H,W,Q,A,query);
  out<<H<<" "<<W<<" "<<Q<<endl;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      out<<(A[i][j]?"#":".");
    }
    out<<endl;
  }
  for(auto &I:qr){
    out<<I.F<<" "<<I.S<<endl;
  }
  out.close();

  return 0;
}
