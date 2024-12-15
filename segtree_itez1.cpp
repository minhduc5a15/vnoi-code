#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

class ST {
private:
    vll arr;
    vll seg;
    int n;

    void build(int id, int start, int end) {
        if (start == end) {
            seg[id] = arr[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(id << 1, start, mid);
        build(id << 1 | 1, mid + 1, end);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }

    void update(int id, int start, int end, int x, int y) {
        if (start > x or end < x) return;
        if (start == end) {
            seg[id] = y;
            return;
        }
        int mid = (start + end) >> 1;
        update(id << 1, start, mid, x, y);
        update(id << 1 | 1, mid + 1, end, x, y);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }

    ll get(int id, int start, int end, int l, int r) {
        if (start > r or end < l) return LONG_LONG_MIN;
        if (l <= start and end <= r) return seg[id];
        int mid = (start + end) >> 1;
        return max(get(id << 1, start, mid, l, r), get(id << 1 | 1, mid + 1, end, l, r));
    }

public:
    void init() {
        cin >> n;
        arr.assign(n + 1, 0);
        seg.assign(n << 2 | 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
    }

    void build() {
        this->build(1, 1, n);
    }

    void update(int x, int y) {
        this->update(1, 1, n, x, y);
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
    tree.build();
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            tree.update(x, y);
        }
        else {
            int l, r;
            cin >> l >> r;
            tree.query(l, r);
        }
    }
    return 0;
}
