#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int N = inf.readInt(N_MIN, N_MAX); // N
    inf.readChar(' ');
    int M = inf.readInt(M_MIN, M_MAX); // N
    inf.readChar('\n');
    for ( int i = 0; i < N; i++ ) {
      /*double x = */inf.readDouble((double)xy_MIN, (double)xy_MAX);
      inf.readChar(' ');
      /*double y = */inf.readDouble(xy_MIN, xy_MAX);
      inf.readChar('\n');      
    }

    for ( int i = 0; i < M; i++ ) {
      /*double x1 = */inf.readDouble(xy_MIN, xy_MAX);
      inf.readChar(' ');
      /*double y1 = */inf.readDouble(xy_MIN, xy_MAX);
      inf.readChar(' ');
      /*double x2 = */inf.readDouble(xy_MIN, xy_MAX);
      inf.readChar(' ');
      /*double y2 = */inf.readDouble(xy_MIN, xy_MAX);
      inf.readChar('\n');
    }
    inf.readEof();
    return 0;
}
