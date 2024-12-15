#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll res = 0, count = 0;
        cin >> n;
        map<ll, ll> mp;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x]++;
        }
        for (auto [_, v]: mp) {
            res += v * (v - 1) * (v - 2) / 6;
            res += v * (v - 1) / 2 * count;
            count += v;
        }
        cout << res << '\n';
    }
    return 0;
}
