#include <iostream>
#include <vector>
#include <set>
#define getAll(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef multiset<ll> msl;

class ST {
private:
    vll arr;
    vector<msl> tree;
public:
    int n, q;

    void init() {
        cin >> n >> q;
        arr.resize(n + 1);
        tree.resize(n << 2 | 1, msl());
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
    }

    void update(int id, int start, int end, int i, int val) {
        if (i < start or i > end) return;
        tree[id].erase(tree[id].lower_bound(arr[i]));
        if (start == end) {
            arr[i] = val;
            tree[id].insert(val);
            return;
        }
        int mid = (start + end) >> 1;
        int left = id << 1, right = id << 1 | 1;
        update(left, start, mid, i, val);
        update(right, mid + 1, end, i, val);
        tree[id].insert(val);
    }

    void build(int id, int start, int end) {
        if (start == end) {
            tree[id].insert(arr[start]);
            return;
        }
        int mid = (start + end) >> 1;
        int left = id << 1, right = id << 1 | 1;
        build(left, start, mid);
        build(right, mid + 1, end);
        tree[id].insert(getAll(tree[left]));
        tree[id].insert(getAll(tree[right]));
    }

    int query(int id, int start, int end, int l, int r, int k) {
        if (l > end or r < start) return -1;
        if (l <= start and end <= r) {
            msl::iterator it = tree[id].lower_bound(k);
            if (it == tree[id].end()) return -1;
            return *it;
        }
        int mid = (start + end) >> 1;
        int left_q = query(id << 1, start, mid, l, r, k);
        int right_q = query(id << 1 | 1, mid + 1, end, l, r, k);
        if (left_q == -1 and right_q != -1) return right_q;
        if (right_q == -1 and left_q != -1) return left_q;
        return min(left_q, right_q);
    }

    void solve() {
        build(1, 1, n);
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int i, v;
                cin >> i >> v;
                update(1, 1, n, i, v);
            }
            else {
                int l, r, k;
                cin >> l >> r >> k;
                cout << query(1, 1, n, l, r, k) << '\n';
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
