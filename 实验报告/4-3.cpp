#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int t = b;
    b = a;
    a = t;
    return;
}

void sort(int (&a)[1000], int len) {
    for (int i = 1; i <= len; i++) {
        int idx = i;
        int mn = 0x3f3f3f3f;
        for (int j = i; j <= len; j++) {
            if (mn > a[j]) idx = j, mn = a[j];
        }
        if (idx != i) swap(a[i], a[idx]);
    }

    return;
}

void output(int a[], int len) {
    for (int i = 1; i <= len; i++) cout << a[i] << ' ';
    return;
}

void input(int (&a)[1000], int len) {
    for (int i = 1; i <= len; i++) cin >> a[i];
}

int main() {
    int a[1000] = {0};

    int n;
    cin >> n;
    input(a, n);

    sort(a, n);
    output(a, n);

    return 0;
}