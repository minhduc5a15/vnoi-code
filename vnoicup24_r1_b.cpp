#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 200005;

vector<int> v_a(MAXN), v_b(MAXN);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        auto solve = []() {
            int n;
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cin >> v_a[i];
            }
            for (int i = 0; i < n; ++i) {
                cin >> v_b[i];
            }
            for (int i = 0; i < n - 1; ++i) {
                v_a[i + 1] += v_a[i] / 2;
                v_a[i] &= 1;
                v_b[i + 1] += v_b[i] / 2;
                v_b[i] &= 1;
            }
            for (int i = n - 1; i >= 0; --i) {
                if (v_a[i] > v_b[i]) {
                    cout << "YES\n";
                    return;
                }
                else if (v_a[i] < v_b[i]) {
                    cout << "NO\n";
                    return;
                }
            }
            cout << "YES\n";
            return;
        };
        solve();
    }

    return 0;
}
