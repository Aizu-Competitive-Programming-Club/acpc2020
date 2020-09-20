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
const ll INFLL = (ll)1e18;
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

template<long long mod>
class modint{
	public:
		long long x;
		modint(long long a){x=a%mod;if(x<0)x+=mod;}
		modint(){x=0;}

		modint pow(long long a){
			modint res(1), b(x);
			while(a){
				if(a&1)res*=b;
				b*=b;
				a>>=1;
			}
			return res;
		}

		modint inv(){return pow(mod-2);}

		modint& operator+=(modint a){x=(x+a.x)%mod;return *this;}
		modint& operator-=(modint a){x=x-a.x;if(x<0)x+=mod;return *this;}
		modint& operator*=(modint a){x=x*a.x%mod;return *this;}
		modint& operator/=(modint a){x=x*a.inv().x%mod;return *this;}

		modint operator+(modint a){return modint(x)+=a;}
		modint operator-(modint a){return modint(x)-=a;}
		modint operator*(modint a){return modint(x)*=a;}
		modint operator/(modint a){return modint(x)/=a;}

		modint operator-(){return modint(x);}

		bool operator==(const modint a){return x == a.x;}
		bool operator<(const modint a){return x < a.x;}
		bool operator>(const modint a){return x > a.x;}
};

template<long long mod>
ostream& operator<<(ostream& os, const modint<mod>& a){
	os << a.x;
	return os;
}
using mint = modint<MOD>;

const int MAX_K = 1010;
using bset = bitset<MAX_K>;

bset mul(vector<int> a,bset b){
    bset res;
    rep(i,a.size()){
        res[i] = b[a[i]];
    }
    return res;
}

vector<int> mul(vector<int> a,vector<int> b){
    int n = a.size();
    vector<int> res(n);
    rep(i,n){
        res[i] = b[a[i]];
    }
    return res;
}

vector<bset> sweep(vector<bset> values){
    int cnt = 0;
    rep(i,MAX_K){
        int itr = INF;
        rep(j,cnt,values.size()){
            if(values[j][i]){
                itr = j;
                break;
            }
        }
        if(itr==INF)continue;
        swap(values[cnt],values[itr]);
        rep(j,cnt+1,values.size()){
            if(values[j][i])values[j] ^= values[cnt];
        }
        ++cnt;
    }
    while(values.size() and values.back().none())values.pop_back();
    return values;
}

mint func(){
    int n = in();
    int k = in();
    vector<int> p(k);
    foreach(i,p)i=in();
    vector<bset> values;
    rep(i,n){
        bset value;
        per(j,k)value[j] = in<char>()=='1';
        values.emplace_back(value);
    }
    int sum = 1;
    while(sum<k){
        per(i,values.size())values.emplace_back(mul(p,values[i]));
        values = sweep(values);
        p = mul(p,p);
        sum *= 2;
    }
    return mint(2).pow(values.size());
}

int main(){
    cout << func() << endl;
  return 0;
}
