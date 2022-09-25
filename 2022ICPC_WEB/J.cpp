#include <algorithm>
#include <cstdio>
#include <iostream>

int n, a[100010];
int b1, b2, len1 = 1, len2 = 1;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    b1 = a[1], b2 = a[n];
    for (int i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1])
            ++len1;
        else
            break;
    }
    for (int i = n - 1; i >= 1; --i) {
        if (a[i] > a[i + 1])
            ++len2;
        else
            break;
    }
    if (b1 < b2) std::swap(b1, b2), std::swap(len1, len2);
    if (b1 == b2) {
        if (len1 % 2 == 1 || len2 % 2 == 1)
            puts("Alice");
        else
            puts("Bob");
    } else {
        if (len1 % 2 == 1)
            puts("Alice");
        else {
            if (len2 % 2 == 1)
                puts("Alice");
            else
                puts("Bob");
        }
    }
    return 0;
}