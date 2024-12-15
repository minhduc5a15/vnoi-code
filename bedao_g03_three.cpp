#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1000001;

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
    int t;
    cin >> t;
    Sieve();
    while (t--) {
        ll n;
        cin >> n;
        ll k = __builtin_sqrt(n);
        if (k * k == n && primes[k]) {
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
    return 0;
}
