#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;
#define lp(i,n) for(int i=0;i<(signed)n;i++)

const long long XY_MIN = XY_ABS * -1;
const long long XY_MAX = XY_ABS;
int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = N_MAX;
    printf("%d\n", N);

    vector<int> x_sel,y_sel;
    set<int> xl,yl;
    int k = N/2;
    vector<pair<int,int>> v;
    lp(i,k){
      int x,y;
      while(1){
	x = gen.uniform<int>(XY_MIN+2000,XY_MAX-2000);
	y = x+gen.uniform<int>(-1000,1000);
	
	if(xl.find(x)!=xl.end()||yl.find(y)!=yl.end()){
	  continue;
	}
	xl.insert(x);
	yl.insert(y);
	break;
      }
      int l = gen.uniform<int>(100000, 1000000);
      int d = gen.uniform<int>(0, 3);
      int dx[4] = {0,0,1,-1};
      int dy[4] = {1,-1,0,0};

      int tx = max(min((long long)x + l*dx[d], XY_MAX),XY_MIN);
      int ty = max(min((long long)y + l*dy[d], XY_MAX),XY_MIN);
      v.push_back({x,y});
      v.push_back({tx,ty});
    }
    gen.shuffle(v.begin(),v.end());
    lp(i,v.size()){
      printf("%d %d\n", v[i].first, v[i].second);
    }
    
    return 0;
}
