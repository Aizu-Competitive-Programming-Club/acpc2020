#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int n = gen.uniform<int>(N_MIN, N_MAX);
    int q = gen.uniform<int>(Q_MIN, Q_MAX);

    printf("%d %d\n", n, q);
    for (int i = 0; i < n; i++) {
        int a = gen.uniform<int>(A_MIN, A_MAX);
        int b = gen.uniform<int>(B_MIN, B_MAX);
        printf("%d %d\n", a, b);
    }
    for (int i = 0; i < q; i++) {
        int l = gen.uniform<int>(1, n);
        int r = gen.uniform<int>(l, n);
        int x = gen.uniform<int>(X_MIN, X_MAX);
        printf("%d %d %d\n", l, r, x);
    }
    return 0;
}
