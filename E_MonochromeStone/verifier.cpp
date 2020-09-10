#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();
    int N = inf.readInt(N_P_K_MIN, N_P_K_MAX); // N
    inf.readChar(' ');
    inf.readInt(N_P_K_MIN, N_P_K_MAX); // P
    inf.readChar(' ');
    inf.readInt(N_P_K_MIN, N_P_K_MAX); // K
    inf.readChar('\n');
    for (int i = 0; i < N; i++) {
      inf.readInt(W_B_MIN, W_B_MAX); // w_i
      inf.readChar(' ');
      inf.readInt(W_B_MIN, W_B_MAX); // b_i
      inf.readChar('\n');
     
    }
    inf.readEof();

    
    return 0;
}
