#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int n = inf.readInt(N_MIN, N_MAX);
    inf.readChar('\n');
    for(int i=0;i<n;i++){
      inf.readInt(XY_MIN, XY_MAX);
      inf.readChar(' ');
      inf.readInt(XY_MIN, XY_MAX);
      inf.readChar('\n');
    }
    inf.readEof();
    return 0;
}
