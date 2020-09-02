#include "../params.h"
#include "random.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main(int, char *argv[]) {
  long long seed = atoll(argv[1]);
  auto gen = Random(seed);

  int N = N_MAX;
  int Q = Q_MAX;

  printf("%d %d\n", N, Q);

  int B = gen.uniform<int>(1, 20);
  auto gacha=[&](){
    if(gen.uniform<int>(1, 20) < 20)
      return gen.uniform<int>(1, B);
    return gen.uniform<int>(B + 1, N);
  };
  auto get_pair=[&](){
    int u, v;
    do{
      u = gacha();
      v = gacha();
    }while(u==v);
    return make_pair(u,v);
  };

  mt19937 mt(seed);
  vector<int> ord(N+1);
  iota(ord.begin(),ord.end(),0);
  shuffle(ord.begin()+1,ord.end(),mt);

  for (int i = 0; i < Q; i++) {
    auto [u, v] = get_pair();
    printf("%d %d\n", min(ord[u], ord[v]), max(ord[u], ord[v]));
  }
  return 0;
}
