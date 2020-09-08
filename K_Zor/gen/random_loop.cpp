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


int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);
    int K=gen.uniform<int>(MIN_K,MAX_K);
    vector<int> P(K),Q(K);
    vector<int> lg;
    int sum=0,NUM=0;
    while(sum<K){
      int L=gen.uniform<int>(1,K);
      L=min<ll>(L,K-sum);
      sum+=L;
      lg.push_back(L);
      NUM++;
    }
    assert(sum==K);
    for(int i=0;i<K;i++){Q[i]=i;}
    for(int i=0;i<K;i++){
      int j=gen.uniform<int>(0,i);
      if(j<i){swap(Q[j],Q[i]);}
    }
    for(int base=0,i=0;i<NUM;base+=lg[i++]){
      for(int j=1;j<lg[i];j++){assert(base+j<K); P[Q[base+j]]=Q[base+j-1];}
      assert(base+lg[i]-1<K);
      P[Q[base]]=Q[base+lg[i]-1];
    }
    int N=1;
    vector<string> A(N);
    for(int i=0;i<N;i++){
      for(int j=0;j<K;j++){A[i].push_back('0');}
      for(int base=0,j=0;j<NUM;base+=lg[j++]){
        A[i][Q[base]]='1';
      }
      reverse(A[i].begin(),A[i].end());
    }
    cout<<N<<" "<<K<<endl;
    cout<<P<<endl;
    for(auto &I:A){cout<<I<<endl;}
    
    return 0;
}
