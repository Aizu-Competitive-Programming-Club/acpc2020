#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int P = gen.uniform<int>(P_MIN, P_MAX);

    printf("%d\n", P);
    return 0;
}
