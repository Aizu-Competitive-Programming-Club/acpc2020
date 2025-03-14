#include<bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    using P = pair<long double,long double>;
    vector<P> differences;
    for(int i=0;i<n;++i){
        long double x;
        long double h;
        long double r;
        cin >> x >> h >> r;
        r /= 2;
        long double dh = h / r;
        differences.emplace_back(x-r,dh);
        differences.emplace_back(x,-2*dh);
        differences.emplace_back(x+r,dh);
    }
    long double ch = 0;
    long double cx = 0;
    long double cdh = 0;
    sort(differences.begin(),differences.end());
    long double ans = 0;
    for(auto i:differences){
        long double nx = i.first;
        long double adh = i.second;
        ch += cdh * (nx-cx);
        cdh += adh;
        cx = nx;
        ans = max(ans,ch);
    }

    printf("%.10Lf\n",(1+1e-5)*ans);
    return 0;
}
