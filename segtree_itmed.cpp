#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class ST {
private:
    vll sg;
public:
    int n;

    void init(int _n) {
        this->n = _n;
        sg.resize(4 * n + 5);
    }

    void update(int id, int start, int end, int i, ll val) {
        if (start > i || end < i) return;
        if (start == end) {
            sg[id] = val;
            return;
        }
        int mid = (start + end) >> 1;
        update(id << 1, start, mid, i, val);
        update(id << 1 | 1, mid + 1, end, i, val);
        sg[id] = max(sg[id << 1], sg[id << 1 | 1]);
    }

    ll get(int id, int start, int end, int l, int r) {
        if (start > r || end < l) return 0ll;
        if (l <= start and end <= r) return sg[id];
        int mid = (start + end) >> 1;
        return max(get(id << 1, start, mid, l, r), get(id << 1 | 1, mid + 1, end, l, r));
    }

    ll get_val(int id) {
        return sg[id];
    }

} tree;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    tree.init(n);
    vector<pair<ll, int>> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    for (int i = n; i >= 1; --i) {
        int left = min(arr[i].second + 1, n);
        int right = min(arr[i].second + k, n);
        ll max_val = tree.get(1, 1, n, left, right);
        tree.update(1, 1, n, arr[i].second, max_val + arr[i].first);
    }
    cout << max(tree.get_val(1), 0ll);
    return 0;
}
