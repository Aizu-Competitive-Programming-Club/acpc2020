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
    cout<<N<<endl;

    vector<int> x_sel,y_sel;
    set<int> xl,yl;
    int k = N/8;
    lp(i,k){
      int x,y;
      while(1){
	x = gen.uniform<int>(XY_MIN,XY_MAX)/10*10;
	y = gen.uniform<int>(XY_MIN,XY_MAX)/10*10;
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
    lp(i,k){
      v.push_back({x_sel[i], y_sel[i]});
      v.push_back({x_sel[N/8-1-i], y_sel[N/8-1-i]});
      w.push_back({x_sel[i],y_sel[N/8-1-i]});
      w.push_back({x_sel[N/8-1-i],y_sel[i]});
    }
    lp(i,v.size()){
      int l = gen.uniform<int>(1,3);
      cout<<v[i].first-l<<" "<<v[i].second-l<<endl;
      cout<<v[i].first+l<<" "<<v[i].second+l<<endl;
    }
    lp(i,w.size()){
      int l = gen.uniform<int>(1,3);
      cout<<w[i].first-l<<" "<<w[i].second-l<<endl;
      cout<<w[i].first+l<<" "<<w[i].second+l<<endl;
    }
    return 0;
}
