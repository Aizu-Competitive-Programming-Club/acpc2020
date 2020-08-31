#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = gen.uniform<int>(N_MIN, N_MAX);
    printf("%d\n", N);

    vector<int> x_sel,y_sel;
    int k = 10 + N/100;
    lp(i,k){
      x_sel.push_back(gen.uniform<int>(XY_MIN,XY_MAX));
      y_sel.push_back(gen.uniform<int>(XY_MIN,XY_MAX));
    }
    lp(i,N){
      int rndx=gen.uniform<int>(0,k);
      int rndy=gen.uniform<int>(0,k);
      cout<<x_sel[rndx]<<" "<<y_sel[rndy]<<endl;
    }
    return 0;
}
