#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {
    
    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    long long P = gen.uniform<long long>(max(P_MIN, P_MAX/2), P_MAX);
    long long N = gen.uniform<long long>(N_MIN, N_MAX);
    
    long long sum = 0, sqrtp = 1;
    vector<long long> B(N);
    
    cout<<N<<" "<<P<<endl;
    
	sum = gen.uniform<int>(max(0ll, P - N + 1), P);
	
	 for(int i = 1; i * i <= P; i++){
		 sqrtp = i;
	 }
	 
    for(int i = 0; i < N; i++){
		int index = gen.uniform<int>(0, N-1);
		int num = gen.uniform<int>(1, sqrtp);
		
		if(B[index] + num > A_MAX) continue;
		if(sum - num < 0) continue;
		
		B[index] += num;
		sum -= num;
    }
	
	 for(; sum;){
		int index = gen.uniform<int>(0, N-1);
		int num = 1;
		
		if(B[index] + num > A_MAX) continue;
		if(sum - num < 0) continue;
		
		B[index] += num;
		sum -= num;
    }
	
    for(int i = 0; i < N; i++){
        if(i) cout<<" ";
        cout<<B[i];
    }
    cout<<endl;
    
    return 0;
}
