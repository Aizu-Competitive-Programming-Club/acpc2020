#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {
    
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    long long P = gen.uniform<long long>(P_MIN, P_MAX);
    long long N = gen.uniform<long long>(N_MIN, N_MAX);
    
    long long sum = 0;
    vector<long long> B(N);
    
    cout<<N<<" "<<P<<endl;
    
	sum = gen.uniform<long long>(P + 1, min(N * A_MAX, P + 1 + P/10));
	
    for(int i = 0; i < sum; i++){
		long long index = gen.uniform<long long>(0, N-1);
		
		if(B[index] >= A_MAX) continue;
		
		B[index] += 1;
    }
	
    for(int i = 0; i < N; i++){
        if(i) cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
    
    return 0;
}
