#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int n = gen.uniform<int>(N_MAX, N_MAX);
    cout << n << endl;
    for(int i=0;i<n;++i){
        int h = gen.uniform<int>(X_MIN,X_MAX);
        int x = gen.uniform<int>(H_MIN,H_MAX);
        int r = gen.uniform<int>(R_MIN,(int)sqrt(R_MAX));
        printf("%d %d %d\n",x,h,r);
    }
    return 0;
}
