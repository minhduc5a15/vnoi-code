#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long res = 0, x;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        if ((i & (n - i - 1)) == 0) {
            res ^= x;
        }
    }
    printf("%lld\n", res);
    return 0;
}
