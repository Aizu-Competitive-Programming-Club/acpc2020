#include<bits/stdc++.h>
#define rep(i,a,...) for(int i = (a)*(strlen(#__VA_ARGS__)!=0);i<(int)(strlen(#__VA_ARGS__)?__VA_ARGS__:(a));++i)
#define per(i,a,...) for(int i = (strlen(#__VA_ARGS__)?__VA_ARGS__:(a))-1;i>=(int)(strlen(#__VA_ARGS__)?(a):0);--i)
#define foreach(i, n) for(auto &i:(n))
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
#define lambda(RES_TYPE, ...) (function<RES_TYPE(__VA_ARGS__)>)[&](__VA_ARGS__) -> RES_TYPE
#define method(FUNC_NAME, RES_TYPE, ...) function<RES_TYPE(__VA_ARGS__)> FUNC_NAME = lambda(RES_TYPE, __VA_ARGS__)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
//const ll MOD = (ll)1e9+7;
const ll MOD = 998244353;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)2e18;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}
#ifdef DEBUG
#define debug(x) cout<<"LINE "<<__LINE__<<": "<<#x<<" = "<<x<<endl;
#else
#define debug(x) (void)0
#endif

namespace templates{
  ll modpow(ll x, ll b){
    ll res = 1;
    while(b){
      if(b&1)res = res * x % MOD;
      x = x * x % MOD;
      b>>=1;
    }
    return res;
  }

  ll modinv(ll x){
    return modpow(x, MOD-2);
  }

  bool was_output = false;
  template<class t>
  void output(t a){
    if(was_output)cout << " ";
    cout << a;
    was_output = true;
  }
  void outendl(){
    was_output = false;
    cout << endl;
  }
  ll in(){
    ll res;
    scanf("%lld", &res);
    return res;
  }

  template<class t>
  istream& operator>>(istream&is, vector<t>&x){
    for(auto &i:x)is >> i;
    return is;
  }

  template<class t, class u>
  istream& operator>>(istream&is, pair<t, u>&x){
    is >> x.first >> x.second;
    return is;
  }

  template<class t>
  void in(t&x){
    cin >> x;
  }

  template<class t>
  t in(){
    t res; cin >> res; return res;
  }

  template<class t>
  void out(t x){
    cout << x;
  }

  template<class t>
  vector<t> sorted(vector<t> line,function<bool(t,t)> comp=[](t a,t b){return a<b;}){
    sort(line.begin(),line.end(),comp);
    return line;
  }

  template<class t>
  vector<t> reversed(vector<t> line){
    reverse(line.begin(),line.end());
    return line;
  }
}

using namespace templates;

vector<ll> func(){
    int n = in();
    int m = in();
    vector<pll> lines(n);
    foreach(i,lines)i = in<pll>();
    vector<ll> res;
    rep(i,m){
        int l = in()-1;
        int r = in();
        ll p = in();
        ll ans = INFLL;
        rep(j,l,r){
            chmin(ans,lines[j].first * p + lines[j].second); 
        }
        res.emplace_back(ans);
    }
    return res;
}

int main(){
    vector<ll> ans = func();
    foreach(i,ans){
        cout << i << endl;
    }
  return 0;
}
