#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << 2 * (n - 1) << endl;
    for (int i = 1; i < n; i++) {
        cout << i << ' ' << i + 1 << '\n';
    }
    for (int i = 2; i <= n; i++) {
        cout << 1 << ' ' << i << '\n';
    }
}
