#include <iostream>
using namespace std;

void sol(int x) {
    int mx = 0, cnt = 0;
    while (x) {
        int t = x % 10;
        if (t == 0) cnt++;
        mx = max(mx, t);
        x /= 10;
    }
    cout << "0的个数为：" << cnt << endl;
    cout << "各数字中的最大者：" << mx << endl;
}

int main() {
    int x;
    cin >> x;
    sol(x);
    
    return 0;
}