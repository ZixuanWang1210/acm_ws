#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> arr[n + 1];
    sort(arr + 1, arr + n + 2);
    for (int i = 1; i <= n + 1; i++) cout << arr[i] << ' ';

    return 0;
}
