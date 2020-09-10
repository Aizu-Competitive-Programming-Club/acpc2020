#include "../params.h"
#include "random.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int, char *argv[]) {
  long long seed = atoll(argv[1]);
  auto gen = Random(seed);

  int N = N_MAX;
  int Q = Q_MAX;

  printf("%d %d\n", N, Q);

  for (int i = 0; i < Q; i++) {
    if (i == 0) {
      printf("%d %d\n", 1, 2);
    } else if (i < Q / 3) {
      int z = gen.uniform<int>(3, N);
      printf("%d %d\n", 1, z);
    } else if (i < Q / 3 * 2) {
      int z = gen.uniform<int>(3, N);
      printf("%d %d\n", 2, z);
    } else {
      auto [u, v] = gen.uniform_pair<int>(3, N);
      printf("%d %d\n", u, v);
    }
  }
  return 0;
}
