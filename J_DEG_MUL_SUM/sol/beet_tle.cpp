#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int n,q;
  cin>>n>>q;

  using ll = long long;
  ll one=0,two=0,three=0;
  auto print=[&](){cout<<one+2*two+three<<'\n';};

  vector<set<int>> G(n);
  for(int i=0;i<q;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;

    if(!G[x].count(y)){
      one++;
      two+=G[x].size()+G[y].size();
      three+=1ULL*G[x].size()*G[y].size();

      for(int z:G[x]) three+=G[z].size()-1;
      for(int z:G[y]) three+=G[z].size()-1;

      G[x].emplace(y);
      G[y].emplace(x);
    }else{
      G[x].erase(y);
      G[y].erase(x);

      for(int z:G[x]) three-=G[z].size()-1;
      for(int z:G[y]) three-=G[z].size()-1;

      one--;
      two-=G[x].size()+G[y].size();
      three-=1ULL*G[x].size()*G[y].size();
    }

    // cout<<one<<' '<<two<<' '<<three<<endl;
    print();
  }
  return 0;
}
