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


class union_find{
    public:
        int n;
        vector<int> parent;
        union_find(int _n):n(_n){
            parent.resize(n);
            rep(i, n){
                parent[i]=i;
            }
        }

        int get_parent(int x){
            if(parent[x]==x)return x;
            return parent[x] = get_parent(parent[x]);
        }

        bool is_same(int a, int b){
            int ap = get_parent(a);
            int bp = get_parent(b);
            return ap == bp;
        }

        void merge(int a, int b){
            int ap = get_parent(a);
            int bp = get_parent(b);
            if(ap==bp)return;
            parent[bp] = ap;
        }

};

int count_lands(vvector<int> board){


    int h = board.size();
    int w = board.front().size();

    method(is_land,bool,int y,int x){
        if(y<0 or x<0 or h<=y or w<=x)return false;
        return board[y][x];
    };

    int res = 0;
    int dx4[]={1,0,-1,0};
    int dy4[]={0,-1,0,1};
    rep(i,h){
        rep(j,w){
            if(!board[i][j])continue;
            ++res;
            stack<pii> st;
            st.emplace(i,j);
            board[i][j] = false;
            while(st.size()){
                int y = st.top().first;
                int x = st.top().second;
                st.pop();
                rep(i,4){
                    int ty = y + dy4[i];
                    int tx = x + dx4[i];
                    if(!is_land(ty,tx))continue;
                    st.emplace(ty,tx);
                    board[ty][tx] = false;
                }
            }
        }
    }
    return res;
}

vector<int> func(){
    int h = in();
    int w = in();
    int n = in();
    vvector<int> board(h,vector<int>(w));
    foreach(i,board)foreach(j,i)j=in<char>()=='#';

    method(number,int,int y,int x){
        if(y<0 or x<0 or h<=y or w<=x)return 0;
        return y * w + x + 1;
    };

    method(is_land,bool,int y,int x){
        if(y<0 or x<0 or h<=y or w<=x)return false;
        return board[y][x];
    };

    union_find uf(h*w + 10);

    int dx4[]={1,0,-1,0};
    int dy4[]={0,-1,0,1};
    int dx8[]={1,1,1,0,-1,-1,-1,0};
    int dy8[]={1,0,-1,-1,-1,0,1,1};
    rep(i,h){
        rep(j,w){
            if(board[i][j])continue;
            rep(k,8){
                int ty = i + dy8[k];
                int tx = j + dx8[k];
                if(is_land(ty,tx))continue;
                uf.merge(number(i,j),number(ty,tx));
            }
        }
    }


    method(func,int,int r,int c){
        --r;
        --c;
        method(get_pos8,pii,int dir){
            return pii(r+dy8[dir],c+dx8[dir]);
        };
        method(is_land8,bool,int dir){
            return is_land(r+dy8[dir],c+dx8[dir]);
        };
        board[r][c] = false;
        vector<int> pos;
        rep(i,4){
            int ty = r + dy4[i];
            int tx = c + dx4[i];
            if(!is_land(ty,tx))continue;
            pos.emplace_back(i*2+1);
        }
        int res = 0;
        if(pos.size()>=2){
            int cnt = 0;
            rep(i,pos.size()){
                int j = (i+1) % pos.size();
                vector<int> p1s;
                vector<int> p2s;
                for(int p=(pos[i]+1)%8;p!=pos[j];p=(p+1)%8){
                    int ty = dy8[p] + r;
                    int tx = dx8[p] + c;
                    if(!is_land(ty,tx)){
                        p1s.emplace_back(p);
                    }
                }
                for(int p=(pos[j]+1)%8;p!=pos[i];p=(p+1)%8){
                    int ty = dy8[p] + r;
                    int tx = dx8[p] + c;
                    if(!is_land(ty,tx)){
                        p2s.emplace_back(p);
                    }
                }
                if(p1s.size())++cnt;
                if((lambda(bool){
                            foreach(p1,p1s){
                                int ty1 = dy8[p1] + r;
                                int tx1 = dx8[p1] + c;
                                foreach(p2,p2s){
                                    int ty2 = dy8[p2] + r;
                                    int tx2 = dx8[p2] + c;
                                    if(uf.is_same(number(ty1,tx1),number(ty2,tx2)))return false;
                                }
                            }
                            return true;
                            })())continue;
                ++res;
            }
            if(res==cnt and (lambda(bool){
                        rep(i,8){
                            int ty = r + dy8[i];
                            int tx = c + dx8[i];
                            if(!is_land(ty,tx))return true;
                        }
                        return false;})())--res;
            map<int,int> m;
            rep(i,8){
                if(is_land8(i))continue;
                if(!is_land8((i+7)%8))continue;
                pii pos = get_pos8(i);
                int y = pos.first;
                int x = pos.second;
                if(i%2==0){
                    ++m[uf.get_parent(number(y,x))];
                }else{
                    if(is_land8((i+6)%8)){
                        ++m[uf.get_parent(number(y,x))];
                    }
                }
            }
            res = 0;
            foreach(i,m){
                res += i.second - 1;
            }
        }else{
            if(pos.empty())--res;
        }
        rep(i,8){
            int y = r + dy8[i];
            int x = c + dx8[i];
            if(is_land(y,x))continue;
            uf.merge(number(r,c),number(y,x));
        }
        return res;
    };

    vector<int> ans(n);

    int sum = count_lands(board);

    int s = 0;
    rep(i,n){
        int u = in();
        int v = in();
        if(i){
            s = 427 * s + 821 * ans[i-1];
            s %= bit(10);
        }
        sum += func((s^u)%bit(10)+1,(s^v)%bit(10)+1);
        ans[i] = sum;
    }
    return ans;
}

int main(){
    vector<int> ans = func();
    foreach(i,ans)cout << i << endl;
    return 0;
}
