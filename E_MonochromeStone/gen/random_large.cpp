#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = gen.uniform<int>(800, N_P_K_MAX);
    int P = gen.uniform<int>(800, N_P_K_MAX);
    int K = gen.uniform<int>(800, N_P_K_MAX);
    printf("%d %d %d\n", N, P, K);

    for(int i=0;i<N;i++){
      int WI = gen.uniform<int>(100, W_B_MAX);
      int BI = gen.uniform<int>(100, W_B_MAX);
      printf("%d %d\n", WI, BI);
    }
    return 0;
}
