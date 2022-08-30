#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int x;
    cin >> x;
    for (int i = 1; i <= n; i++)
        if (x <= arr[i])
            cout << x << ' ' << arr[i] << ' ', x = 0x3f3f3f3f;
        else
            cout << arr[i] << ' ';

    return 0;
}
