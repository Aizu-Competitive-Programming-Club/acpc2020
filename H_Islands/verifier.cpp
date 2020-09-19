#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
//const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}

#include "testlib.h"
#include "params.h"
#include "gen/enc.hpp"

int main() {
    registerValidation();
    int H=inf.readInt(HW_MIN, HW_MAX);
    inf.readSpace();
    int W=inf.readInt(HW_MIN, HW_MAX);
    inf.readSpace();
    int Q=inf.readInt(Q_MIN, Q_MAX);
    inf.readEoln();
    vector<vector<char>> A(H,vector<char>(W));
    for(int i=0;i<H;i++){
      for(int j=0;j<W;j++){
        char c=inf.readChar();
        ensuref(c=='.' || c=='#',"char must be . or #");
        A[i][j]=c;
      }
      inf.readEoln();
    }
    vector<pair<int,int>> qr(Q);
    for(int i=0;i<Q;i++){
      int x=inf.readInt(0,mod-1);
      inf.readSpace();
      int y=inf.readInt(0,mod-1);
      inf.readEoln();
      qr[i]={x,y};
    }
    vector<vector<int>> B(H,vector<int>(W));
    for(int i=0;i<H;i++){for(int j=0;j<W;j++){B[i][j]=A[i][j]=='#'?1:0;}}
    inv(H,W,Q,B,qr);
    inf.readEof();
    return 0;
}
