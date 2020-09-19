#include <iostream>
#include <vector>
#include "random.h"
#include "../params.h"
using namespace std;
#define lp(i,n) for(int i=0;i<(signed)n;i++)

const long long XY_MIN = XY_ABS * -1/100;
const long long XY_MAX = XY_ABS/100;
int main(int, char* argv[]) {

    long long seed = atoll(argv[1]);
    auto gen = Random(seed);

    int N = N_MAX;

    vector<int> x_sel,y_sel;
    set<int> xl,yl;
    int k = gen.uniform<int>(N/10,N);
    lp(i,k+10){
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
    vector<pair<int,int>> lis;
    pair<int,int> goal;
    lp(i,k){
      if(i%2==0){
	lis.push_back({x_sel[i], y_sel[(i/2)*2]});
      }
      else{
	lis.push_back({x_sel[i+2], y_sel[(i/2)*2]});
      }
    }
    pair<int,int> s1=lis[0],s2=lis[1],g1=lis[lis.size()-2],g2=lis[lis.size()-1];
    int gg = N - k;
    gg/=2;
    lis.erase(lis.begin(), lis.begin()+2);
    lis.erase(lis.end()-2, lis.end());
    int t = gen.uniform<int>(0,k-10);
    for(int i=0;i<gg;i++){
      int xt1 = gen.uniform<int>(x_sel[t],x_sel[t]+1000000);
      int xt2 = xt1 + 1000000;
      int yt = gen.uniform<int>(XY_MIN,XY_MAX);
      if(xl.find(xt1)!=xl.end()||xl.find(xt2)!=xl.end()||yl.find(yt)!=yl.end()){
	i--;
	continue;
      }
      lis.push_back({xt1, yt});
      lis.push_back({xt2, yt});
    }
    //gen.shuffle(lis.begin(),lis.end());
    cout<<lis.size()+4<<endl;
    cout<<s1.first<<" "<<s1.second<<endl;
    cout<<s2.first<<" "<<s2.second<<endl;
    lp(i,lis.size()){
      cout<<lis[i].first<<" "<<lis[i].second<<endl;
    }
    cout<<g1.first<<" "<<g1.second<<endl;
    cout<<g2.first<<" "<<g2.second<<endl;

    return 0;
}
