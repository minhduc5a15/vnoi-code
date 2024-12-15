#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef long long ll;
const int MAXN = 1000001;

bool primes[1000001];
int pre[101];

void Sieve() {
    memset(primes, true, sizeof(primes));
    for (int p = 2; p * p <= MAXN; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= MAXN; i += p) {
                primes[i] = false;
            }
        }
    }
    primes[0] = primes[1] = false;
}

int solve(ll l, ll r) {
    Sieve();
    ll res = 0;
    for (int i = 3; i <= 100; ++i) {
        pre[i] = primes[i];
        pre[i] += pre[i - 1];
    }
    for (ll i = 2; i * i <= r; ++i) {
        if (!primes[i]) continue;
        int left_count = 1, right_count = 1;
        ll L = i, R = i;
        while (L < l) L *= i, ++left_count;
        while (R < r) R *= i, ++right_count;
        res += pre[right_count] - pre[left_count];
    }
    return res;
}

int main() {
    FILE* inp = fopen("BAI4.INP", "r");
    FILE* out = fopen("BAI4.OUT", "w");
    ll l, r;
    fscanf(inp, "%lld %lld", &l, &r);
    fprintf(out, "%d", solve(l, r));
    fclose(inp);
    fclose(out);
    return 0;
}
