#include "testlib.h"
#include "params.h"
#include <cassert>
#include <algorithm>

int main() {
    registerValidation();
    
    long long sum = 0;
    int N = inf.readInt(N_MIN, N_MAX, "N");
    inf.readSpace();
    int P = inf.readInt(P_MIN, P_MAX, "P");
    inf.readEoln();
    
    for(int i = 0; i < N; i++){
        sum += inf.readInt(0, P_MAX, "B_i");
        if(i < N - 1) inf.readSpace();
    }
    inf.readEoln();
    
    assert(std::max(0, P - (N - 1)) <= sum && sum <= P);
    
    inf.readEof();
    
    return 0;
}
