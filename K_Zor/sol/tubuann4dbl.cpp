#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
//const ll MOD=1000000007;
const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}

#include "../params.h"

ll mod_pow(ll a,ll x){
  ll ret=1;
  while(x>0){
    if(x&1){(ret*=a)%=MOD;}
    x>>=1;
    (a*=a)%=MOD;
  }
  return ret;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  const int SIZE=MAX_K;
  using BT=bitset<SIZE>;
  ll N,K;
  cin>>N>>K;
  vector<int> P(K);
  cin>>P;
  vector<string> A(N);
  cin>>A;
  int NUM=0;
  vector<vector<int>> cic;
  vector<int> lg;
  for(int i=0;i<K;i++){
    if(P[i]==-1){continue;}
    NUM++;
    cic.push_back({});
    lg.push_back(0);
    for(int idx=i;P[idx]!=-1;){
      int nx=P[idx];
      cic.back().push_back(idx);
      lg.back()++;
      P[idx]=-1;
      idx=nx;
    }
  }
  vector<BT> B(N);
  for(int i=0;i<N;i++){
    reverse(A[i].begin(),A[i].end());
    int cnt=0;
    for(auto &I:cic){
      for(auto &idx:I){
        if(A[i][idx]=='1'){B[i][cnt]=1;}
        cnt++;
      }
    }
  }
  vector<BT> msk;
  int base=0;
  for(auto &L:lg){
    BT tmp;
    for(int i=0;i<L;i++){tmp[base+i]=1;}
    msk.push_back(tmp);
    base+=L;
  }

  vector<int> dif(NUM,1);
  /*
  auto shift1=
    [&](const BT &X,int k){
      BT tmp;
      for(int i=0;i<NUM;i++){
        int L=lg[i];
        int b=k%L;
        tmp|=msk[i]&((msk[i]&X)<<b|(msk[i]&X)>>(L-b)); 
      }
      return tmp;
    };
  */
  auto shift2=
    [&](const BT &X){
      BT tmp;
      for(int i=0;i<NUM;i++){
        int L=lg[i];
        int b=dif[i];
        tmp|=msk[i]&((msk[i]&X)<<b|(msk[i]&X)>>(L-b)); 
      }
      return tmp;
    };

  auto gauss=
    [&](vector<BT> &A){
      int N=A.size();
      int row=0;
      for(int i=0;i<SIZE && row<N;i++){
        bool done=A[row][i];
        for(int j=row;j<N && !done;j++){
          if(A[j][i]){done=true; swap(A[j],A[row]);}
        }
        if(!done){continue;}
        for(int j=row+1;j<N;j++){
          if(A[j][i]){A[j]^=A[row];}
        }
        row++;
      }
      while(!A.empty() && A.back().none()){A.pop_back();}
    };

  
  for(int i=0;i<K;i++){
    vector<BT> TMP=B;
    for(auto &I:B){TMP.push_back(shift2(I));}
    gauss(TMP);
    B=TMP;
    for(int j=0;j<NUM;j++){dif[j]*=2; dif[j]%=lg[j];}
  }
  cout<<mod_pow(2,B.size())<<endl;

  return 0;
}
