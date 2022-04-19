#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000];

void swape(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void bubble_sort() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (arr[i] > arr[j]) swape(arr[i], arr[j]);
        }
    }
}

int main() {
    n = 10;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    bubble_sort();

    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';

    return 0;
}
