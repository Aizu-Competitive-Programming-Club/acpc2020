#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)

int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = N_MAX;
    printf("%d\n", N);

    vector<int> x_sel,y_sel;
    set<int> xl,yl;
    int k = N;
    lp(i,k){
      int x,y;
      while(1){
	x = gen.uniform<int>(XY_MIN,XY_MAX);
	y = gen.uniform<int>(XY_MIN,XY_MAX);
	if(xl.find(x)!=xl.end()||yl.find(y)!=yl.end()){
	  continue;
	}
	break;
      }
      x_sel.push_back(x);
      y_sel.push_back(y);
    }
    sort(x_sel.begin(),x_sel.end());
    sort(y_sel.begin(),y_sel.end());
    lp(i,N){
      if(i%2==0)cout<<x_sel[N/2+i/2]<<" "<<y_sel[(i/2)*2]<<endl;
      else cout<<x_sel[N/2-1-i/2]<<" "<<y_sel[(i/2)*2]<<endl;
    }
    return 0;
}
