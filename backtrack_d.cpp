#include <iostream>
using namespace std;
long long a[100], res = 0, M = (1ll << 26ll) - 1;
int n;

void backtrack(int k, long long T) {
    if (k == n) {
        res += (T == M);
        return;
    }
    else if (T == M) {
        res += (1ll << (1ll * (n - k)));
        return;
    }
    backtrack(k + 1, T);
    backtrack(k + 1, T | a[k + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int F[30] = {};
        string s;
        cin >> s;
        for (char c: s) F[c - 'a'] = 1;
        long long t = 0;
        for (int j = 0; j < 26; ++j) t = t * 2 + F[j];
        a[i] = t;
    }
    backtrack(0, 0);
    cout << res;
}
