#include <cstring>
#include <iostream>

char s[1005];
int n;

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        if (i != 1 && s[i - 1] == 'L') continue;
        if (s[i] == 'L') continue;
        if (i != n && s[i + 1] == 'L') continue;
        s[i] = 'C';
    }
    printf("%s", s + 1);
    return 0;
}