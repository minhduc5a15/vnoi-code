#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1000000007;

vector<ll> factorial, inv_factorial;

ll power(ll base, ll exponent, ll modulus = MOD) {
    base %= modulus;
    ll result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

void init_factorial(int n) {
    factorial.resize(n + 1, 1);
    inv_factorial.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        factorial[i] = 1LL * factorial[i - 1] * i % MOD;
    }
    inv_factorial[n] = power(factorial[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 1; --i) {
        inv_factorial[i] = 1LL * inv_factorial[i + 1] * (i + 1) % MOD;
    }
}

int comb(int n, int k) {
    if (k > n) return 0;
    return 1LL * factorial[n] * inv_factorial[k] % MOD * inv_factorial[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, k;
    cin >> m >> n >> k;
    vector<pair<int, int>> s(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i].first >> s[i].second;
    }
    sort(s.begin(), s.end());
    init_factorial(m + n);
    vector<int> dp(k, 0);
    for (int i = 0; i < k; ++i) {
        int x = s[i].first, y = s[i].second;
        dp[i] = comb(x + y - 2, x - 1);
        for (int j = 0; j < i; ++j) {
            if (int px = s[j].first, py = s[j].second; px <= x && py <= y) {
                dp[i] = (dp[i] - 1LL * dp[j] * comb(x - px + y - py, x - px) % MOD + MOD) % MOD;
            }
        }
    }
    ll result = comb(m + n - 2, m - 1);
    for (int i = 0; i < k; ++i) {
        int x = s[i].first, y = s[i].second;
        result = (result - 1LL * dp[i] * comb(m - x + n - y, m - x) % MOD + MOD) % MOD;
    }
    cout << result;
    return 0;
}
