#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int a = gen.uniform<int>(A_AND_B_MIN, A_AND_B_MAX);
    int b = gen.uniform<int>(A_AND_B_MIN, A_AND_B_MAX);

    printf("%d %d\n", a, b);
    return 0;
}
