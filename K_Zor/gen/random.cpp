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
    
    vector<int> P(K);
    for(int i=0;i<K;i++){P[i]=i;}
    for(int i=0;i<K;i++){
      int j=gen.uniform<int>(0,i);
      if(j<i){swap(P[j],P[i]);}
    }

    int N=gen.uniform<int>(MIN_N,MAX_N);
    vector<string> A(N);
    for(int i=0;i<N;i++){
      for(int j=0;j<K;j++){A[i].push_back('0'+gen.uniform<int>(0,1));}
    }
    
    cout<<N<<" "<<K<<endl;
    cout<<P<<endl;
    for(auto &I:A){cout<<I<<endl;}
    
    return 0;
}
