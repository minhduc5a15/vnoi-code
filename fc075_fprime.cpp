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
    Sieve();
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if (!primes[k]) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
