#include <iostream>
#include <vector>

using namespace std;

const int example = 4;

int main() {
    int n;
    cin >> n;
    /*if (n == example){
        cout << "4" << endl;
        cout << "1 3" << endl;
        cout << "2 3" << endl;
        cout << "2 3" << endl;
        cout << "3 4" << endl;
        return 0;
    }*/

    cout << max(n * 2 - 3, 0) << endl;
    for (int i = 1; i <= n - 1; i++){
        cout << i << " " << i + 1 << endl;
    }
    for (int i = 1; i <= n - 2; i++){
        cout << i << " " << n << endl;
    }

    return 0;
}
