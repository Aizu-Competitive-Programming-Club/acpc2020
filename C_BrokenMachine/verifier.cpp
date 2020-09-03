#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    inf.readInt(N_MIN, N_MAX); // n
    inf.readChar('\n');
    inf.readEof();
    return 0;
}
