#include "testlib.h"
#include "params.h"
#include <bits/stdc++.h>
using namespace std;
const long long XY_MIN = XY_ABS * -1;
const long long XY_MAX = XY_ABS;
int main() {
    registerValidation();

    int n = inf.readInt(N_MIN, N_MAX);
    inf.readChar('\n');
    set<pair<int,int>> s;
    for(int i=0;i<n;i++){
      int x = inf.readInt(XY_MIN, XY_MAX);
      inf.readChar(' ');
      int y = inf.readInt(XY_MIN, XY_MAX);
      inf.readChar('\n');
      if(s.find({x,y}) != s.end()){
	assert("two dots in same place");
      }
      s.insert({x,y});
    }
    inf.readEof();
    return 0;
}
