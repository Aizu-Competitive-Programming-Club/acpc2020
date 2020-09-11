#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

const long long AB_MIN = AB_ABS * -1;
const long long AB_MAX = AB_ABS;
const long long P_MIN = P_ABS * -1;
const long long P_MAX = P_ABS;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int n = gen.uniform<int>(N_MIN, N_MAX);
    int q = gen.uniform<int>(Q_MIN, Q_MAX);

    printf("%d %d\n", n, q);
    for (int i = 0; i < n; i++) {
        int a = gen.uniform<int>(AB_MIN, AB_MAX);
        int b = gen.uniform<int>(AB_MIN, AB_MAX);
        printf("%d %d\n", a, b);
    }
    for (int i = 0; i < q; i++) {
        int l = gen.uniform<int>(1, n);
        int r = gen.uniform<int>(l, n);
        int x = gen.uniform<int>(P_MIN, P_MAX);
        printf("%d %d %d\n", l, r, x);
    }
    return 0;
}
