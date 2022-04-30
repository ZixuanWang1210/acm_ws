#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int p[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int a, b;
    while (scanf("%d%d", &a, &b)) {
        if (a == -1 && b == -1) break;
        for (int i = 1; i < N; i++) p[i] = i;
        bool f = false;
        p[a] = b;
        while (scanf("%d%d", &a, &b)) {
            if (a == 0 && b == 0) break;
            if (f) continue;
            int x = find(a), y = find(b);
            if (x == y) f = true;
            p[x] = y;
        }
        if (f)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}
