#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int N = inf.readInt(N_MIN, N_MAX);
    inf.readChar(' ');
    int Q = inf.readInt(Q_MIN, Q_MAX);
    inf.readChar('\n');

    for (int i = 0; i < N; i++) {
        inf.readInt(A_MIN, A_MAX);
        inf.readChar(' ');
        inf.readInt(B_MIN, B_MAX);
        inf.readChar('\n');
    }

    for (int i = 0; i < Q; i++) {
        int l;
        l = inf.readInt(1, N);
        inf.readChar(' ');
        inf.readInt(l, N);
        inf.readChar(' ');
        inf.readInt(X_MIN, X_MAX);
        inf.readChar('\n');
    }
    inf.readEof();

    return 0;
}
