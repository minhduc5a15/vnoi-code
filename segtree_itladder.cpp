#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

class SegmentTree {
private:
    int n;
    vector<ll> tree, lazyA, lazyB;
public:

    SegmentTree(int size) {
        this->n = size;
        tree.assign(n << 2 | 1, 0);
        lazyA.assign(n << 2 | 1, 0);
        lazyB.assign(n << 2 | 1, 0);
    }

    void apply(int id, int start, int end, ll A, ll B) {
        ll len = end - start + 1;
        tree[id] = (tree[id] + len * B % MOD + A * (len * (len - 1) / 2) % MOD) % MOD;
        lazyA[id] = (lazyA[id] + A) % MOD;
        lazyB[id] = (lazyB[id] + B) % MOD;
    }

    void push(int id, int start, int end) {
        if (lazyA[id] != 0 || lazyB[id] != 0) {
            int mid = (start + end) >> 1;
            apply(id << 1, start, mid, lazyA[id], lazyB[id]);
            apply(id << 1 | 1, mid + 1, end, lazyA[id], (lazyB[id] + lazyA[id] * (mid + 1 - start) % MOD) % MOD);
            lazyA[id] = 0;
            lazyB[id] = 0;
        }
    }

    void update(int id, int start, int end, int l, int r, ll A, ll B) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply(id, start, end, A, (B + A * (start - l) % MOD) % MOD);
            return;
        }
        push(id, start, end);
        int mid = (start + end) >> 1;
        update(id << 1, start, mid, l, r, A, B);
        update(id << 1 | 1, mid + 1, end, l, r, A, B);
        tree[id] = (tree[id << 1] + tree[id << 1 | 1]) % MOD;
    }

    ll query(int id, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[id];
        push(id, start, end);
        int mid = (start + end) >> 1;
        ll q1 = query(id << 1, start, mid, l, r);
        ll q2 = query(id << 1 | 1, mid + 1, end, l, r);
        return (q1 + q2) % MOD;
    }

    void update(int l, int r, ll A, ll B) {
        update(1, 1, n, l, r, A, B);
    }

    ll query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    SegmentTree segTree(n);
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int L, R;
            ll A, B;
            cin >> L >> R >> A >> B;
            segTree.update(L, R, A, B);
        }
        else if (type == 2) {
            int L, R;
            cin >> L >> R;
            cout << segTree.query(L, R) << '\n';
        }
    }
    return 0;
}
