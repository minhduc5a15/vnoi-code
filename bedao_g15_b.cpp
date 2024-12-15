#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll power(ll base, ll exponent, ll modulus = MOD) {
    ll res = 1;
    while (exponent) {
        if (exponent & 1) {
            res = (res * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll res = n * (n - 1) % MOD;
    res = (res * (power(2, m) - 1)) % MOD;
    res = (res * (power(2, 2 * m - 2 + m * (n - 2)))) % MOD;
    cout << res << endl;
    return 0;
}
