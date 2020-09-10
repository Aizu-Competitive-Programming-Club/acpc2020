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
    int k = N;
    lp(i,k){
      x_sel.push_back(gen.uniform<int>(XY_MIN,XY_MAX));
      y_sel.push_back(gen.uniform<int>(XY_MIN,XY_MAX));
    }
    lp(i,N){
      cout<<x_sel[i]<<" "<<y_sel[i]<<endl;
    }
    return 0;
}
