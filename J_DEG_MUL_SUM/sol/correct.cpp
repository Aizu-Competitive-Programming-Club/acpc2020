#include <bits/stdc++.h>
using namespace std;

using Int = long long;
const char newl = '\n';

//INSERT ABOVE HERE
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n,q;
  cin>>n>>q;

  vector<int> us(q),vs(q);
  for(int i=0;i<q;i++) cin>>us[i]>>vs[i],us[i]--,vs[i]--;

  using ll = long long;
  ll one=0,two=0,three=0;
  auto print=[&](){cout<<three+2*two+one<<newl;};

  using P = pair<int, int>;
  set<P> es;

  vector<ll> deg(n,0),sum(n,0);
  auto calc_two=[&](int v){return deg[v]*(deg[v]-1)/2;};


  const int B = 200;
  vector<int> ts,rev(n,0);
  vector ex(2*B,vector(2*B,0));

  // 3 -> 2 -> 1
  auto add_edge=[&](int u,int v){
    // inside
    three+=deg[u]*deg[v];
    // tip
    three+=(sum[u]-deg[u])+(sum[v]-deg[v]);

    two-=calc_two(u)+calc_two(v);

    deg[u]++;deg[v]++;
    sum[u]+=deg[v];
    sum[v]+=deg[u];

    for(int i=0;i<(int)ts.size();i++){
      if(ex[rev[u]][i]) sum[ts[i]]++;
      if(ex[rev[v]][i]) sum[ts[i]]++;
    }
    ex[rev[u]][rev[v]]=ex[rev[v]][rev[u]]=1;

    two+=calc_two(u)+calc_two(v);

    one++;

    es.emplace(u,v);
  };

  // 1 -> 2 -> 3
  auto rmv_edge=[&](int u,int v){
    one--;

    two-=calc_two(u)+calc_two(v);

    ex[rev[u]][rev[v]]=ex[rev[v]][rev[u]]=0;
    for(int i=0;i<(int)ts.size();i++){
      if(ex[rev[u]][i]) sum[ts[i]]--;
      if(ex[rev[v]][i]) sum[ts[i]]--;
    }

    sum[u]-=deg[v];
    sum[v]-=deg[u];
    deg[u]--;deg[v]--;

    two+=calc_two(u)+calc_two(v);

    // inside
    three-=deg[u]*deg[v];
    // tip
    three-=(sum[u]-deg[u])+(sum[v]-deg[v]);

    es.erase(P(u,v));
  };

  vector used(n,0);
  for(int s=0;s<q;s+=B){
    int t=min(s+B,q);

    for(int i=0;i<n;i++) sum[i]=0;

    ts.clear();
    for(int i=s;i<t;i++){
      used[us[i]]=used[vs[i]]=1;
      ts.emplace_back(us[i]);
      ts.emplace_back(vs[i]);
    }

    sort(ts.begin(),ts.end());
    ts.erase(unique(ts.begin(),ts.end()),ts.end());
    for(int i=0;i<(int)ts.size();i++) rev[ts[i]]=i;

    // initialize ex
    for(int i=0;i<(int)ts.size();i++)
      for(int j=0;j<(int)ts.size();j++)
        ex[i][j]=0;

    for(auto [a,b]:es){
      sum[a]+=deg[b];
      sum[b]+=deg[a];
      if(used[a] and used[b])
        ex[rev[a]][rev[b]]=ex[rev[b]][rev[a]]=1;
    }

    for(int i=s;i<t;i++){
      if(!ex[rev[us[i]]][rev[vs[i]]])
        add_edge(us[i],vs[i]);
      else
        rmv_edge(us[i],vs[i]);

      // cout<<one<<' '<<two<<' '<<three<<endl;
      print();
    }

    for(int i=s;i<t;i++)
      used[us[i]]=used[vs[i]]=0;
  }

  return 0;
}
