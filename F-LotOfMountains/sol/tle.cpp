#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    using ll = long long;
    using ldouble = long double;

    using T = tuple<ll,ldouble,ldouble>;

    vector<T> line;

    for(int i=0;i<n;++i){
        int a;
        ldouble b;
        ldouble c;
        cin >> a >> b >> c;
        line.emplace_back(a,b,c/2);
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

    
    for(int i=0;i<n;++i){
        ans = max(ans,func(get<0>(line[i])));
    }

    printf("%.10Lf\n",ans);

    return 0;
}
