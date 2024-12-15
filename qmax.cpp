#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<int> vi;

class Tree {
private:
    vi max_seg, delta;

public:
    int n, m, q;

    void init() {
        cin >> n >> m;
        max_seg.resize(n << 2 | 1, 0), delta.resize(n << 2 | 1, 0);
    }

    void update(int id, int start, int end, int l, int r, int val) {
        if (start > r || end < l) return;
        if (l <= start && end <= r) {
            max_seg[id] += val;
            delta[id] += val;
            return;
        }
        int mid = (start + end) >> 1, left = id << 1, right = id << 1 | 1;
        update(left, start, mid, l, r, val);
        update(right, mid + 1, end, l, r, val);
        max_seg[id] = max(max_seg[left], max_seg[right]) + delta[id];
    }

    int query(int id, int start, int end, int l, int r) {
        if (start > r || end < l) return INT_MIN;
        if (l <= start && end <= r) return max_seg[id];
        int mid = (start + end) >> 1, left = id << 1, right = id << 1 | 1;
        return max(query(left, start, mid, l, r), query(right, mid + 1, end, l, r)) + delta[id];
    }

    void solve() {
        while (m--) {
            int l, r, val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        }
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
} tree;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    tree.init();
    tree.solve();
    return 0;
}
