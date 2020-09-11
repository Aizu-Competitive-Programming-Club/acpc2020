#include <bits/stdc++.h>
using namespace std;

// source : https://community.topcoder.com/stat?c=problem_statement&pm=15639&rd=17637

#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=1;i<=n;++i)
#define rng(v) v.begin(),v.end()
#define pb push_back
#define fi first
#define se second
#define sz(x) int(x.size())
#define v(T) vector<T>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef v(int) vi;
typedef v(vi) vvi;
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
const int di[] = {-1,0,1,0,-1,1,-1,1}, dj[] = {0,-1,0,1,-1,-1,1,1};

struct uf {
  vi d;
  uf(){}
  uf(int mx):d(mx,-1){}
  int root(int x) {
    if(d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  int size(int x) { return -d[root(x)];}
};
//

class DisappearingGridGraph {
public:
  void keepErasing() {
    int h,w,n;
    cin>>h>>w>>n;

    vvi a(h+2,vi(w+2,1));
    rrep(i,h)rrep(j,w) a[i][j] = 0;

    h += 2; w += 2;
    uf d(h*w);
    rep(i,h)rep(j,w) {
      int v = i*w+j;
      if (!a[i][j]) continue;
      if (i) {
        int ni = i-1, nj = j;
        int u = ni*w+nj;
        if (a[ni][nj]) d.unite(v,u);
      }
      if (j) {
        int ni = i, nj = j-1;
        int u = ni*w+nj;
        if (a[ni][nj]) d.unite(v,u);
      }
    }

    int add = 1;

    for(int i=1;i<h-1;i++){
      string b;
      cin>>b;
      for(int j=1;j<w-1;j++){
        if(b[j - 1] == '#') continue;

        a[i][j] = 1;
        add--; add++;
        int nv = i*w+j;
        rep(v,8) {
          int ni = i+di[v], nj = j+dj[v];
          if (v >= 4) {
            int cnt = a[i][nj]+a[ni][j]+a[ni][nj];
            if (cnt == 3) {
              --add;
              continue;
            }
            if (cnt == 2) --add;
          }
          if (!a[ni][nj]) continue;
          add++;
          int u = ni*w+nj;
          if (d.unite(nv,u)) --add;
        }
      }
    }

    int state = 0;
    rep(ti,n) {
      int uuu, vvv;
      cin >> uuu >> vvv;
      int i = (state ^ uuu) % (1<<10);
      int j = (state ^ vvv) % (1<<10);
      ++i; ++j;
      assert(!a[i][j]);

      a[i][j] = 1;
      add--; add++;
      int nv = i*w+j;
      rep(v,8) {
        int ni = i+di[v], nj = j+dj[v];
        if (v >= 4) {
          int cnt = a[i][nj]+a[ni][j]+a[ni][nj];
          if (cnt == 3) {
            --add;
            continue;
          }
          if (cnt == 2) --add;
        }
        if (!a[ni][nj]) continue;
        add++;
        int u = ni*w+nj;
        if (d.unite(nv,u)) --add;
      }

      cout << add << '\n';
      state = (427 * state + 821 * add) % (1<<10);
    }
  }
};

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  DisappearingGridGraph ans;
  ans.keepErasing();
  return 0;
}
