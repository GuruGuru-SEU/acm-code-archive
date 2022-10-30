#include <iostream>

int n, m;
double ans[233][233];

int main() {
    scanf("%d%d", &n, &m);
    if (m == 2) {
        ans[1][2] = 1;
        ans[2][2] = 1;
        for (int i = 3; i <= n; ++i)
            ans[i][1] = 1;
    } else {
        // if (n >= m) {
        //     for (int i = 1; i <= m; ++i)
        //         ans[i][m - i + 1] = 1;
        //     for (int i = m + 1; i <= n; ++i)
        //         ans[i][1] = 1;
        // } else {
        //     for (int i = 1, j = m; i <= n; i += 2, j -= 1)
        //         ans[i][j] = ans[i + 1][j] = 1;
        // }
        for (int i = 1, j = m; i <= n; i += 2, j -= 1)
            ans[i][std::max(1, j)] = ans[i + 1][std::max(1, j)] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%.12lf ", ans[i][j]);
        printf("\n");
    }
    return 0;
}