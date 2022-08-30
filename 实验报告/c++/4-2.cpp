#include <bits/stdc++.h>
using namespace std;

int get(int n) {
    int ans = 0;
    if (n == 1)
        return 1;
    else
        return n * get(n - 1);
}

int main() {
    int n;
    cin >> n;
    cout << get(n);

    return 0;
}