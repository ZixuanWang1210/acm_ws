#include <bits/stdc++.h>
using namespace std;

void insert(int (&a)[1000], int len, int x) {
    int b[1000] = {0}, idx = 1;

    for (int i = 1; i <= len; i++) {
        if (x <= a[i]) b[idx++] = x, x = 0x3f3f3f3f;
        b[idx++] = a[i];
    }

    for (int i = 1; i <= len + 1; i++) {
        a[i] = b[i];
    }

    return;
}

void output(int a[], int len) {
    for (int i = 1; i <= len + 1; i++) cout << a[i] << ' ';
    return;
}

int main() {
    int a[1000] = {0};

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int x;
    cin >> x;
    insert(a, n, x);
    output(a, n);

    return 0;
}