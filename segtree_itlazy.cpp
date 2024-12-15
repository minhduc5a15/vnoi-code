#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class ST {
private:
    vll arr;
    vll sg;
    vll lazy;

    void propagate(int id, int start, int end) {
        if (lazy[id] != 0) {
            sg[id] += lazy[id];
            if (start != end) {
                lazy[id << 1] += lazy[id];
                lazy[id << 1 | 1] += lazy[id];
            }
            lazy[id] = 0;
        }
    }

    void build(int id, int start, int end) {
        if (start == end) {
            sg[id] = arr[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(id << 1, start, mid);
        build(id << 1 | 1, mid + 1, end);
        sg[id] = max(sg[id << 1], sg[id << 1 | 1]);
    }

    void updateRange(int id, int start, int end, int l, int r, ll val) {
        propagate(id, start, end);
        if (start > r or end < l) return;
        if (l <= start and end <= r) {
            lazy[id] += val;
            propagate(id, start, end);
            return;
        }
        int mid = (start + end) >> 1;
        updateRange(id << 1, start, mid, l, r, val);
        updateRange(id << 1 | 1, mid + 1, end, l, r, val);
        sg[id] = max(sg[id << 1], sg[id << 1 | 1]);
    }

    ll get(int id, int start, int end, int l, int r) {
        propagate(id, start, end);
        if (start > r or end < l) return LONG_LONG_MIN;
        if (l <= start and end <= r) return sg[id];
        int mid = (start + end) >> 1;
        return max(get(id << 1, start, mid, l, r), get(id << 1 | 1, mid + 1, end, l, r));
    }

public:
    int n;

    void init() {
        cin >> n;
        sg.resize(n << 2 | 1);
        lazy.resize(n << 2 | 1);
        arr.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        this->build(1, 1, n);
    }

    void updateRange(int l, int r, int val) {
        this->updateRange(1, 1, n, l, r, val);
    }

    void query(int l, int r) {
        cout << get(1, 1, n, l, r) << '\n';
    }

} tree;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    tree.init();
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y, val;
            cin >> x >> y >> val;
            tree.updateRange(x, y, val);
        }
        else {
            int l, r;
            cin >> l >> r;
            tree.query(l, r);
        }
    }
    return 0;
}
