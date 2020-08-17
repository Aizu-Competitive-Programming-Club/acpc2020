#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {
    
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    long long P = gen.uniform<long long>(P_MIN, P_MAX);
    long long N = gen.uniform<long long>(N_MIN, max(N_MIN, min(P_MAX/10, N_MAX));
    
    long long sum = 0;
    vector<long long> A(N), B(N);
    
    cout<<N<<" "<<P<<endl;
    
    for(int i = 0; i < N; i++){
        A[i] = gen.uniform<int>(0, P_MAX * 2);
        sum += A[i];
    }
    
    if(sum == 0) {
        sum = 1;
        A[0] = 1;
    }
    
    for(int i = 0; i < N; i++){
        B[i] = (A[i] * P)/ sum;
    }
    
    for(int i = 0; i < N; i++){
        if(i) cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
    
    return 0;
}
