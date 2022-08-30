#include <bits/stdc++.h>
using namespace std;

int a[10];

void input() {
    for (int i = 0; i < 4; i++) cin >> a[i];
}

void q_sort(int l, int r) {
    if (l >= r) return;

    int i = l - 1, j = r + 1, mid = a[l + r >> 1];
    while (i < j) {
        do i++;
        while (a[i] < mid);
        do j--;
        while (a[j] > mid);
        if (i < j) swap(a[i], a[j]);
    }
    q_sort(l, j), q_sort(j + 1, r);
    return;
}

void sol1() {
    q_sort(0, 3);
    for (int i = 0; i < 4; i++) cout << a[i] << ' ';
    cout << endl;
}

void sol2() {
    sort(a, a + 3);
    for (int i = 0; i < 4; i++) cout << a[i] << ' ';
    cout << endl;

    sort(a, a + 4, [](int x, int y) { return x > y; });
    for (int i = 0; i < 4; i++) cout << a[i] << ' ';
    cout << endl;
}

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void sol3() {
    const int INF = 0x3f3f3f3f;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (a[i] > a[j]) swap(a[i], a[j]);
        }
        cout << a[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (a[i] < a[j]) swap(a[i], a[j]);
        }
        cout << a[i] << ' ';
    }
}

int main() {
    input();
    sol1();
    sol2();
    sol3();

    return 0;
}
