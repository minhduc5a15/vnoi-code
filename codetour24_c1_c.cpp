#include <iostream>
#include <vector>
#include <algorithm>
#define getAll(x) x.begin(), x.end()
using namespace std;
const int MAXN = 500005;
typedef vector<int> vi;

vi BIT(MAXN << 1);
int n, q;

void update(int i) {
    if (i <= n + q) return ++BIT[i], update(i + (i & -i));
}

int get(int i) {
    return !i ? 0 : BIT[i] + get(i - (i & -i));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> q;
    vi arr(n), queries(q), u(n + q);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        u[i] = arr[i];
    }
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
        u[n + i] = queries[i];
    }
    sort(u.begin(), u.end());
    for (int x: arr) {
        update(lower_bound(getAll(u), x) - u.begin() + 1);
    }
    for (int x: queries) {
        int i = lower_bound(getAll(u), x) - u.begin() + 1;
        cout << get(i) + 1 << '\n';
        update(i);
    }
    return 0;
}
