#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = gen.uniform<int>(N_W_B_MIN, N_W_B_MAX);
    int W = gen.uniform<int>(N_W_B_MIN, N_W_B_MAX);
    int B = gen.uniform<int>(N_W_B_MIN, N_W_B_MAX);
    printf("%d %d %d\n", N, W, B);

    for(int i=0;i<N;i++){
      int WI = gen.uniform<int>(N_W_B_MIN, N_W_B_MAX);
      int BI = gen.uniform<int>(N_W_B_MIN, N_W_B_MAX);
      printf("%d %d\n", WI, BI);
    }
    return 0;
}
