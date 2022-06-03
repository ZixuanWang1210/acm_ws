#include <iostream>
using namespace std;
const int Max = 1e6 + 5;

int dp[Max];
int ls[Max];

int main() {
    int n;
    cin >> n;
    dp[100000] = 1;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        int g = 0;
        for (int j = 0; j <= 200000; j++) {
            if (dp[j] >= 1) {
                ls[++g] = (j + a);
                ls[++g] = (j - a);
                ls[++g] = (a - j);
            }
        }
        for (int j = 1; j <= g; j++) {
            dp[ls[j]]++;
        }
    }
    int ans = -1;

    for (int i = 100000; i <= 200000; i++)
        if (dp[i]) ans++;
    cout << ans;
}
