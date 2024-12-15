#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const int MOD = 1000000007;

struct Lazy {
    vll lazyAdd, lazyMul, lazySet;
    vector<bool> isAdd, isMul, isSet;

    void init(int n) {
        lazyAdd.resize(n << 2 | 1, 0);
        lazyMul.resize(n << 2 | 1, 1);
        lazySet.resize(n << 2 | 1, 0);
        isAdd.resize(n << 2 | 1);
        isMul.resize(n << 2 | 1);
        isSet.resize(n << 2 | 1);
    }
};

class ST {
private:
    vll arr;
    vll seg;
    Lazy lazy;
    int n, q;

    void build(int id, int start, int end) {
        if (start == end) {
            seg[id] = arr[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(id << 1, start, mid);
        build(id << 1 | 1, mid + 1, end);
        seg[id] = (seg[id << 1] + seg[id << 1 | 1]) % MOD;
    }

    void apply(int id, int start, int end) {
        if (lazy.isSet[id]) {
            seg[id] = (lazy.lazySet[id] * (end - start + 1)) % MOD;
            if (start != end) {
                lazy.isSet[id << 1] = lazy.isSet[id << 1 | 1] = true;
                lazy.lazySet[id << 1] = lazy.lazySet[id << 1 | 1] = lazy.lazySet[id];
                lazy.isAdd[id << 1] = lazy.isAdd[id << 1 | 1] = false;
                lazy.isMul[id << 1] = lazy.isMul[id << 1 | 1] = false;
                lazy.lazyAdd[id << 1] = lazy.lazyAdd[id << 1 | 1] = 0;
                lazy.lazyMul[id << 1] = lazy.lazyMul[id << 1 | 1] = 1;
            }
            lazy.isSet[id] = false;
        }
        if (lazy.isMul[id]) {
            seg[id] = (seg[id] * lazy.lazyMul[id]) % MOD;
            if (start != end) {
                lazy.isMul[id << 1] = lazy.isMul[id << 1 | 1] = true;
                lazy.lazyMul[id << 1] = (lazy.lazyMul[id << 1] * lazy.lazyMul[id]) % MOD;
                lazy.lazyMul[id << 1 | 1] = (lazy.lazyMul[id << 1 | 1] * lazy.lazyMul[id]) % MOD;
                lazy.lazyAdd[id << 1] = (lazy.lazyAdd[id << 1] * lazy.lazyMul[id]) % MOD;
                lazy.lazyAdd[id << 1 | 1] = (lazy.lazyAdd[id << 1 | 1] * lazy.lazyMul[id]) % MOD;
            }
            lazy.isMul[id] = false;
            lazy.lazyMul[id] = 1;
        }
        if (lazy.isAdd[id]) {
            seg[id] = (seg[id] + (lazy.lazyAdd[id] * (end - start + 1)) % MOD) % MOD;
            if (start != end) {
                lazy.isAdd[id << 1] = lazy.isAdd[id << 1 | 1] = true;
                lazy.lazyAdd[id << 1] = (lazy.lazyAdd[id << 1] + lazy.lazyAdd[id]) % MOD;
                lazy.lazyAdd[id << 1 | 1] = (lazy.lazyAdd[id << 1 | 1] + lazy.lazyAdd[id]) % MOD;
            }
            lazy.isAdd[id] = false;
            lazy.lazyAdd[id] = 0;
        }
    }

    void updateRange(int id, int start, int end, int l, int r, int type, ll val) {
        apply(id, start, end);
        if (start > r or end < l) return;
        if (l <= start and end <= r) {
            if (type == 1) {
                lazy.isAdd[id] = true;
                lazy.lazyAdd[id] += val;
                lazy.lazyAdd[id] %= MOD;
            }
            else if (type == 2) {
                lazy.isMul[id] = true;
                lazy.lazyMul[id] *= val;
                lazy.lazyMul[id] %= MOD;
            }
            else if (type == 3) {
                lazy.isSet[id] = true;
                lazy.lazySet[id] = val % MOD;
            }
            apply(id, start, end);
            return;
        }
        int mid = (start + end) >> 1;
        updateRange(id << 1, start, mid, l, r, type, val);
        updateRange(id << 1 | 1, mid + 1, end, l, r, type, val);
        seg[id] = (seg[id << 1] + seg[id << 1 | 1]) % MOD;
    }

    ll get(int id, int start, int end, int l, int r) {
        apply(id, start, end);
        if (start > r or end < l) return 0;
        if (l <= start and end <= r) return seg[id] % MOD;
        int mid = (start + end) >> 1;
        return (get(id << 1, start, mid, l, r) + get(id << 1 | 1, mid + 1, end, l, r)) % MOD;
    }

public:
    void init() {
        cin >> n >> q;
        arr.resize(n + 1);
        seg.resize(n << 2 | 1);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        lazy.init(n);
    }

    void build() {
        build(1, 1, n);
    }

    void updateRange(int l, int r, int type, ll val) {
        updateRange(1, 1, n, l, r, type, val);
    }

    ll query(int l, int r) {
        return get(1, 1, n, l, r);
    }

    void solve() {
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r, val;
                cin >> l >> r >> val;
                updateRange(l, r, 1, val);
            }
            else if (type == 2) {
                int l, r, val;
                cin >> l >> r >> val;
                updateRange(l, r, 2, val);
            }
            else if (type == 3) {
                int l, r, val;
                cin >> l >> r >> val;
                updateRange(l, r, 3, val);
            }
            else if (type == 4) {
                int l, r;
                cin >> l >> r;
                cout << query(l, r) << '\n';
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ST tree;
    tree.init();
    tree.build();
    tree.solve();
    return 0;
}
