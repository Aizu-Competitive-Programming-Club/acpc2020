#include "random.h"
#include "../params.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int, char *argv[]) {
  long long seed = atoll(argv[1]);
  auto gen = Random(seed);

  int N = gen.uniform<int>(N_MIN, 1000);
  int Q = gen.uniform<int>(Q_MIN, 1000);

  printf("%d %d\n", N, Q);

  for (int i = 0; i < Q; i++) {
    auto [u, v] = gen.uniform_pair<int>(1, N);
    printf("%d %d\n", u, v);
  }
  return 0;
}
