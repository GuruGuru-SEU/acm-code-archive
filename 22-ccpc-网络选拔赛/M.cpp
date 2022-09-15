#include <cstdio>
#include <iostream>

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    int ans = (n - 1) % (k - 1) == 0 ? (n - 1) / (k - 1) : (n - 1) / (k - 1) + 1;
    printf("%d", ans);
    return 0;
}