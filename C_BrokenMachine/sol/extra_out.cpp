#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << max(n * 2 - 3, 0) << endl;
    for (int i = 1; i <= n - 1; i++){
        cout << i << " " << i + 1 << endl;
    }
    for (int i = 1; i <= n - 2; i++){
        cout << i << " " << n << endl;
    }
    cout << "0" << endl;

    return 0;
}
