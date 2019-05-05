#include <bits/stdc++.h>

using namespace std;

char s[200001];
char t[200001];

int main() {
    int h, w, n, x, y, l, r, u, d, i;

    scanf("%d %d %d", &h, &w, &n);
    scanf("%d %d", &x, &y);
    scanf("%s", s);
    scanf("%s", t);

    l = 0, r = w + 1;

    for (i = n - 1; i >= 0; i--) {
        if (t[i] == 'L') {
            if (r <= w) r++;
        } else if (t[i] == 'R') {
            if (l > 0) l--;
        }
        cout << l << " " << r << endl;

        if (s[i] == 'L') {
            l++;
        } else if (s[i] == 'R') {
            r--;
        }
        cout << l << " " << r << endl;

        if (l + 1 >= r) {
            puts("NO");

            return 0;
        }
    }

    if (y <= l || y >= r) {
        puts("NO");

        return 0;
    }

    u = 0, d = h + 1;

    for (i = n - 1; i >= 0; i--) {
        if (t[i] == 'U') {
            if (d <= h) d++;
        } else if (t[i] == 'D') {
            if (u > 0) u--;
        }

        if (s[i] == 'U') {
            u++;
        } else if (s[i] == 'D') {
            d--;
        }

        if (u + 1 >= d) {
            puts("NO");

            return 0;
        }
    }

    if (x <= u || x >= d) {
        puts("NO");

        return 0;
    }

    puts("YES");

    return 0;
}
