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

    vector<int> x_sel,y_sel;
    set<int> xl,yl;
    int k = N/100;
    vector<pair<int,int>> v;
    lp(i,k){
      int x,y;
      while(1){
	x = gen.uniform<int>(XY_MIN/100+2000,XY_MAX/100-2000);
	y = x+gen.uniform<int>(-1000,1000);

	if(xl.find(x)!=xl.end()||yl.find(y)!=yl.end()){
	  continue;
	}
	xl.insert(x);
	yl.insert(y);
	break;
      }
      v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>> res;
    lp(i,v.size()){
      int cn = gen.uniform<int>(50,100);
      vector<pair<int,int>> ls={v[i]};
      lp(j,cn){
	while(1){
	  int l = gen.uniform<int>(100, 100000);
	  int d = gen.uniform<int>(0, 3);
	  int dx[4] = {0,0,1,-1};
	  int dy[4] = {1,-1,0,0};
	  int t = gen.uniform<int>(0,ls.size()-1);

	  int tx = max(min((long long)ls[t].first + l*dx[d], XY_MAX),XY_MIN);
	  int ty = max(min((long long)ls[t].second + l*dy[d], XY_MAX),XY_MIN);
	  if(xl.find(tx)!=xl.end()&&yl.find(ty)!=yl.end()) continue;
	  xl.insert(tx);
	  yl.insert(ty);
	  ls.push_back({tx,ty});
	  break;
	}
      }
      lp(i,ls.size()){
	res.push_back(ls[i]);
      }
    }
    cout<<res.size()<<endl;
    lp(i,res.size()){
      printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}
