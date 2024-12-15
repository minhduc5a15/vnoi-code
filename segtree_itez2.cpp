#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> BIT;
int n;

void update(int id, int val) {
    if (id <= n) BIT[id] += val, update(id + (id & -id), val);
}

ll get(int id) {
    return !id ? 0 : BIT[id] + get(id - (id & -id));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<ll> arr(n + 1);
    BIT.assign(n + 1, 0);
    int q;
    cin >> q;
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            update(x, -arr[x]);
            arr[x] = y;
            update(x, arr[x]);
        }
        else {
            cout << get(y) - get(x - 1) << '\n';
        }
    }
    return 0;
}
