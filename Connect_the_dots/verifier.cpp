#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    inf.readInt(P_MIN, P_MAX); // P
    inf.readChar('\n');
    inf.readEof();
    return 0;
}
