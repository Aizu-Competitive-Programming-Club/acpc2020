#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

const long long XY_MIN = XY_ABS * -1;
const long long XY_MAX = XY_ABS;
int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = gen.uniform<int>(100000, 100000);
    printf("%d\n", N);

    vector<int> x_sel,y_sel;
    int k = N*2;
    lp(i,k){
      x_sel.push_back(gen.uniform<int>(XY_MIN,XY_MAX));
      y_sel.push_back(gen.uniform<int>(XY_MIN,XY_MAX));
    }
    set<pair<int,int>> s;
    lp(i,N){
      while(1){
	int rndx=gen.uniform<int>(0,k-1);
	int rndy=gen.uniform<int>(0,k-1);
	if(s.find({rndx,rndy})!=s.end())continue;
	s.insert({rndx,rndy});
        cout<<x_sel[rndx]<<" "<<y_sel[rndy]<<endl;
        break;
      }
    }
    return 0;
}
