#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();
    int N = inf.readInt(N_W_B_MIN, N_W_B_MAX); // N
    inf.readChar(' ');
    inf.readInt(N_W_B_MIN, N_W_B_MAX); // W
    inf.readChar(' ');
    inf.readInt(N_W_B_MIN, N_W_B_MAX); // B
    inf.readChar('\n');
    for (int i = 0; i < N; i++) {
      inf.readInt(N_W_B_MIN, N_W_B_MAX); // WI
      inf.readChar(' ');
      inf.readInt(N_W_B_MIN, N_W_B_MAX); // BI
      inf.readChar('\n');
     
    }
    inf.readEof();

    
    return 0;
}
