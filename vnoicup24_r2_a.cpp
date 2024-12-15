#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    vector<ll> arr;
    while (t--) {
        int n;
        ll x;
        cin >> n >> x;
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int pos = -1;
            for (int j = arr.size() - 1; j >= 0; --j) {
                if (x >= arr[j] / i + (arr[j] % i != 0)) {
                    pos = j;
                    break;
                }
            }
            if (pos == -1) {
                break;
            }
            res++;
            arr.erase(arr.begin() + pos);
        }
        arr.clear();
        cout << res << '\n';
    }
    return 0;
}
