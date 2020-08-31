#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n,q;
  cin>>n>>q;

  using P = pair<int, int>;
  set<P> es;
  vector<long long> cnt(n);

  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;

    if(es.count(P(x,y))){
      es.erase(P(x,y));
      cnt[x]--;
      cnt[y]--;
    }else{
      es.emplace(x,y);
      cnt[x]++;
      cnt[y]++;
    }

    long long ans=0;
    for(auto [a, b]:es)
      ans+=cnt[a]*cnt[b];
    cout<<ans<<'\n';
  }
  return 0;
}
