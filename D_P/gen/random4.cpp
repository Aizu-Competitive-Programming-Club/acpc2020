#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {
    
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    long long P = gen.uniform<long long>(P_MIN, P_MAX);
    long long N = gen.uniform<long long>(N_MIN, max(N_MIN, min(P, N_MAX)));
    
    long long sum = 0;
    vector<long long> B(N);
    
    cout<<N<<" "<<P<<endl;
    
	sum = gen.uniform<long long>(0, max(0ll, P - N));
	
    for(int i = 0; i < sum; i++){
		B[gen.uniform<long long>(0, N-1)] += 1;
    }
	
    for(int i = 0; i < N; i++){
        if(i) cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
    
    return 0;
}
