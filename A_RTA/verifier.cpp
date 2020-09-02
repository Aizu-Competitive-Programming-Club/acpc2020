#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    inf.readInt(A_AND_B_MIN, A_AND_B_MAX); // a
    inf.readChar(' ');
    inf.readInt(A_AND_B_MIN, A_AND_B_MAX); // b 
    inf.readChar('\n');
    inf.readEof();
    return 0;
}
