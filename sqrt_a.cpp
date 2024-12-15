#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 200005;

vector<ll> BIT(MAXN);

void update(int id, int val) {
    if (id > MAXN) return;
    return BIT[id] += val, update(id + (id & -id), val);
}

ll get(int id) {
    return !id ? 0 : BIT[id] + get(id - (id & -id));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(k, u - arr[k]);
            arr[k] = u;
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get(r) - get(l - 1) << '\n';
        }
    }
    return 0;
}
