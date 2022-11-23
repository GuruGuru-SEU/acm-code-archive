#include <cstring>
#include <iostream>

char s[10005];

int n;
int a[6];

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'U') {
            cnt = 0;
        } else if (s[i] == 'S') {
            a[1] = cnt;
            cnt = 0;
        } else if (s[i] == 'T') {
            a[2] = cnt;
            cnt = 0;
        } else if (s[i] == 'C') {
            a[3] = cnt;
            cnt = 0;
        } else {
            cnt++;
        }
    }
    printf("%d\n", a[1] + a[3] + 2 * a[2]);

    return 0;
}