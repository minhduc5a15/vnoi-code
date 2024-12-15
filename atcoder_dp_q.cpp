#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<ll> BIT;
int n;

void update(int id, ll val) {
    if (id <= n) BIT[id] = max(BIT[id], val), update(id + (id & -id), val);
}

ll get(int id) {
    return !id ? 0 : max(BIT[id], get(id - (id & -id)));
}

struct flower {
    int h;
    ll a;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<flower> arr(n);
    BIT.assign(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].h;
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].a;
    }
    for (int i = 0; i < n; ++i) {
        update(arr[i].h, get(arr[i].h - 1) + arr[i].a);
    }
    cout << get(n);
    return 0;
}
