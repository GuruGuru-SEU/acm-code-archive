#include <iostream>

int a[1000005];
int n, k;

int main() {
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    if (a[n - 1] <= a[n]) {
        puts("Python will never be faster than C++");
    } else {
        for (int i = n + 1; i <= 1000000; ++i) {
            a[i] = std::max(0, 2 * a[i - 1] - a[i - 2]);
            if (a[i] < k) {
                printf("Python 3.%d will be faster than C++", i);
                break;
            }
        }
    }
    return 0;
}