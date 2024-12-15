#include <iostream>
#include <vector>
#include <algorithm>
#define getAll(x) x.begin(), x.end()
using namespace std;
const int MAXN = 100005;
typedef vector<int> vi;

vector<vi> min_seg(17, vi(MAXN)), max_seg(17, vi(MAXN)), gcd_seg(17, vi(MAXN));

int getMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(min_seg[k][l], min_seg[k][r - (1 << k) + 1]);
}

int getMax(int l, int r) {
    int k = __lg(r - l + 1);
    return max(max_seg[k][l], max_seg[k][r - (1 << k) + 1]);
}

int getGcd(int l, int r) {
    int k = __lg(r - l + 1);
    return __gcd(gcd_seg[k][l], gcd_seg[k][r - (1 << k) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vi arr(n + 1), next(n + 5), f(n + 5, n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        min_seg[0][i] = max_seg[0][i] = arr[i];
    }
    for (int i = 1; i <= n - 1; ++i) {
        gcd_seg[0][i] = abs(arr[i] - arr[i + 1]);
    }
    for (int i = 1; (1 << i) <= n - 1; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n - 1; ++j) {
            gcd_seg[i][j] = __gcd(gcd_seg[i - 1][j], gcd_seg[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            min_seg[i][j] = min(min_seg[i - 1][j], min_seg[i - 1][j + (1 << (i - 1))]);
            max_seg[i][j] = max(max_seg[i - 1][j], max_seg[i - 1][j + (1 << (i - 1))]);
        }
    }
    vi vec(getAll(arr));
    sort(getAll(vec));
    vec.resize(unique(getAll(vec)) - vec.begin());
    for (int i = n; i >= 1; --i) {
        int u = lower_bound(getAll(vec), arr[i]) - begin(vec);
        f[i] = f[i + 1];
        if (next[u]) f[i] = min(f[i], next[u]);
        next[u] = i;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (f[l] <= r) {
            cout << "NO\n";
            continue;
        }
        int diff = getMax(l, r) - getMin(l, r);
        if (diff == 0) {
            cout << "NO\n";
            continue;
        }
        if (diff % (r - l) == 0 && (diff / (r - l) == getGcd(l, r - 1))) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
