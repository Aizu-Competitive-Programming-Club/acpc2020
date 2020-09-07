#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << max(n + n * 2 - 3, 0) << endl;
    for (int i = 1; i <= n; i++){
        cout << i << " " << i << endl;
    }
    for (int i = 1; i <= n - 1; i++){
        cout << i << " " << i + 1 << endl;
    }
    for (int i = 1; i <= n - 2; i++){
        cout << i << " " << n << endl;
    }

    return 0;
}
