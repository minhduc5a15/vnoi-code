#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define getAll(x) (x).begin(), (x).end()
using namespace std;
typedef vector<int> vi;

class MergeSortTree {
private:
    vi arr;
    vector<vi> tree;
public:
    int n, q;

    void init() {
        cin >> n;
        tree.resize(4 * n + 5);
        arr.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
    }

    void build(int id, int start, int end) {
        if (start == end) {
            tree[id].push_back(arr[start]);
            return;
        }
        int mid = (start + end) >> 1;
        int left_node = id << 1, right_node = left_node + 1;
        build(left_node, start, mid);
        build(right_node, mid + 1, end);
        merge(getAll(tree[left_node]), getAll(tree[right_node]), back_inserter(tree[id]));
    }

    int query(int id, int start, int end, int l, int r, int k) {
        if (l > end || r < start) return 0;
        if (l <= start && r >= end) {
            return tree[id].end() - upper_bound(getAll(tree[id]), k);
        }
        int left_node = id << 1, right_node = id << 1 | 1;
        int mid = (start + end) >> 1;
        return query(left_node, start, mid, l, r, k) + query(right_node, mid + 1, end, l, r, k);
    }

    void solve() {
        cin >> q;
        build(1, 1, n);
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            cout << query(1, 1, n, l, r, k) << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    MergeSortTree Tree;
    Tree.init();
    Tree.solve();
    return 0;
}
