#include <iostream>

int n;
double a[100005];

int main() {
    scanf("%d", &n);
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &a[i]);
        sum += a[i];
    }
    double cnt = 1.0 * n + 1.0;
    for (int i = 2; i <= n; ++i) {
        a[i] = sum / cnt;
    }
    a[1] = (sum / cnt) * 2;
    for (int i = 1; i <= n; ++i) {
        printf("%.9lf ", a[i]);
    }

    return 0;
}