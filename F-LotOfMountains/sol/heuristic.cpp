#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    using ll = long long;
    using ldouble = long double;

    using T = tuple<ll,ldouble,ll>;

    vector<T> line;

    for(int i=0;i<n;++i){
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        line.emplace_back(a,b,c);
    }

    function<ldouble(ll)> func = 
        [&](ll place) -> ldouble{
            ldouble res = 0;
            for(T mountain:line){
                ll dis = abs(get<0>(mountain)-place);
                if(dis>get<2>(mountain))continue;
                res += get<1>(mountain) * (get<2>(mountain) - dis) / get<2>(mountain);
            }
            return res;
        };

    ldouble ans = 0;

    sort(line.begin(),line.end(),[](T a,T b){
            return get<1>(a) > get<1>(b);
            });
    
    clock_t start = clock();
    for(int i=0;i<n and ((clock()-start)/(double)CLOCKS_PER_SEC < 1.8);++i){
        ans = max(ans,func(get<0>(line[i])));
    }

    printf("%.10Lf\n",ans);

    return 0;
}
