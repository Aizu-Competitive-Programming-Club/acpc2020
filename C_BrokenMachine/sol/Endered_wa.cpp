#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << (n-1) * 2 << endl;
    for(int i=1;i<n;++i){
        cout << i << " " << i + 1 << endl;
        cout << i << " " << n << endl;
    }
    return 0;
}
