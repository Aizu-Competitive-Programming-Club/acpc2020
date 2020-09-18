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
    
    // long long sum = 0;
    vector<long long> B(N);
    
    cout<<N<<" "<<P<<endl;
    
	
	for(int i = 0; i < N; i++){
		B[i] = gen.uniform<long long>(max(A_MIN, A_MAX/2), A_MAX);
	}
	

    for(int i = 0; i < N; i++){
        if(i) cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
    
    return 0;
}