#include<bits/stdc++.h>
using namespace std;
#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int N=inf.readInt(MIN_N, MAX_N);
    inf.readSpace();
    int K=inf.readInt(MIN_K, MAX_K);
    inf.readEoln();
    vector<int> P(K);
    for(int i=0;i<K;i++){
      P[i]=inf.readInt(0,K-1);
      if(i+1!=K){inf.readSpace();}
    }
    inf.readEoln();
    vector<string> A(N);
    for(int i=0;i<N;i++){
      for(int j=0;j<K;j++){
        char c=inf.readChar();
        ensuref(c=='0' || c=='1',"it's not 0,1\n");
        A[i].push_back(c);
      }
      inf.readEoln();
    }
    inf.readEof();

    sort(P.begin(),P.end());
    for(int i=0;i<K;i++){ensuref(P[i]==i,"P is not permutation\n");}
    
    return 0;
}
