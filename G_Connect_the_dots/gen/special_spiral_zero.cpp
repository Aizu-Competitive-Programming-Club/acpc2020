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
    cout<<N-1<<endl;

    vector<int> x_sel,y_sel;
    set<int> xl,yl;
    int k = N/2;
    lp(i,k){
      int x,y;
      while(1){
	x = gen.uniform<int>(XY_MIN,XY_MAX);
	y = gen.uniform<int>(XY_MIN,XY_MAX);
	if(xl.find(x)!=xl.end()||yl.find(y)!=yl.end()){
	  continue;
	}
	xl.insert(x);
	yl.insert(y);
	break;
      }
      x_sel.push_back(x);
      y_sel.push_back(y);
    }
    sort(x_sel.begin(),x_sel.end());
    sort(y_sel.begin(),y_sel.end());
    vector<pair<int,int>> v,w;
    lp(i,k/2){
      v.push_back({x_sel[i], y_sel[i]});
      v.push_back({x_sel[k-1-i], y_sel[k-1-i]});
      v.push_back({x_sel[i],y_sel[k-1-i]});
      if(i!=k/2-1)v.push_back({x_sel[k-1-i],y_sel[i+1]});
    }
    lp(i,v.size()){
      cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}
