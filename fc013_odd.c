#include <stdio.h>

int main() {
    int n, x;
    scanf("%d\n%d", &n, &x);
    int res = x;
    while (--n) {
        scanf("%d", &x);
        res ^= x;
    }
    printf("%d", res);
    return 0;
}
