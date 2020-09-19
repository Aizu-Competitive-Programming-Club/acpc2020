#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << (n-1) * 2 - 1 << endl;
    for(int i=1;i<n-1;++i){
        cout << i << " " << i + 1 << endl;
        cout << i << " " << n << endl;
    }
    cout << n-1 << " " << n << endl;
    return 0;
}
