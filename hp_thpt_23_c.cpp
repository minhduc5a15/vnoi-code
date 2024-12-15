#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10000001;
vector<bool> primes;

void Sieve() {
    primes.resize(MAXN, true);
    for (int p = 2; p * p <= MAXN; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= MAXN; i += p) {
                primes[i] = false;
            }
        }
    }
    primes[0] = primes[1] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    Sieve();
    vector<int> arr(n), prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        prefix[i + 1] += prefix[i] + x;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int sum = prefix[r] - prefix[l - 1];
        if (sum > 0 and primes[sum]) {
            cout << 1 << '\n';
        }
        else cout << 0 << '\n';
    }

    return 0;
}
