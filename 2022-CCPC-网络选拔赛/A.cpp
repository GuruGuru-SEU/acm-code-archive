#include <iostream>

using namespace std;

int cards[10][100];
int a[100];
int table_cards[100];
int last_x, last_true;
int m, p = 3, q;

int main() {
    for (int u = 0; u < 4; ++u) {
        for (int i = 1; i <= 13; ++i) {
            int x;
            cin >> x;
            cards[u][x]++;
        }
    }
    cin >> m;
    while (m--) {
        q = (p + 1) % 4;
        char op;
        cin >> op;
        if (op == 'S') {
            int x, y;
            cin >> x >> y;
            last_x = x;
            last_true = 1;
            for (int i = 1; i <= y; ++i) {
                cin >> a[i];
                if (a[i] != last_x) last_true = 0;
                table_cards[a[i]]++;
                cards[q][a[i]]--;
            }
        } else if (op == '!') {
            int y;
            cin >> y;
            last_true = 1;
            for (int i = 1; i <= y; ++i) {
                cin >> a[i];
                if (a[i] != last_x) last_true = 0;
                table_cards[a[i]]++;
                cards[q][a[i]]--;
            }
        } else if (op == '?') {
            int des = last_true ? q : p;
            for (int i = 1; i <= 13; ++i) {
                cards[des][i] += table_cards[i];
                table_cards[i] = 0;
            }
        }
        p = q;
    }
    for (int u = 0; u < 4; ++u) {
        for (int i = 1; i <= 13; ++i) {
            for (int j = 1; j <= cards[u][i]; ++j) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}