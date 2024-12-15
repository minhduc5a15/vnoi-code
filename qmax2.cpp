#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Tree {
private:
    vector<int> max_seg, delta;
public:
    int n, q;

    void init() {
        cin >> n >> q;
        max_seg.resize(n << 2 | 1), delta.resize(n << 2 | 1);
    }

    void update(int id, int start, int end, int l, int r, int k) {
        if (start > r || end < l || end < start) return;
        if (l <= start && end <= r) {
            max_seg[id] += k;
            delta[id] += k;
            return;
        }
        int mid = (start + end) >> 1;
        int left = id << 1, right = id << 1 | 1;
        update(left, start, mid, l, r, k);
        update(right, mid + 1, end, l, r, k);
        max_seg[id] = max(max_seg[left], max_seg[right]) + delta[id];
    }

    int get(int id, int start, int end, int l, int r) {
        if (start > r || end < l || end < start) return INT_MIN;
        if (l <= start && end <= r) return max_seg[id];
        int mid = (start + end) >> 1;
        int left = id << 1, right = id << 1 | 1;
        return max(get(left, start, mid, l, r), get(right, mid + 1, end, l, r)) + delta[id];
    }

    void solve() {
        while (q--) {
            int type, x, y;
            cin >> type >> x >> y;
            if (!type) {
                int d;
                cin >> d;
                update(1, 1, n, x, y, d);
            }
            else {
                cout << get(1, 1, n, x, y) << '\n';
            }
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
