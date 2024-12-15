#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int n = 1;
        while ((1 << n) - 2 <= x) ++n;
        cout << --n << '\n';
        for (int i = 0; i < n; ++i) {
            cout << (1 << n) - (1 << i) - 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
