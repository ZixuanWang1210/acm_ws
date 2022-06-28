#include <bits/stdc++.h>
using namespace std;
int c[10];
int main() {
    int n;
    cin >> n;
    int minn = n + 1;
    for (int i = 1; i <= 9; i++) cin >> c[i], minn = min(minn, c[i]);
    // 最多能取的个数
    int ct = n / minn;
    // 贪心保证下个长度能取最小的情况下，尽量拿最大的
    for (int i = ct; i >= 1; i--) {
        for (int j = 9; j >= 1; j--) {
            int money = (n - c[j]);
            int base = (i - 1) * minn;
            if (money >= base) {
                n -= c[j];
                cout << j;
                break;
            }
        }
    }
}
