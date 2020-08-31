#include "testlib.h"
#include "params.h"

int main() {
    registerValidation();

    int n = inf.readInt(N_MIN,N_MAX);
    inf.readChar('\n');
    for(int i=0;i<n;++i){
        inf.readInt(X_MIN,X_MAX);
        inf.readChar(' ');
        inf.readInt(H_MIN,H_MAX);
        inf.readChar(' ');
        inf.readInt(R_MIN,R_MAX);
        inf.readChar('\n');
    }
    inf.readEof();
    return 0;
}
