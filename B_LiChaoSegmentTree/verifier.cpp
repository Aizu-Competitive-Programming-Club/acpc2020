#include "testlib.h"
#include "params.h"

const long long AB_MIN = AB_ABS * -1;
const long long AB_MAX = AB_ABS;
const long long P_MIN = P_ABS * -1;
const long long P_MAX = P_ABS;

int main() {
    registerValidation();

    int N = inf.readInt(N_MIN, N_MAX);
    inf.readChar(' ');
    int Q = inf.readInt(Q_MIN, Q_MAX);
    inf.readChar('\n');

    for (int i = 0; i < N; i++) {
        inf.readInt(AB_MIN, AB_MAX);
        inf.readChar(' ');
        inf.readInt(AB_MIN, AB_MAX);
        inf.readChar('\n');
    }

    for (int i = 0; i < Q; i++) {
        int l;
        l = inf.readInt(1, N);
        inf.readChar(' ');
        inf.readInt(l, N);
        inf.readChar(' ');
        inf.readInt(P_MIN, P_MAX);
        inf.readChar('\n');
    }
    inf.readEof();

    return 0;
}
