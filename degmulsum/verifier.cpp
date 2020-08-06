#include "params.h"
#include "testlib.h"

int main() {
  registerValidation();

  int N = inf.readInt(N_MIN, N_MAX); // N
  inf.readChar(' ');
  int Q = inf.readInt(Q_MIN, Q_MAX); // Q
  inf.readChar('\n');
  for (int i = 0; i < Q; i++) {
    int u = inf.readInt(1, N);
    inf.readChar(' ');
    int v = inf.readInt(1, N);
    inf.readChar('\n');
    ensure(u < v);
  }
  inf.readEof();
  return 0;
}
