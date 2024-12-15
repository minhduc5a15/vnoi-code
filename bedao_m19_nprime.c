#include <stdio.h>
#include <math.h>
typedef long long ll;

void solve(ll n) {
    for (ll i = 2; i <= 1000005; ++i) {
        if (n % i == 0) {
            if (n % (i * i) == 0) {
                printf("%lld %lld\n", i, n / i / i);
                return;
            }
            ll a = sqrt(n / i);
            ll b = i;
            printf("%lld %lld\n", a, b);
            return;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        solve(n);
    }
    return 0;
}
